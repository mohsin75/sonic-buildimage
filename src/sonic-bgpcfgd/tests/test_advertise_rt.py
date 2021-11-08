from unittest.mock import MagicMock, patch

from bgpcfgd.directory import Directory
from bgpcfgd.template import TemplateFabric
from bgpcfgd.managers_advertise_rt import AdvertiseRouteMgr
from swsscommon import swsscommon

def constructor(skip_bgp_asn=False):
    cfg_mgr = MagicMock()

    common_objs = {
        'directory': Directory(),
        'cfg_mgr':   cfg_mgr,
        'tf':        TemplateFabric(),
        'constants': {},
    }

    mgr = AdvertiseRouteMgr(common_objs, "STATE_DB", "ADVERTISE_NETWORK")
    if not skip_bgp_asn:
        mgr.directory.put("CONFIG_DB", swsscommon.CFG_DEVICE_METADATA_TABLE_NAME, "localhost", {"bgp_asn": "65100"})
    assert len(mgr.advertised_routes) == 0

    return mgr

def set_del_test(mgr, op, args, expected_ret, expected_cmds):
    set_del_test.push_list_called = False
    def push_list(cmds):
        set_del_test.push_list_called = True
        assert cmds in expected_cmds
        return True
    mgr.cfg_mgr.push_list = push_list

    if op == "SET":
        ret = mgr.set_handler(*args)
        assert ret == expected_ret
    elif op == "DEL":
        mgr.del_handler(*args)
    else:
        assert False, "Wrong operation"

    if expected_cmds:
        assert set_del_test.push_list_called, "cfg_mgr.push_list wasn't called"
    else:
        assert not set_del_test.push_list_called, "cfg_mgr.push_list was called"

def test_set_del():
    mgr = constructor()
    set_del_test(
        mgr,
        "SET",
        ("10.1.0.0/24", {}),
        True,
        [
            ["router bgp 65100",
             " no bgp network import-check"],
            ["router bgp 65100",
             " address-family ipv4 unicast",
             "  network 10.1.0.0/24"]
        ]
    )

    set_del_test(
        mgr,
        "SET",
        ("fc00:10::/64", {}),
        True,
        [
            ["router bgp 65100",
             " address-family ipv6 unicast",
             "  network fc00:10::/64"]
        ]
    )

    set_del_test(
        mgr,
        "DEL",
        ("10.1.0.0/24",),
        True,
        [
            ["router bgp 65100",
             " address-family ipv4 unicast",
             "  no network 10.1.0.0/24"]
        ]
    )

    set_del_test(
        mgr,
        "DEL",
        ("fc00:10::/64",),
        True,
        [
            ["router bgp 65100",
             " bgp network import-check"],
            ["router bgp 65100",
             " address-family ipv6 unicast",
             "  no network fc00:10::/64"]
        ]
    )


def test_set_del_vrf():
    mgr = constructor()
    set_del_test(
        mgr,
        "SET",
        ("vrfRED|10.2.0.0/24", {}),
        True,
        [
            ["router bgp 65100 vrf vrfRED",
             " no bgp network import-check"],
            ["router bgp 65100 vrf vrfRED",
             " address-family ipv4 unicast",
             "  network 10.2.0.0/24"]
        ]
    )

    set_del_test(
        mgr,
        "SET",
        ("vrfRED|fc00:20::/64", {}),
        True,
        [
            ["router bgp 65100 vrf vrfRED",
             " address-family ipv6 unicast",
             "  network fc00:20::/64"]
        ]
    )

    set_del_test(
        mgr,
        "DEL",
        ("vrfRED|10.2.0.0/24",),
        True,
        [
            ["router bgp 65100 vrf vrfRED",
             " address-family ipv4 unicast",
             "  no network 10.2.0.0/24"]
        ]
    )

    set_del_test(
        mgr,
        "DEL",
        ("vrfRED|fc00:20::/64",),
        True,
        [
            ["router bgp 65100 vrf vrfRED",
             " bgp network import-check"],
            ["router bgp 65100 vrf vrfRED",
             " address-family ipv6 unicast",
             "  no network fc00:20::/64"]
        ]
    )
