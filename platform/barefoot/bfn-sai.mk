BFN_SAI = bfnsdk_1.0.0_amd64.deb
$(BFN_SAI)_URL =	"https://www.dropbox.com/s/4ljk6hzw82rudsr/bfnsdk_1.0.0_amd64.deb?dl=0"
# $(BFN_SAI_DEV)_URL =	"https://www.dropbox.com/s/4ljk6hzw82rudsr/bfnsdk_1.0.0_amd64.deb?dl=0"

SONIC_ONLINE_DEBS += $(BFN_SAI) # $(BFN_SAI_DEV)
$(BFN_SAI_DEV)_DEPENDS += $(BFN_SAI)
