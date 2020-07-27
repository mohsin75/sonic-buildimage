# Marvell SAI

export MRVL_SAI_VERSION = 1.2.1
export MRVL_SAI_TAG = SONiC.201803
export MRVL_SAI = mrvllibsai_$(MRVL_SAI_VERSION).deb

$(MRVL_SAI)_SRC_PATH = $(PLATFORM_PATH)/sai
$(MRVL_SAI)_DEPENDS += $(MRVL_FPA)
$(eval $(call add_conflict_package,$(MRVL_SAI),$(LIBSAIVS_DEV)))

SONIC_MAKE_DEBS += $(MRVL_SAI)
