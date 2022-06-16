LIBSAIBCM_XGS_VERSION = 7.1.0.0-5
LIBSAIBCM_DNX_VERSION = 7.1.0.0-1
LIBSAIBCM_BRANCH_NAME = REL_7.0
LIBSAIBCM_XGS_URL_PREFIX = "https://sonicstorage.blob.core.windows.net/public/sai/bcmsai/$(LIBSAIBCM_BRANCH_NAME)/$(LIBSAIBCM_XGS_VERSION)"
LIBSAIBCM_DNX_URL_PREFIX = "https://sonicstorage.blob.core.windows.net/public/sai/bcmsai/$(LIBSAIBCM_BRANCH_NAME)/$(LIBSAIBCM_DNX_VERSION)"

BRCM_SAI = libsaibcm_$(LIBSAIBCM_XGS_VERSION)_amd64.deb
$(BRCM_SAI)_URL = "$(LIBSAIBCM_XGS_URL_PREFIX)/$(BRCM_SAI)"
BRCM_SAI_DEV = libsaibcm-dev_$(LIBSAIBCM_XGS_VERSION)_amd64.deb
$(eval $(call add_derived_package,$(BRCM_SAI),$(BRCM_SAI_DEV)))
$(BRCM_SAI_DEV)_URL = "$(LIBSAIBCM_XGS_URL_PREFIX)/$(BRCM_SAI_DEV)"

# SAI module for DNX Asic family
BRCM_DNX_SAI = libsaibcm_dnx_$(LIBSAIBCM_DNX_VERSION)_amd64.deb
$(BRCM_DNX_SAI)_URL = "$(LIBSAIBCM_DNX_URL_PREFIX)/$(BRCM_DNX_SAI)"

SONIC_ONLINE_DEBS += $(BRCM_SAI)
SONIC_ONLINE_DEBS += $(BRCM_DNX_SAI)
$(BRCM_SAI_DEV)_DEPENDS += $(BRCM_SAI)
$(eval $(call add_conflict_package,$(BRCM_SAI_DEV),$(LIBSAIVS_DEV)))
