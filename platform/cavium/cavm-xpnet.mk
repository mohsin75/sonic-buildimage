CAVM_SAI_URL = https://github.com/XPliant/OpenXPS/raw/18cd5fb556b6262943c0af70375e2631ac3fe08d/SAI

CAVM_XPNET_DEB = xp80-Pcie-Endpoint.deb
$(CAVM_XPNET_DEB)_URL = $(CAVM_SAI_URL)/netdev/$(CAVM_XPNET_DEB)

SONIC_ONLINE_DEBS += $(CAVM_XPNET_DEB)
