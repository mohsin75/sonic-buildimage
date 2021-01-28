# docker image for fpm-frr

DOCKER_FPM_FRR_STEM = docker-fpm-frr
DOCKER_FPM_FRR = $(DOCKER_FPM_FRR_STEM).gz
DOCKER_FPM_FRR_DBG = $(DOCKER_FPM_FRR_STEM)-$(DBG_IMAGE_MARK).gz

$(DOCKER_FPM_FRR)_PATH = $(DOCKERS_PATH)/$(DOCKER_FPM_FRR_STEM)
$(DOCKER_FPM_FRR)_PYTHON_WHEELS += $(SONIC_BGPCFGD) $(SONIC_FRR_MGMT_FRAMEWORK)

$(DOCKER_FPM_FRR)_DEPENDS += $(FRR) $(FRR_SNMP) $(SWSS) $(LIBYANG1)
$(DOCKER_FPM_FRR)_DBG_DEPENDS = $($(DOCKER_CONFIG_ENGINE_BUSTER)_DBG_DEPENDS)
$(DOCKER_FPM_FRR)_DBG_DEPENDS += $(SWSS_DBG) $(LIBSWSSCOMMON_DBG) \
                                $(FRR_DBG) $(FRR_SNMP_DBG) $(LIBYANG1_DBG)

$(DOCKER_FPM_FRR)_DBG_IMAGE_PACKAGES = $($(DOCKER_CONFIG_ENGINE_BUSTER)_DBG_IMAGE_PACKAGES)

$(DOCKER_FPM_FRR)_LOAD_DOCKERS += $(DOCKER_CONFIG_ENGINE_BUSTER)

SONIC_DOCKER_IMAGES += $(DOCKER_FPM_FRR)

SONIC_DOCKER_DBG_IMAGES += $(DOCKER_FPM_FRR_DBG)

$(DOCKER_FPM_FRR)_CONTAINER_NAME = bgp
$(DOCKER_FPM_FRR)_RUN_OPT += --privileged -t
$(DOCKER_FPM_FRR)_RUN_OPT += -v /etc/sonic:/etc/sonic:ro

$(DOCKER_FPM_FRR)_FILES += $(SUPERVISOR_PROC_EXIT_LISTENER_SCRIPT)

$(DOCKER_FPM_FRR)_BASE_IMAGE_FILES += vtysh:/usr/bin/vtysh
$(DOCKER_FPM_FRR)_BASE_IMAGE_FILES += TSA:/usr/bin/TSA
$(DOCKER_FPM_FRR)_BASE_IMAGE_FILES += TSB:/usr/bin/TSB
$(DOCKER_FPM_FRR)_BASE_IMAGE_FILES += TSC:/usr/bin/TSC
$(DOCKER_FPM_FRR)_BASE_IMAGE_FILES += TSC:/usr/bin/TS
$(DOCKER_FPM_FRR)_BASE_IMAGE_FILES += monit_bgp:/etc/monit/conf.d
