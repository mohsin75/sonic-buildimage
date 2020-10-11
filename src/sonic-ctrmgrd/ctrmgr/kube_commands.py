#!/usr/bin/python3 -u
# -*- coding: utf-8 -*-

import os
import sys
import ssl
import subprocess
import syslog
import inspect
import shutil
import fcntl
import tempfile
import argparse
import urllib.request
from urllib.parse import urlparse
import yaml
import json
from sonic_py_common import device_info

KUBE_ADMIN_CONF = "/etc/sonic/kube_admin.conf"
# kubectl --kubeconfig <KUBE_ADMIN_CONF> label nodes
#       <device_info.get_hostname()> <label to be added>

def log_debug(m):
    msg = "{}: {}".format(inspect.stack()[1][3], m)
    print(msg)
    syslog.syslog(syslog.LOG_DEBUG, msg)


def log_error(m):
    print(m)
    syslog.syslog(syslog.LOG_ERR, m)


def to_str(s):
    if isinstance(s, str):
        return s

    if isinstance(s, bytes):
        return s.decode('utf-8')

    return str(s)


def systemd_service_action(action, feat):
    log_debug("{} service {}".format(action, feat))
    status = os.system("systemctl {} {}".format(action, feat))
    if status != 0:
        syslog.syslog(syslog.LOG_ERR,
                "Failed to {} {}".format(action, feat))
    else:
        syslog.syslog(syslog.LOG_INFO,
                "{} {} is done".format(action, feat))


def _run_command(cmd, timeout=5):
    """ Run shell command and return exit code, along with stdout. """
    try:
        proc = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE,
                stderr=subprocess.PIPE)
        (o, e) = proc.communicate(timeout)
        output = to_str(o)
        err = to_str(e)
        ret = proc.returncode
    except subprocess.TimeoutExpired as error:
        proc.kill()
        output = ""
        err = str(error)
        ret = -1

    log_debug("cmd:{}\nret={}".format(cmd, ret))
    if output:
        log_debug("out:{}".format(output))
    if err:
        log_debug("err:{}".format(err))

    return (ret, output.strip(), err.strip())


def kube_read_labels():
    """ Read current labels on node and return as dict. """
    KUBECTL_GET_CMD = "kubectl --kubeconfig {} get nodes --show-labels |\
 grep {} | tr -s ' ' | cut -f6 -d' '"

    labels = {}
    ret, out, _ = _run_command(KUBECTL_GET_CMD.format(
        KUBE_ADMIN_CONF, device_info.get_hostname()))

    if ret == 0:
        lst = out.split(",")

        for label in lst:
            tmp = label.split("=")
            labels[tmp[0]] = tmp[1]

    # log_debug("{} kube labels {} ret={}".format(
        # "Applied" if ret == 0 else "Failed to apply",
        # json.dumps(labels, indent=4), ret))

    return (ret, labels)

 
def kube_write_labels(set_labels, unset_labels):
    """ Set given set_labels.
        Ensure labels in unset_labels are not there.
    """
    KUBECTL_SET_CMD = "kubectl --kubeconfig {} label --overwrite nodes {} {}"

    ret, node_labels = kube_read_labels()
    if ret != 0:
        log_debug("Read before set failed. Hence skipping set {}".format(str(labels)))
        return ret

    label_str = ""
    for (name, val) in set_labels.items():
        if name in node_labels:
            # Can't update; but can be removed
            if val != node_labels[name]:
                # A label always get same value. Check it out.
                # If it is required to modify, need to remove it first
                log_error(
                        "label already exists({}={}); can't set different value {}".
                        format(name, node_labels[name], val))
                return -1
        else:
            # Add label
            label_str += "{}={} ".format(name, val)

    for name in unset_labels:
        # Remove labels that are not provided
        if name in node_labels:
            # Remove label
            label_str += "{}- ".format(name)

    if label_str:
        (ret, _, _) = _run_command(KUBECTL_SET_CMD.format(
            KUBE_ADMIN_CONF, device_info.get_hostname(), label_str.strip()))

        log_debug("{} kube labels {} ret={}".format(
            "Applied" if ret == 0 else "Failed to apply", label_str, ret))
    else:
        log_debug("Given labels are in sync with node labels. Hence no-op")
    return ret

 
def func_get_labels(args):
    """ args parser default function for get labels"""
    ret, node_labels = kube_read_labels()
    if ret != 0:
        log_debug("Labels read failed.")
        return ret

    print(json.dumps(node_labels, indent=4))
    return 0
    

def is_connected(server=""):
    """ Check if we are currently connected """
    KUBELET_YAML = "/var/lib/kubelet/config.yaml"

    if (os.path.exists(KUBELET_YAML) and os.path.exists(KUBE_ADMIN_CONF)):
        with open(KUBE_ADMIN_CONF, 'r') as s:
            d = yaml.load(s, yaml.SafeLoader)
            d = d['clusters'] if 'clusters' in d else []
            d = d[0] if len(d) > 0 else {}
            d = d['cluster'] if 'cluster' in d else {}
            d = d['server'] if 'server' in d else ""
            if d:
                o = urlparse(d)
                if o.hostname:
                    return not server or server == o.hostname
    return False


def func_is_connected(args):
    """ Get connected state """
    connected = is_connected()
    print("Currently {} to Kube master".format(
        "connected" if connected else "not connected"))
    return 0


def _take_lock():
    """ Take a lock to block concurrent calls """
    LOCK_FILE = "/var/lock/kube_join.lock"
    lock_fd = None
    try:
        lock_fd = open(LOCK_FILE, "w")
        fcntl.lockf(lock_fd, fcntl.LOCK_EX | fcntl.LOCK_NB)
        log_debug("Lock taken {}".format(LOCK_FILE))
    except IOError as e:
        lock_fd = None
        log_error("Lock {} failed: {}".format(LOCK_FILE, str(e)))
    return lock_fd


def _download_file(server, port, insecure):
    """ Download file from Kube master to assist join as node. """
    SERVER_ADMIN_URL = "https://{}/admin.conf"

    if insecure:
        r = urllib.request.urlopen(SERVER_ADMIN_URL.format(server),
                context=ssl._create_unverified_context())
    else:
        r = urllib.request.urlopen(SERVER_ADMIN_URL.format(server))

    (h, fname) = tempfile.mkstemp(suffix="_kube_join")
    data = r.read()
    os.write(h, data)
    os.close(h)

    # Ensure the admin.conf has given VIP as server-IP.
    update_file = "{}.upd".format(fname)
    cmd = 'sed "s/server:.*:{}/server: https:\/\/{}:{}/" {} > {}'.format(
            str(port), server, str(port), fname, update_file)
    (ret, _, err) = _run_command(cmd)

    if ret != 0:
        log_err("sed update of downloaded file failed with ret={}\n{}".
                format(ret, err))
        return ret

    shutil.copyfile(update_file, KUBE_ADMIN_CONF)

    _run_command("rm -f {} {}".format(fname, update_file))
    log_debug("{} downloaded".format(KUBE_ADMIN_CONF))


def _troubleshoot_tips():
    """ log troubleshoot tips which could be handy,
        when in trouble with join
    """
    msg = """
if join fails, check the following

a.  Ensure both master & node run same or compatible k8s versions

b.  Check if this node already exists in master
    Use 'sudo kubectl --kubeconfig=/etc/kubernetes/admin.conf get nodes' to list nodes at master.

    If yes, delete it, as the node is attempting a new join.
    'kubectl --kubeconfig=/etc/kubernetes/admin.conf drain <node name> --ignore-daemonsets'
    'kubectl --kubeconfig=/etc/kubernetes/admin.conf delete node <node name>'

c.  In Master check if all system pods are running good.
    'kubectl get pods --namespace kube-system'

    If any not running properly, say READY column has 0/1, decribe pod for more detail.
    'kubectl --namespace kube-system describe pod <pod name>'

    For additional details, look into pod's logs.
    @ node: /var/log/pods/<podname>/...
    @ master: 'kubectl logs -n kube-system <pod name>'
    """

    (h, fname) = tempfile.mkstemp(suffix="kube_hints_")
    os.write(h, str.encode(msg))
    os.close(h)

    log_error("Refer file {} for troubleshooting tips".format(fname))


def _do_reset(pending_join = False):
    # Drain & delete self from cluster. If not, the next join would fail
    #
    if os.path.exists(KUBE_ADMIN_CONF):
        _run_command(
                "kubectl --kubeconfig {} --request-timeout 20s drain {} --ignore-daemonsets".
                format(KUBE_ADMIN_CONF, device_info.get_hostname()))

        _run_command("kubectl --kubeconfig {} --request-timeout 20s delete node {}".
                format(KUBE_ADMIN_CONF, device_info.get_hostname()))

    _run_command("kubeadm reset -f", 10)
    _run_command("rm -rf /etc/cni/net.d")
    if not pending_join:
        _run_command("rm -f {}".format(KUBE_ADMIN_CONF))
    _run_command("systemctl stop kubelet")


def _do_join(server, port, insecure):
    KUBEADM_JOIN_CMD = "kubeadm join --discovery-file {} --node-name {}"

    try:
        _download_file(server, port, insecure)

        _do_reset(True)

        _run_command("modprobe br_netfilter")

        _run_command("systemctl start kubelet")

        (ret, out, err) = _run_command(KUBEADM_JOIN_CMD.format(
            KUBE_ADMIN_CONF, device_info.get_hostname()), timeout=60)

    except IOError as e:
        err = "Download failed: {}".format(str(e))

    _troubleshoot_tips()

    if (ret != 0):
        log_error(err)

    return (ret, out, err)


def kube_join_master(server, port, insecure, force=False):
    """ The main function that initiates join to master """

    out = ""
    err = ""
    ret = 0

    log_debug("join: server:{} port:{} insecure:{} force:{}".
            format(server, port, insecure, force))

    lock_fd = _take_lock()
    if not lock_fd:
        log_error("Lock {} is active; Bail out".format(LOCK_FILE))
        return

    systemd_service_action("start", "kubelet")
    if not force:
        if is_connected(server):
            err = "Master {} is already connected. "
            err += "Reset or join with force".format(server)
            ret = -1

    if ret == 0:
        (ret, out, err) = _do_join(server, port, insecure)

    log_debug("join: ret={} out:{} err:{}".format(ret, out, err))
    return (ret, out, err)
    

def kube_reset_master(force):
    err = ""
    ret = 0

    lock_fd = _take_lock()
    if not lock_fd:
        log_error("Lock {} is active; Bail out".format(LOCK_FILE))
        return

    systemd_service_action("stop", "kubelet")
    if not force:
        if not is_connected():
            err = "Currently not connected to master. "
            err += "Use force reset if needed"
            log_debug("Not connected ... bailing out")
            ret = -1

    if ret == 0:
        _do_reset()

    return (ret, err)



def main():
    syslog.openlog("kube_commands")
    parser=argparse.ArgumentParser(description=
            "get-labels")
    subparsers = parser.add_subparsers(title='actions')

    parser_get_labels = subparsers.add_parser("get-labels",
            help="Get current labels on node")
    parser_get_labels.set_defaults(func=func_get_labels)

    parser_is_connected = subparsers.add_parser("connected",
            help="Get connnected status")
    parser_is_connected.set_defaults(func=func_is_connected)

    if len(sys.argv) < 2:
        parser.print_help()
        exit(-1)

    args = parser.parse_args()
    args.func(args)

    syslog.closelog()

if __name__ == "__main__":
    if os.geteuid() != 0:
        exit("Please run as root. Exiting ...")
    main()
    sys.exit(0)

