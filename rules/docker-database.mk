# docker image for database

DOCKER_DATABASE_STEM = docker-database
DOCKER_DATABASE = $(DOCKER_DATABASE_STEM).gz
DOCKER_DATABASE_DBG = $(DOCKER_DATABASE_STEM)-$(DBG_IMAGE_MARK).gz

$(DOCKER_DATABASE)_PATH = $(DOCKERS_PATH)/$(DOCKER_DATABASE_STEM)

$(DOCKER_DATABASE)_DEPENDS += $(REDIS_TOOLS) $(REDIS_SERVER)
$(DOCKER_DATABASE)_DBG_DEPENDS = $($(DOCKER_CONFIG_ENGINE_STRETCH)_DBG_DEPENDS)
$(DOCKER_DATABASE)_DBG_DEPENDS += $(REDIS_TOOLS_DBG)

$(DOCKER_DATABASE)_DBG_IMAGE_PACKAGES = $($(DOCKER_CONFIG_ENGINE_STRETCH)_DBG_IMAGE_PACKAGES)

$(DOCKER_DATABASE)_LOAD_DOCKERS += $(DOCKER_CONFIG_ENGINE_STRETCH)

SONIC_DOCKER_IMAGES += $(DOCKER_DATABASE)
SONIC_INSTALL_DOCKER_IMAGES += $(DOCKER_DATABASE)
SONIC_STRETCH_DOCKERS += $(DOCKER_DATABASE)

SONIC_DOCKER_DBG_IMAGES += $(DOCKER_DATABASE_DBG)
SONIC_INSTALL_DOCKER_DBG_IMAGES += $(DOCKER_DATABASE_DBG)
SONIC_STRETCH_DBG_DOCKERS += $(DOCKER_DATABASE_DBG)

$(DOCKER_DATABASE)_CONTAINER_NAME = database
$(DOCKER_DATABASE)_RUN_OPT += --privileged -t
$(DOCKER_DATABASE)_RUN_OPT += -v /etc/sonic:/etc/sonic:ro

$(DOCKER_DATABASE)_BASE_IMAGE_FILES += redis-cli:/usr/bin/redis-cli
$(DOCKER_DATABASE)_BASE_IMAGE_FILES += monit_database:/etc/monit/conf.d
