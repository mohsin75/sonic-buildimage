# initramfs-tools package

IXGBE_DRIVER_VERSION = 5.2.4
export IXGBE_DRIVER_VERSION

IXGBE_DRIVER = ixgbe.ko
$(IXGBE_DRIVER)_SRC_PATH = $(SRC_PATH)/ixgbe
$(IXGBE_DRIVER)_DEPENDS += $(LINUX_HEADERS) $(LINUX_HEADERS_COMMON)
SONIC_MAKE_DEBS += $(IXGBE_DRIVER)
