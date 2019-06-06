# libhiredis package

HIREDIS_VERSION = 0.13.3
HIREDIS_VERSION_FULL = $(HIREDIS_VERSION)-2

export HIREDIS_VERSION HIREDIS_VERSION_FULL

LIBHIREDIS = libhiredis0.13_$(HIREDIS_VERSION_FULL)_$(CONFIGURED_ARCH).deb
$(LIBHIREDIS)_SRC_PATH = $(SRC_PATH)/hiredis
$(LIBHIREDIS)_DEPENDS += $(REDIS_TOOLS) $(REDIS_SERVER)
$(LIBHIREDIS)_RDEPENDS +=
SONIC_MAKE_DEBS += $(LIBHIREDIS)

LIBHIREDIS_DEV = libhiredis-dev_$(HIREDIS_VERSION_FULL)_$(CONFIGURED_ARCH).deb
$(eval $(call add_derived_package,$(LIBHIREDIS),$(LIBHIREDIS_DEV)))

LIBHIREDIS_DBG = libhiredis-dbg_$(HIREDIS_VERSION_FULL)_$(CONFIGURED_ARCH).deb
$(eval $(call add_derived_package,$(LIBHIREDIS),$(LIBHIREDIS_DBG)))
