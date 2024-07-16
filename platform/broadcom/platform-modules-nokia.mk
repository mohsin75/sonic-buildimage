# Nokia Platform modules

NOKIA_IXR7250_PLATFORM_MODULE_VERSION = 1.0
NOKIA_IXR7220H3_PLATFORM_MODULE_VERSION = 1.0
NOKIA_IXR7220H4_32D_PLATFORM_MODULE_VERSION = 1.0
NOKIA_IXR7220H5_64D_PLATFORM_MODULE_VERSION = 1.0

export NOKIA_IXR7250_PLATFORM_MODULE_VERSION
export NOKIA_IXR7220H3_PLATFORM_MODULE_VERSION
export NOKIA_IXR7220H4_32D_PLATFORM_MODULE_VERSION
export NOKIA_IXR7220H5_64D_PLATFORM_MODULE_VERSION

NOKIA_IXR7250_PLATFORM_MODULE = sonic-platform-nokia-chassis_$(NOKIA_IXR7250_PLATFORM_MODULE_VERSION)_amd64.deb
$(NOKIA_IXR7250_PLATFORM_MODULE)_SRC_PATH = $(PLATFORM_PATH)/sonic-platform-modules-nokia
$(NOKIA_IXR7250_PLATFORM_MODULE)_DEPENDS += $(LINUX_HEADERS) $(LINUX_HEADERS_COMMON) $(NOKIA_NDK_DEBIAN)
$(NOKIA_IXR7250_PLATFORM_MODULE)_PLATFORM = x86_64-nokia_ixr7250e_sup-r0
$(NOKIA_IXR7250_PLATFORM_MODULE)_PLATFORM += x86_64-nokia_ixr7250e_36x400g-r0
SONIC_DPKG_DEBS += $(NOKIA_IXR7250_PLATFORM_MODULE)

NOKIA_IXR7220H3_PLATFORM_MODULE = sonic-platform-nokia-ixr7220h3_$(NOKIA_IXR7220H3_PLATFORM_MODULE_VERSION)_amd64.deb
$(NOKIA_IXR7220H3_PLATFORM_MODULE)_DEPENDS += $(LINUX_HEADERS) $(LINUX_HEADERS_COMMON) 
$(NOKIA_IXR7220H3_PLATFORM_MODULE)_PLATFORM = x86_64-nokia_ixr7220_h3-r0
$(eval $(call add_extra_package,$(NOKIA_IXR7250_PLATFORM_MODULE),$(NOKIA_IXR7220H3_PLATFORM_MODULE)))

NOKIA_IXR7220H4_32D_PLATFORM_MODULE = sonic-platform-nokia-ixr7220h4-32d_$(NOKIA_IXR7220H4_32D_PLATFORM_MODULE_VERSION)_amd64.deb
$(NOKIA_IXR7220H4_32D_PLATFORM_MODULE)_DEPENDS += $(LINUX_HEADERS) $(LINUX_HEADERS_COMMON) 
$(NOKIA_IXR7220H4_32D_PLATFORM_MODULE)_PLATFORM = x86_64-nokia_ixr7220_h4_32d-r0
$(eval $(call add_extra_package,$(NOKIA_IXR7250_PLATFORM_MODULE),$(NOKIA_IXR7220H4_32D_PLATFORM_MODULE)))

NOKIA_IXR7220H5_64D_PLATFORM_MODULE = sonic-platform-nokia-ixr7220h5-64d_$(NOKIA_IXR7220H5_64D_PLATFORM_MODULE_VERSION)_amd64.deb
$(NOKIA_IXR7220H5_64D_PLATFORM_MODULE)_DEPENDS += $(LINUX_HEADERS) $(LINUX_HEADERS_COMMON) 
$(NOKIA_IXR7220H5_64D_PLATFORM_MODULE)_PLATFORM = x86_64-nokia_ixr7220_h5_64d-r0
$(eval $(call add_extra_package,$(NOKIA_IXR7250_PLATFORM_MODULE),$(NOKIA_IXR7220H5_64D_PLATFORM_MODULE)))
