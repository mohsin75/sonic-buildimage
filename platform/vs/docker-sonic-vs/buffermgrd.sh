#!/usr/bin/env bash

BUFFER_CALCULATION_MODE=$(redis-cli -n 4 hget "DEVICE_METADATA|localhost" buffer_model)
export ASIC_VENDOR=vs

if [ "$BUFFER_CALCULATION_MODE" == "dynamic" ]; then
    BUFFERMGRD_ARGS="-a /etc/sonic/asic_table.json -p /etc/sonic/peripheral_table.json"
else
    # Should we use the fallback MAC in case it is not found in Device.Metadata
    BUFFERMGRD_ARGS="-l /usr/share/sonic/hwsku/pg_profile_lookup.ini"
fi

exec /usr/bin/buffermgrd ${BUFFERMGRD_ARGS}
