import setuptools

setuptools.setup(
    name = 'sonic-frr-mgmt-framework',
    version = '1.0',
    description = 'Utility to dynamically configuration FRR based on database update',
    url = 'https://github.com/Azure/sonic-buildimage',
    packages = setuptools.find_packages(),
    entry_points = {
        'console_scripts': [
            'frrcfgd = frrcfgd.frrcfgd:main',
        ]
    },
    install_requires = [
        'jinja2>=2.10',
        'netaddr==0.8.0',
        'pyyaml==5.3.1',
        'zipp==1.2.0', # importlib-resources needs zipp and seems to have a bug where it will try to import too new of a version for Python 2
    ],
    setup_requires = [
        'pytest-runner',
        'wheel'
    ],
    tests_require = [
        'pytest',
        'pytest-cov',
        'sonic-config-engine'
    ],
    data_files = [('frr/common', ['templates/common/daemons.common.conf.j2']),
                  ('frr/bgpd', ['templates/bgpd/bgpd.conf.db.j2',
                                'templates/bgpd/bgpd.spine_chassis_frontend_router.conf.j2',
                                'templates/bgpd/bgpd.conf.j2',
                                'templates/bgpd/bgpd.conf.db.route_map.j2',
                                'templates/bgpd/bgpd.conf.db.pref_list.j2',
                                'templates/bgpd/bgpd.conf.db.nbr_or_peer.j2',
                                'templates/bgpd/bgpd.conf.db.nbr_af.j2',
                                'templates/bgpd/bgpd.conf.db.comm_list.j2',
                                'templates/bgpd/bgpd.conf.db.addr_family.j2',
                                'templates/bgpd/bgpd.conf.db.addr_family.evpn.j2']),
                  ('frr/bfdd', ['templates/bfdd/bfdd.conf.j2']),
                  ('frr/ospfd', ['templates/ospfd/ospfd.conf.j2',
                                 'templates/ospfd/ospfd.conf.db.area.j2',
                                 'templates/ospfd/ospfd.conf.db.comm_list.j2',
                                 'templates/ospfd/ospfd.conf.db.distributeroute.j2',
                                 'templates/ospfd/ospfd.conf.db.interface.j2',
                                 'templates/ospfd/ospfd.conf.db.policyrange.j2',
                                 'templates/ospfd/ospfd.conf.db.vlink.j2']),
                  ('frr/staticd', ['templates/staticd/staticd.conf.j2',
                                   'templates/staticd/staticd.db.conf.j2',
                                   'templates/staticd/staticd.default_route.conf.j2']),
                  ('frr/supervisord', ['templates/supervisord/supervisord.conf.j2',
                                       'templates/supervisord/critical_processes'])
    ]
)
