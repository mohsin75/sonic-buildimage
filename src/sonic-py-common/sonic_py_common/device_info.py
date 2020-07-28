import os
import subprocess

import yaml

# TODD: Replace with swsscommon
from swsssdk import ConfigDBConnector, SonicDBConfig

USR_SHARE_SONIC_PATH = "/usr/share/sonic"
HOST_DEVICE_PATH = USR_SHARE_SONIC_PATH + "/device"
CONTAINER_PLATFORM_PATH = USR_SHARE_SONIC_PATH + "/platform"

MACHINE_CONF_PATH = "/host/machine.conf"
SONIC_VERSION_YAML_PATH = "/etc/sonic/sonic_version.yml"

# Port configuration file names
PORT_CONFIG_FILE = "port_config.ini"
PLATFORM_JSON_FILE = "platform.json"



def get_machine_info():
    """
    Retreives data from the machine configuration file

    Returns:
        A dictionary containing the key/value pairs as found in the machine
        configuration file
    """
    if not os.path.isfile(MACHINE_CONF_PATH):
        return None

    machine_vars = {}
    with open(MACHINE_CONF_PATH) as machine_conf_file:
        for line in machine_conf_file:
            tokens = line.split('=')
            if len(tokens) < 2:
                continue
            machine_vars[tokens[0]] = tokens[1].strip()

    return machine_vars


def get_platform():
    """
    Retrieve the device's platform identifier

    Returns:
        A string containing the device's platform identifier
    """
    # First, attempt to retrieve the platform string from Config DB
    config_db = ConfigDBConnector()
    config_db.connect()

    metadata = config_db.get_table('DEVICE_METADATA')

    if 'localhost' in metadata and 'platform' in metadata['localhost']:
        return metadata['localhost']['platform']

    # If we were unable to retrieve the platform string from Config DB, attempt
    # to retrieve it from the machine configuration file
    machine_info = get_machine_info()
    if machine_info:
        if machine_info.has_key('onie_platform'):
            return  machine_info['onie_platform']
        elif machine_info.has_key('aboot_platform'):
            return machine_info['aboot_platform']

    return None


def get_hwsku():
    """
    Retrieve the device's hardware SKU identifier

    Returns:
        A string containing the device's hardware SKU identifier
    """
    config_db = ConfigDBConnector()
    config_db.connect()

    metadata = config_db.get_table('DEVICE_METADATA')

    if 'localhost' in metadata and 'hwsku' in metadata['localhost']:
        return metadata['localhost']['hwsku']

    return ""


def get_platform_and_hwsku():
    """
    Convenience function which retrieves both the device's platform identifier
    and hardware SKU identifier

    Returns:
        A tuple of two strings, the first containing the device's
        platform identifier, the second containing the device's
        hardware SKU identifier
    """
    platform = get_platform()
    hwsku = get_hwsku()

    return (platform, hwsku)

def get_paths_to_platform_and_hwsku_dirs():
    """
    Retreives the paths to the device's platform and hardware SKU data
    directories

    Returns:
        A tuple of two strings, the first containing the path to the platform
        directory of the device, the second containing the path to the hardware
        SKU directory of the device
    """
    # Get platform and hwsku
    (platform, hwsku) = get_platform_and_hwsku()

    # Determine whether we're running in a container or on the host
    platform_path_host = os.path.join(HOST_DEVICE_PATH, platform)

    if os.path.isdir(CONTAINER_PLATFORM_PATH):
        platform_path = CONTAINER_PLATFORM_PATH
    elif os.path.isdir(platform_path_host):
        platform_path = platform_path_host
    else:
        raise OSError("Failed to locate platform directory")

    hwsku_path = os.path.join(platform_path, hwsku)

    return (platform_path, hwsku_path)


def get_path_to_port_config_file():
    """
    Retrieves the path to the device's port configuration file

    Returns:
        A string containing the path the the device's port configuration file
    """
    # Get platform and hwsku path
    (platform_path, hwsku_path) = get_paths_to_platform_and_hwsku_dirs()

    # First check for the presence of the new 'platform.json' file
    port_config_file_path = os.path.join(platform_path, PLATFORM_JSON_FILE)
    if not os.path.isfile(port_config_file_path):
        # platform.json doesn't exist. Try loading the legacy 'port_config.ini' file
        port_config_file_path = os.path.join(hwsku_path, PORT_CONFIG_FILE)
        if not os.path.isfile(port_config_file_path):
            raise OSError("Failed to detect port config file: {}".format(port_config_file_path))

    return port_config_file_path


def get_sonic_version_info():
    if not os.path.isfile(SONIC_VERSION_YAML_PATH):
        return None

    data = {}
    with open(SONIC_VERSION_YAML_PATH) as stream:
        if yaml.__version__ >= "5.1":
            data = yaml.full_load(stream)
        else:
            data = yaml.load(stream)

    return data


#
# Multi-ASIC functionality
#

def _valid_mac_address(mac):
    return bool(re.match("^([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})$", mac))


def get_system_mac(namespace=None):
    version_info = get_sonic_version_info()

    if (version_info['asic_type'] == 'mellanox'):
        # With Mellanox ONIE release(2019.05-5.2.0012) and above
        # "onie_base_mac" was added to /host/machine.conf:
        # onie_base_mac=e4:1d:2d:44:5e:80
        # So we have another way to get the mac address besides decode syseeprom
        # By this can mitigate the dependency on the hw-management service
        base_mac_key = "onie_base_mac"
        machine_vars = get_machine_info()
        if machine_vars is not None and base_mac_key in machine_vars:
            mac = machine_vars[base_mac_key]
            mac = mac.strip()
            if _valid_mac_address(mac):
                return mac

        hw_mac_entry_cmds = [ "sudo decode-syseeprom -m" ]
    elif (version_info['asic_type'] == 'marvell'):
        # Try valid mac in eeprom, else fetch it from eth0
        platform = get_platform()
        hwsku = get_hwsku()
        profile_cmd = 'cat' + HOST_DEVICE_PATH + '/' + platform +'/'+ hwsku +'/profile.ini | grep switchMacAddress | cut -f2 -d='
        hw_mac_entry_cmds = [ profile_cmd, "sudo decode-syseeprom -m", "ip link show eth0 | grep ether | awk '{print $2}'" ]
    else:
        mac_address_cmd = "cat /sys/class/net/eth0/address"
        if namespace is not None:
            mac_address_cmd = "sudo ip netns exec {} {}".format(namespace, mac_address_cmd)

        hw_mac_entry_cmds = [mac_address_cmd]

    for get_mac_cmd in hw_mac_entry_cmds:
        proc = subprocess.Popen(get_mac_cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        (mac, err) = proc.communicate()
        if err:
            continue
        mac = mac.strip()
        if _valid_mac_address(mac):
            break

    if not _valid_mac_address(mac):
        return None

    # Align last byte of MAC if necessary
    if version_info and version_info['asic_type'] == 'centec':
        last_byte = mac[-2:]
        aligned_last_byte = format(int(int(last_byte, 16) + 1), '02x')
        mac = mac[:-2] + aligned_last_byte
    return mac


def get_system_routing_stack():
    """
    Retrieves the routing stack being utilized on this device

    Returns:
        A string containing the name of the routing stack in use on the device
    """
    command = "sudo docker ps | grep bgp | awk '{print$2}' | cut -d'-' -f3 | cut -d':' -f1"

    try:
        proc = subprocess.Popen(command,
                                stdout=subprocess.PIPE,
                                shell=True,
                                stderr=subprocess.STDOUT)
        stdout = proc.communicate()[0]
        proc.wait()
        result = stdout.rstrip('\n')
    except OSError as e:
        raise OSError("Cannot detect routing stack")

    return result

