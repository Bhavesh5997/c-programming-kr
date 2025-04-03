#include <zephyr/drivers/i2c.h>
#include <zephyr/device.h>
#include <zephyr/sys/util.h>
#include <stdio.h>
#include <zephyr/devicetree.h>
#include <zephyr/irq.h>
#include "i2c_lattice.h"

#define DT_DRV_COMPAT qemu_i2c_lattice

struct i2c_lattice_config {
	mem_addr_t base;
};

struct i2c_lattice_data {
	struct k_mutex mutex;
};

static int i2c_lattice_read(const struct i2c_lattice_config *config,
			    struct i2c_lattice_data *data, struct i2c_msg *msg,
			    uint16_t addr)
{
	uint8_t *read_ptr = msg->buf;
	uint32_t bytes_left = msg->len;
	int count_bytes = 1;

	if (!bytes_left)
		return -EINVAL;

	k_mutex_lock(&data->mutex, K_FOREVER);
	sys_write8(BUS_SPEED_MODE_MASK & 0x01, config->base + MODE_REG);
	sys_write8(addr_mode, config->base + MODE_REG);
	sys_write8(trx_mode, config->base + MODE_REG);
	sys_write8(msg->len, config->base + TGT_BYTE_CNT_REG);
	sys_write8(start, config->base + CONTROL_REG);

	while (bytes_left) {
		if (bytes_left <= FIFO_DEPTH) {
			if (count_bytes > 1)
				sys_write8(repeated_start, config->base + CONTROL_REG);
			while (sys_read8(config->base + INT_STATUS1_REG) &
			       tr_cmp_int);

			sys_write8(0xFF, config->base + INT_STATUS1_REG);

			*read_ptr++ = sys_read8(config->base + RD_DATA_REG);
		} else {
			if (count_bytes > 1)
				sys_write8(repeated_start, config->base + CONTROL_REG);
			while (sys_read8(config->base + INT_STATUS1_REG) &
			       rx_fifo_afull_int);

			sys_write8(0xFF, config->base + INT_STATUS1_REG);

			*read_ptr++ = sys_read8(config->base + RD_DATA_REG);
		}
		bytes_left--;
		count_bytes++;
	}

	k_mutex_unlock(&data->mutex);

	return 0;
}

static int i2c_lattice_write(const struct i2c_lattice_config *config,
			    struct i2c_lattice_data *data, struct i2c_msg *msg,
			    uint16_t addr)
{
	uint8_t *write_ptr = msg->buf;
	uint32_t bytes_send = msg->len;
	uint32_t write_data;
	int count_bytes = 1;

	if (!bytes_send)
		return -EINVAL;

	k_mutex_lock(&data->mutex, K_FOREVER);
	sys_write8(BUS_SPEED_MODE_MASK & 0x01, config->base + MODE_REG);
	sys_write8(addr_mode, config->base + MODE_REG);
	sys_write8(!trx_mode, config->base + MODE_REG);
	sys_write8(msg->len, config->base + TGT_BYTE_CNT_REG);
	sys_write8(start, config->base + CONTROL_REG);

	while (bytes_send) {
		if (bytes_send <= FIFO_DEPTH) {
			if (count_bytes > 1)
				sys_write8(repeated_start, config->base + CONTROL_REG);
			while (sys_read8(config->base + INT_STATUS1_REG) &
			       tr_cmp_int);

			sys_write8(0xFF, config->base + INT_STATUS1_REG);

			write_data = *write_ptr++;

			sys_write8(write_data, config->base + WR_DATA_REG);
		} else {
			if (count_bytes > 1)
				sys_write8(repeated_start, config->base + CONTROL_REG);
			while (sys_read8(config->base + INT_STATUS1_REG) &
			       tx_fifo_aempty_int);

			sys_write8(0xFF, config->base + INT_STATUS1_REG);

			write_data = *write_ptr++;

			sys_write8(write_data, config->base + WR_DATA_REG);
		}
		bytes_send--;
		count_bytes++;
	}

	return 0;
}

static int i2c_lattice_transfer(const struct device *dev,
				   struct i2c_msg *msgs, uint8_t num_msgs,
				   uint16_t addr)
{
	const struct i2c_lattice_config *config = dev->config;
	struct i2c_lattice_data *data = dev->data;
	int ret;

	do {
		if (msgs->flags & I2C_MSG_READ)
			ret = i2c_lattice_read(config, data, msgs, addr);
		else
			ret = i2c_lattice_write(config, data, msgs, addr);
		msgs++;
		num_msgs--;
	} while (num_msgs);

	return ret;
}

static int i2c_lattice_configure(const struct device *dev, uint32_t dev_config)
{
	const struct i2c_lattice_config *config = dev->config;

	printf("Configuring %s at %lu\n",dev->name, config->base);

	return 0;
}

static int i2c_lattice_init(const struct device *dev)
{
	const struct i2c_lattice_config *config = dev->config;
	struct i2c_lattice_data *data = dev->data;
	int error;

	error = i2c_lattice_configure(dev, I2C_MODE_CONTROLLER);

	printf("Initializing......\n");

	if (error) {
		return error;
	}

	k_mutex_init(&data->mutex);
	sys_write8(0x40 & TARGET_ADDRL_MASK, config->base + TARGET_ADDRL_REG);
	sys_write8(0x00 & TARGET_ADDRH_MASK, config->base + TARGET_ADDRH_REG);
	sys_write8(0xFA, config->base + CLK_PRESCL_REG);
	sys_write8(0x00 & CLK_PRESC_HIGH_MASK, config->base + MODE_REG);
	sys_write8(0x01, config->base + SCL_TIMEOUT_REG);
	sys_write8(0x00, config->base + INT_ENABLE2_REG);

	printf("initialized");

	return 0;
}

static DEVICE_API(i2c, i2c_lattice_driver_api) = {
	.configure = i2c_lattice_configure,
	.transfer = i2c_lattice_transfer,
};

#define CREATE_I2C_DEVICE(inst)                                  \
	static const struct i2c_lattice_config i2c_config_##inst = { \
		.base = DT_REG_ADDR(DT_INST(inst, DT_DRV_COMPAT)),                        \
	};                                                             \
	DEVICE_DT_INST_DEFINE(inst, i2c_lattice_init, NULL,                 \
			NULL,                                    \
			&i2c_config_##inst,                    \
			POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT, \
			&i2c_lattice_driver_api);
DT_INST_FOREACH_STATUS_OKAY(CREATE_I2C_DEVICE)
