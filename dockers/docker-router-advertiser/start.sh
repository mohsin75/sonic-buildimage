#! /bin/bash

if [ "${RUNTIME_OWNER}" == "" ]; then
    RUNTIME_OWNER="kube"
fi

CTR_SCRIPT="/usr/share/sonic/scripts/container_state.py"
if test -f ${CTR_SCRIPT}
then
    ${CTR_SCRIPT} up -f radv -o ${RUNTIME_OWNER} -v ${IMAGE_VERSION}
fi

