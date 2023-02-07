# PDDF Generic Platform modules
#####################################################
PDDF_PLATFORM_MODULE_VERSION = 1.1

export PDDF_PLATFORM_MODULE_VERSION

PDDF_PLATFORM_MODULE = sonic-platform-pddf_$(PDDF_PLATFORM_MODULE_VERSION)_amd64.deb
$(PDDF_PLATFORM_MODULE)_SRC_PATH = $(PLATFORM_PDDF_PATH)/i2c
$(PDDF_PLATFORM_MODULE)_DEPENDS += $(LINUX_HEADERS) $(LINUX_HEADERS_COMMON)
SONIC_DPKG_DEBS += $(PDDF_PLATFORM_MODULE)

PDDF_PLATFORM_MODULE_SYM = sonic-platform-pddf-sym_$(PDDF_PLATFORM_MODULE_VERSION)_amd64.deb
$(eval $(call add_derived_package,$(PDDF_PLATFORM_MODULE),$(PDDF_PLATFORM_MODULE_SYM)))

SONIC_STRETCH_DEBS += $(PDDF_PLATFORM_MODULE)
