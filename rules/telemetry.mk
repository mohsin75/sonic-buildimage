# SONiC telemetry package

SONIC_TELEMETRY = sonic-gnmi_0.1_$(CONFIGURED_ARCH).deb
$(SONIC_TELEMETRY)_SRC_PATH = $(SRC_PATH)/sonic-gnmi
$(SONIC_TELEMETRY)_DEPENDS  = $(SONIC_MGMT_COMMON) $(SONIC_MGMT_COMMON_CODEGEN) \
    $(LIBSWSSCOMMON_DEV) $(LIBSWSSCOMMON) 
$(SONIC_TELEMETRY)_RDEPENDS = $(LIBSWSSCOMMON) $(LIBSWSSCOMMON_DEV)
SONIC_DPKG_DEBS += $(SONIC_TELEMETRY)
