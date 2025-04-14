/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/drivers/i2c.h>

#define DT_DRV_COMPAT qemu_i2c_lattice

static const struct device *i2c_dev = DEVICE_DT_GET(DT_INST(0, DT_DRV_COMPAT));

int main(void)
{
	int ret;


	if (!device_is_ready(i2c_dev)) {
		printf("Device not found\n");
	}

	ret = i2c_write(i2c_dev, NULL, 1, 64);

	if (ret) {
		printf("Write operation is failed\n");
	}

	ret = i2c_read(i2c_dev, NULL, 1, 64);

	if (ret) {
		printf("Read operation is failed\n");
	}

	printf("Hello World! %s\n", CONFIG_BOARD_TARGET);

	return 0;
}
