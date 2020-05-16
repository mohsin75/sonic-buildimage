# docker image for docker-ptf-cavm

DOCKER_PTF_CAVM = docker-ptf-cavm.gz
$(DOCKER_PTF_CAVM)_PATH = $(DOCKERS_PATH)/docker-ptf-saithrift
$(DOCKER_PTF_CAVM)_DEPENDS += $(PYTHON_SAITHRIFT_CAVM)
$(DOCKER_PTF_CAVM)_LOAD_DOCKERS += $(DOCKER_PTF)
SONIC_DOCKER_IMAGES += $(DOCKER_PTF_CAVM)
SONIC_STRETCH_DOCKERS += $(DOCKER_PTF_CAVM)
