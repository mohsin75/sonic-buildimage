# Arista Platform modules

ARISTA_PLATFORM_MODULE_VERSION = 1.0

export ARISTA_PLATFORM_MODULE_VERSION

ARISTA_PLATFORM_MODULE = sonic-platform-arista_$(ARISTA_PLATFORM_MODULE_VERSION)_amd64.deb
$(ARISTA_PLATFORM_MODULE)_SRC_PATH = $(PLATFORM_PATH)/sonic-platform-modules-arista
$(ARISTA_PLATFORM_MODULE)_DEPENDS += $(LINUX_HEADERS) $(LINUX_HEADERS_COMMON)
SONIC_MAKE_DEBS += $(ARISTA_PLATFORM_MODULE)

ARISTA_PLATFORM_MODULE_PYTHON2 = python-sonic-platform-arista_$(ARISTA_PLATFORM_MODULE_VERSION)_all.deb
$(eval $(call add_extra_package,$(ARISTA_PLATFORM_MODULE),$(ARISTA_PLATFORM_MODULE_PYTHON2)))

ARISTA_PLATFORM_MODULE_PYTHON3 = python3-sonic-platform-arista_$(ARISTA_PLATFORM_MODULE_VERSION)_all.deb
$(eval $(call add_extra_package,$(ARISTA_PLATFORM_MODULE),$(ARISTA_PLATFORM_MODULE_PYTHON3)))

ARISTA_PLATFORM_MODULE_DRIVERS = drivers-sonic-platform-arista_$(ARISTA_PLATFORM_MODULE_VERSION)_amd64.deb
$(eval $(call add_extra_package,$(ARISTA_PLATFORM_MODULE),$(ARISTA_PLATFORM_MODULE_DRIVERS)))

export ARISTA_PLATFORM_MODULE ARISTA_PLATFORM_MODULE_PYTHON2 ARISTA_PLATFORM_MODULE_PYTHON3 ARISTA_PLATFORM_MODULE_DRIVERS

export ARISTA_SCD_DRIVER_CONFIG=m
