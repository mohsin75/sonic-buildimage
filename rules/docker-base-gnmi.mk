# docker image for GNMI base

DOCKER_BASE_GNMI_STEM = docker-base-gnmi
DOCKER_BASE_GNMI = $(DOCKER_BASE_GNMI_STEM).gz
DOCKER_BASE_GNMI_DBG = $(DOCKER_BASE_GNMI_STEM)-$(DBG_IMAGE_MARK).gz

$(DOCKER_BASE_GNMI)_PATH = $(DOCKERS_PATH)/$(DOCKER_BASE_GNMI_STEM)

$(DOCKER_BASE_GNMI)_DEPENDS += $(SONIC_MGMT_COMMON)
$(DOCKER_BASE_GNMI)_DEPENDS += $(SONIC_TELEMETRY)
$(DOCKER_BASE_GNMI)_DBG_DEPENDS = $($(DOCKER_CONFIG_ENGINE_BULLSEYE)_DBG_DEPENDS)

$(DOCKER_BASE_GNMI)_LOAD_DOCKERS += $(DOCKER_CONFIG_ENGINE_BULLSEYE)

$(DOCKER_BASE_GNMI)_VERSION = 1.0.0
$(DOCKER_BASE_GNMI)_PACKAGE_NAME = base-gnmi

$(DOCKER_BASE_GNMI)_DBG_IMAGE_PACKAGES = $($(DOCKER_CONFIG_ENGINE_BULLSEYE)_DBG_IMAGE_PACKAGES)

SONIC_DOCKER_IMAGES += $(DOCKER_BASE_GNMI)
SONIC_BULLSEYE_DOCKERS += $(DOCKER_BASE_GNMI)

