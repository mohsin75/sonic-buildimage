#!/usr/bin/env bash

# This version is per docker. To be updated upon updates.
# Hence this could be different from version of other features
IMAGE_VERSION = "1.0.0"

if [ "${RUNTIME_OWNER}" == "" ]; then
    RUNTIME_OWNER="local"
fi

/usr/bin/container_state up -f snmp -o ${RUNTIME_OWNER} -v ${IMAGE_VERSION}

mkdir -p /var/sonic
echo "# Config files managed by sonic-config-engine" > /var/sonic/config_status
