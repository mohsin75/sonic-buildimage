#!/usr/bin/env bash


if [ "${RUNTIME_OWNER}" == "" ]; then
    RUNTIME_OWNER="kube"
fi

CTR_SCRIPT="/usr/share/sonic/scripts/container_state.py"
if test -f ${CTR_SCRIPT}
then
    ${CTR_SCRIPT} up -f snmp -o ${RUNTIME_OWNER} -v ${IMAGE_VERSION}
fi

mkdir -p /etc/ssw /etc/snmp

SONIC_CFGGEN_ARGS=" \
    -d \
    -y /etc/sonic/sonic_version.yml \
    -t /usr/share/sonic/templates/sysDescription.j2,/etc/ssw/sysDescription \
    -y /etc/sonic/snmp.yml \
    -t /usr/share/sonic/templates/snmpd.conf.j2,/etc/snmp/snmpd.conf \
"

sonic-cfggen $SONIC_CFGGEN_ARGS

mkdir -p /var/sonic
echo "# Config files managed by sonic-config-engine" > /var/sonic/config_status
