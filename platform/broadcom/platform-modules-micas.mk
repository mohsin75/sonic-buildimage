## M2-W6510-32C
MICAS_M2_W6510_32C_PLATFORM_MODULE_VERSION = 1.0
export MICAS_M2_W6510_32C_PLATFORM_MODULE_VERSION

MICAS_M2_W6510_32C_PLATFORM_MODULE = platform-modules-micas-m2-w6510-32c_$(MICAS_M2_W6510_32C_PLATFORM_MODULE_VERSION)_amd64.deb
$(MICAS_M2_W6510_32C_PLATFORM_MODULE)_SRC_PATH = $(PLATFORM_PATH)/sonic-platform-modules-micas
$(MICAS_M2_W6510_32C_PLATFORM_MODULE)_DEPENDS += $(LINUX_HEADERS) $(LINUX_HEADERS_COMMON) $(PDDF_PLATFORM_MODULE)
$(MICAS_M2_W6510_32C_PLATFORM_MODULE)_PLATFORM = x86_64-micas_m2-w6510-32c-r0
SONIC_DPKG_DEBS += $(MICAS_M2_W6510_32C_PLATFORM_MODULE)
SONIC_STRETCH_DEBS += $(MICAS_M2_W6510_32C_PLATFORM_MODULE)

