#!/usr/bin/env python
from sonic_package_manager.reference import PackageReference


def test__reference():
    package_constraint = PackageReference.parse(
        'swss@sha256:9780f6d83e45878749497a6297ed9906c19ee0cc48cc88dc63827564bb8768fd'
    )
    assert package_constraint.name == 'swss'
    assert package_constraint.reference == 'sha256:9780f6d83e45878749497a6297ed9906c19ee0cc48cc88dc63827564bb8768fd'
