# sonic-stormond (SONiC Storage Monitoring daemon) Debian package

# SONIC_STORMOND_PY3 package

SONIC_STORMOND_PY3 = sonic_stormond-1.0-py3-none-any.whl
$(SONIC_STORMOND_PY3)_SRC_PATH = $(SRC_PATH)/sonic-platform-daemons/sonic-stormond
$(SONIC_STORMOND_PY3)_DEPENDS = $(SONIC_PY_COMMON_PY3)
$(SONIC_STORMOND_PY3)_PYTHON_VERSION = 3
SONIC_PYTHON_WHEELS += $(SONIC_STORMOND_PY3)
