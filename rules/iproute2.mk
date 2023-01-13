# iproute2 package

IPROUTE2_VERSION = 5.10.0
IPROUTE2_VERSION_FULL = ${IPROUTE2_VERSION}-4

export IPROUTE2_VERSION
export IPROUTE2_VERSION_FULL

IPROUTE2 = iproute2_$(IPROUTE2_VERSION_FULL)_$(CONFIGURED_ARCH).deb
$(IPROUTE2)_SRC_PATH = $(SRC_PATH)/iproute2
SONIC_MAKE_DEBS += $(IPROUTE2)
