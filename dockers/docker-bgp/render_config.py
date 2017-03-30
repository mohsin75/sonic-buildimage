#!/usr/bin/env python

import sys
import os.path
import argparse

from minigraph_facts import parse_xml
import jinja2
import netaddr


def is_ipv4(value):
    if not value:
        return False
    if isinstance(value, netaddr.IPAddress):
        addr = value
    else:
        try:
            addr = netaddr.IPAddress(str(value))
        except:
            return False
    return addr.version == 4

def is_ipv6(value):
    if not value:
        return False
    if isinstance(value, netaddr.IPAddress):
        addr = value
    else:
        try:
            addr = netaddr.IPAddress(str(value))
        except:
            return False
    return addr.version == 6


def main():
    parser=argparse.ArgumentParser(description="Render configuration file from minigraph data and jinja2 template.")
    parser.add_argument("template")
    parser.add_argument("-m", "--minigraph", required=True, help="minigraph xml file")
    #parser.add_argument("-v", "--variable-file", help="yaml file that contains addtional variables")
    args = parser.parse_args()

    minigraph = args.minigraph
    template_file = args.template
    
    data = parse_xml(minigraph)

    env = jinja2.Environment(loader=jinja2.FileSystemLoader('./'), trim_blocks=True)
    env.filters['ipv4'] = is_ipv4
    env.filters['ipv6'] = is_ipv6
    template = env.get_template(template_file)

    print template.render(data)

if __name__ == "__main__":
    main()

