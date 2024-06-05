SONIC_NETTOOLS_VERSION = 0.1

export SONIC_NETTOOLS_VERSION

SONIC_NETTOOLS = sonic-nettools_$(SONIC_NETTOOLS_VERSION)_$(CONFIGURED_ARCH).deb
$(SONIC_NETTOOLS)_SRC_PATH = $(SRC_PATH)/sonic-nettools
SONIC_MAKE_DEBS += $(SONIC_NETTOOLS)

$(eval $(call add_extra_package,$(SONIC_NETTOOLS),$(package)))
