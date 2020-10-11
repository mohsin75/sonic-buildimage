# sonic-ctrmgrd package

SONIC_CTRMGRD = sonic_ctrmgrd-1.0.0-py3-none-any.whl
$(SONIC_CTRMGRD)_SRC_PATH = $(SRC_PATH)/sonic-ctrmgrd
$(SONIC_CTRMGRD)_PYTHON_VERSION = 3
$(SONIC_CTRMGRD)_DEPENDS += $(PYTHON3_SWSSCOMMON)
$(SONIC_CTRMGRD)_DEPENDS += $(SONIC_PY_COMMON_PY3)

$(SONIC_CTRMGRD)_MONITOR_SCRIPT = container_monitor.py
$($(SONIC_CTRMGRD)_MONITOR_SCRIPT)_PATH = $($(SONIC_CTRMGRD)_SRC_PATH)/ctrmgr

$(SONIC_CTRMGRD)_STATE_SCRIPT = container_state
$($(SONIC_CTRMGRD)_STATE_SCRIPT)_PATH = $($(SONIC_CTRMGRD)_SRC_PATH)/ctrmgr

$(SONIC_CTRMGRD)_CFG_JSON = kube.config.json
$($(SONIC_CTRMGRD)_CFG_JSON)_PATH = $($(SONIC_CTRMGRD)_SRC_PATH)/ctrmgr

$(SONIC_CTRMGRD)_SERVICE = ctrmgrd.service
$($(SONIC_CTRMGRD)_SERVICE)_PATH = $($(SONIC_CTRMGRD)_SRC_PATH)/ctrmgr

SONIC_PYTHON_WHEELS += $(SONIC_CTRMGRD)

SONIC_COPY_FILES += $($(SONIC_CTRMGRD)_MONITOR_SCRIPT) \
                    $($(SONIC_CTRMGRD)_STATE_SCRIPT) \
                    $($(SONIC_CTRMGRD)_CFG_JSON) \
                    $($(SONIC_CTRMGRD)_SERVICE)
