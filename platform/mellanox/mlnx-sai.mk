# Mellanox SAI

MLNX_SAI_VERSION = ffbwithv1.4-sonicffb
MLNX_SAI_REVISION = 489702025311e019b6565bfd74f91f2c518dcdab

export MLNX_SAI_VERSION MLNX_SAI_REVISION

MLNX_SAI = mlnx-sai_1.mlnx.$(MLNX_SAI_VERSION)_amd64.deb
$(MLNX_SAI)_SRC_PATH = $(PLATFORM_PATH)/mlnx-sai
$(MLNX_SAI)_DEPENDS += $(MLNX_SDK_DEBS)
$(MLNX_SAI)_RDEPENDS += $(MLNX_SDK_RDEBS) $(MLNX_SDK_DEBS)
SONIC_MAKE_DEBS += $(MLNX_SAI)
