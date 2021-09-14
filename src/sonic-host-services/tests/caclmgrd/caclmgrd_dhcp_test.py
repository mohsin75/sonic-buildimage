import os
import sys

from swsscommon import swsscommon
from parameterized import parameterized
from sonic_py_common.general import load_module_from_source
from unittest import TestCase, mock

from .test_dhcp_vectors import CACLMGRD_DHCP_TEST_VECTOR
from tests.common.mock_configdb import MockConfigDb


swsscommon.ConfigDBConnector = MockConfigDb
test_path = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
modules_path = os.path.dirname(test_path)
scripts_path = os.path.join(modules_path, "scripts")
sys.path.insert(0, modules_path)
caclmgrd_path = os.path.join(scripts_path, 'caclmgrd')
caclmgrd = load_module_from_source('caclmgrd', caclmgrd_path)


class TestCaclmgrdDhcp(TestCase):
    """
        Test caclmgrd dhcp
    """
    @parameterized.expand(CACLMGRD_DHCP_TEST_VECTOR)
    def test_caclmgrd_dhcp(self, test_name, test_data):
        MockConfigDb.set_config_db(test_data["config_db"])

        with mock.patch("caclmgrd.subprocess") as mocked_subprocess:
            popen_mock = mock.Mock()
            popen_attrs = test_data["popen_attributes"]
            popen_mock.configure_mock(**popen_attrs)
            mocked_subprocess.Popen.return_value = popen_mock

            call_mock = mock.Mock()
            call_rc = test_data["call_rc"]
            mocked_subprocess.call.return_value = call_rc

            caclmgrd_daemon = caclmgrd.ControlPlaneAclManager("caclmgrd")
            mux_update = test_data["mux_update"]

            for key,data in mux_update:
                caclmgrd_daemon.update_dhcp_acl(key, '', data)

            mocked_subprocess.call.assert_has_calls(test_data["expected_subprocess_calls"], any_order=False)
