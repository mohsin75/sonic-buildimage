# python-saithrift package

PYTHON_SAITHRIFT_BRCM = python-saithrift_0.9.4_amd64.deb
$(PYTHON_SAITHRIFT_BRCM)_SRC_PATH = $(SRC_PATH)/SAI
$(PYTHON_SAITHRIFT_BRCM)_DEPENDS += $(BRCM_SAI_DEV) $(THRIFT_COMPILER) $(PYTHON_THRIFT) $(LIBTHRIFT_DEV)
#SONIC_DPKG_DEBS += $(PYTHON_SAITHRIFT_BRCM)
