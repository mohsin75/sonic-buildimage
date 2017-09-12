#!/usr/bin/env bash

# Generate supervisord config file
mkdir -p /etc/supervisor/conf.d/
sonic-cfggen -m /etc/sonic/minigraph.xml -t /usr/share/sonic/templates/docker-dhcp-relay.supervisord.conf.j2 > /etc/supervisor/conf.d/docker-dhcp-relay.supervisord.conf

# Generate the script that waits for all interfaces to come up and make it executable
sonic-cfggen -d -t /usr/share/sonic/templates/wait_for_intf.sh.j2 > /usr/bin/wait_for_intf.sh
chmod +x /usr/bin/wait_for_intf.sh

# The docker container should start this script as PID 1, so now that supervisord is
# properly configured, we exec supervisord so that it runs as PID 1 for the
# duration of the container's lifetime
exec /usr/bin/supervisord
