# Accton Platform modules
ACCTON_ES9632XX_PLATFORM_MODULE_VERSION = 1.1
ACCTON_ES9632XQ_PLATFORM_MODULE_VERSION = 1.1

export ACCTON_ES9632XX_PLATFORM_MODULE_VERSION
export ACCTON_ES9632XQ_PLATFORM_MODULE_VERSION

ACCTON_ES9632XX_PLATFORM_MODULE = sonic-platform-accton-es9632xx_$(ACCTON_ES9632XX_PLATFORM_MODULE_VERSION)_amd64.deb
$(ACCTON_ES9632XX_PLATFORM_MODULE)_SRC_PATH = $(PLATFORM_PATH)/sonic-platform-modules-accton
$(ACCTON_ES9632XX_PLATFORM_MODULE)_PLATFORM = x86_64-es9632xx-r0
$(ACCTON_ES9632XX_PLATFORM_MODULE)_DEPENDS += $(LINUX_HEADERS) $(LINUX_HEADERS_COMMON)
SONIC_DPKG_DEBS += $(ACCTON_ES9632XX_PLATFORM_MODULE)

ACCTON_ES9632XQ_PLATFORM_MODULE = sonic-platform-accton-es9632xq_$(ACCTON_ES9632XQ_PLATFORM_MODULE_VERSION)_amd64.deb
$(ACCTON_ES9632XQ_PLATFORM_MODULE)_PLATFORM = x86_64-es9632xq-r0
$(eval $(call add_extra_package,$(ACCTON_ES9632XX_PLATFORM_MODULE),$(ACCTON_ES9632XQ_PLATFORM_MODULE)))
