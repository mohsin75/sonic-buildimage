import re

from swsscommon import swsscommon

from .log import log_err, log_info
from .manager import Manager


class BBRMgr(Manager):
    """ This class initialize "BBR" feature for  """
    def __init__(self, common_objs, db, table):
        """
        Initialize the object
        :param common_objs: common object dictionary
        :param db: name of the db
        :param table: name of the table in the db
        """
        super(BBRMgr, self).__init__(
            common_objs,
            [("CONFIG_DB", swsscommon.CFG_DEVICE_METADATA_TABLE_NAME, "localhost/bgp_asn"),],
            db,
            table,
        )
        self.enabled = False
        self.default_state = "disabled"
        self.bbr_enabled_pgs = {}
        self.__init()

    def set_handler(self, key, data):
        """ Implementation of 'SET' command for this class """
        if not self.enabled:
            log_info("BBRMgr::BBR is disabled. Drop the request")
            return True
        if not self.__set_validation(key, data):
            return True
        cmds, peer_groups_to_restart = self.__set_prepare_config(data['status'])
        self.cfg_mgr.push_list(cmds)
        self.cfg_mgr.restart_peer_groups(peer_groups_to_restart)
        log_info("BBRMgr::Scheduled BBR update")
        return True

    def del_handler(self, key):
        """ Implementation of 'DEL' command for this class """
        log_err("The '%s' table shouldn't be removed from the db" % self.table_name)

    def __init(self):
        """ Initialize BBRMgr. Extracted from constructor """
        if self.directory.path_exist("CONFIG_DB", "BGP_BBR", "all/status"):
            config_db_bbr = self.directory.get_slot("CONFIG_DB", "BGP_BBR")
            log_info("BBRMgr::Initialize from CONFIG_DB")
            self.bbr_enabled_pgs = self.__read_pgs()
            if self.bbr_enabled_pgs:
                self.enabled = True
                self.default_state = config_db_bbr["all"]["status"]
                log_info("BBRMgr::Initialized from CONFIG_DB and Enabled. Default state: '%s'" % self.default_state)
            else:
                log_info("BBRMgr::Initialized from CONFIG_DB and Disabled: no BBR enabled peers")
        else:
            log_info("BBRMgr::Initialize from constants")
            if not 'bgp' in self.constants:
                log_err("BBRMgr::Initialized from constants and Disabled: 'bgp' key is not found in constants")
            elif 'bbr' in self.constants['bgp'] \
                    and 'enabled' in self.constants['bgp']['bbr'] \
                    and self.constants['bgp']['bbr']['enabled']:
                self.bbr_enabled_pgs = self.__read_pgs()

                # Check if BBR enabled peers exist
                if self.bbr_enabled_pgs:
                    self.enabled = True
                    if 'default_state' in self.constants['bgp']['bbr'] \
                            and self.constants['bgp']['bbr']['default_state'] == 'enabled':
                        self.default_state = "enabled"
                    else:
                        self.default_state = "disabled"
                    log_info("BBRMgr::Initialized from constants and Enabled. Default state: '%s'" % self.default_state)
                else:
                    log_info("BBRMgr::Initialized from constants and Disabled: no BBR enabled peers")
            else:
                log_info("BBRMgr::Initialized from constants and Disabled: no bgp.bbr.enabled in the constants")
        self.directory.put(self.db_name, self.table_name, "all", {"status": self.default_state})

    def __read_pgs(self):
        """
        Read peer-group bbr settings from constants file
        :return: return bbr information from constant peer-group settings
        """
        if 'peers' not in self.constants['bgp']:
            log_info("BBRMgr::no 'peers' was found in constants")
            return {}
        res = {}
        for peer_name, value in self.constants['bgp']['peers'].items():
            if 'bbr' not in value:
                continue
            for pg_name, pg_afs in value['bbr'].items():
                res[pg_name] = pg_afs
        return res

    def __set_validation(self, key, data):
        """ Validate set-command arguments
        :param key: key of 'set' command
        :param data: data of 'set' command
        :return: True is the parameters are valid, False otherwise
        """
        if key != 'all':
            log_err("Invalid key '%s' for table '%s'. Only key value 'all' is supported" % (key, self.table_name))
            return False
        if 'status' not in data:
            log_err("Invalid value '%s' for table '%s', key '%s'. Key 'status' in data is expected" % (data, self.table_name, key))
            return False
        if data['status'] != "enabled" and data['status'] != "disabled":
            log_err("Invalid value '%s' for table '%s', key '%s'. Only 'enabled' and 'disabled' are supported" % (data, self.table_name, key))
            return False
        return True

    def __set_prepare_config(self, status):
        """
        Generate FFR configuration to apply changes
        :param status: either "enabled" or "disabled"
        :return: list of commands prepared for FRR
        """
        bgp_asn = self.directory.get_slot("CONFIG_DB", swsscommon.CFG_DEVICE_METADATA_TABLE_NAME)["localhost"]["bgp_asn"]
        available_peer_groups = self.__get_available_peer_groups()
        cmds = ["router bgp %s" % bgp_asn]
        prefix_of_commands = "" if status == "enabled" else "no "
        peer_groups_to_restart = set()
        for af in ["ipv4", "ipv6"]:
            cmds.append(" address-family %s" % af)
            for pg_name in sorted(self.bbr_enabled_pgs.keys()):
                for peer_group_name in available_peer_groups:
                    if peer_group_name.startswith(pg_name) and af in self.bbr_enabled_pgs[pg_name]:
                        cmds.append("  %sneighbor %s allowas-in 1" % (prefix_of_commands, peer_group_name))
                        peer_groups_to_restart.add(peer_group_name)
        return cmds, list(peer_groups_to_restart)

    def __get_available_peer_groups(self):
        """
        Extract configured peer-groups from the config
        :return: set of available peer-groups
        """
        re_pg = re.compile(r'^\s*neighbor\s+(\S+)\s+peer-group\s*$')
        res = set()
        self.cfg_mgr.update()
        for line in self.cfg_mgr.get_text():
            m = re_pg.match(line)
            if m:
                res.add(m.group(1))
        return res
