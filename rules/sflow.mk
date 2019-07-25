# host-sflow package

HSFLOWD_VERSION = 2.0.21
HSFLOWD_SUBVERSION = 3
export HSFLOWD_VERSION HSFLOWD_SUBVERSION

HSFLOWD = hsflowd_$(HSFLOWD_VERSION)-$(HSFLOWD_SUBVERSION)_amd64.deb
$(HSFLOWD)_DEPENDS += $(LIBHIREDIS_DEV) $(LINUX_HEADERS) $(LINUX_HEADERS_COMMON)
$(HSFLOWD)_SRC_PATH = $(SRC_PATH)/sflow/hsflowd

SONIC_MAKE_DEBS += $(HSFLOWD)
SONIC_STRETCH_DEBS += $(HSFLOWD)
export HSFLOWD

# sflowtool package

SFLOWTOOL_VERSION = 5.04
export SFLOWTOOL_VERSION

SFLOWTOOL = sflowtool_$(SFLOWTOOL_VERSION)_amd64.deb
$(SFLOWTOOL)_SRC_PATH = $(SRC_PATH)/sflow/sflowtool

SONIC_MAKE_DEBS += $(SFLOWTOOL)
SONIC_STRETCH_DEBS += $(SFLOWTOOL)
export SFLOWTOOL

# libmnl & psample packages

LIBMNL_DEV_VERSION = 1.0.4-2
export LIBMNL_DEV_VERSION
LIBMNL_DEV = libmnl-dev_$(LIBMNL_DEV_VERSION)_amd64.deb
$(LIBMNL_DEV)_URL = http://ftp.debian.org/debian/pool/main/libm/libmnl/libmnl-dev_1.0.4-2_amd64.deb
SONIC_ONLINE_DEBS += $(LIBMNL_DEV)

PSAMPLE_VERSION = 1.1
PSAMPLE_SUBVERSION = 1
export PSAMPLE_VERSION PSAMPLE_SUBVERSION

PSAMPLE = psample_$(PSAMPLE_VERSION)-$(PSAMPLE_SUBVERSION)_amd64.deb
$(PSAMPLE)_DEPENDS += $(LIBMNL_DEV)
$(PSAMPLE)_SRC_PATH = $(SRC_PATH)/sflow/psample

SONIC_MAKE_DEBS += $(PSAMPLE)
SONIC_STRETCH_DEBS += $(PSAMPLE)
export PSAMPLE
