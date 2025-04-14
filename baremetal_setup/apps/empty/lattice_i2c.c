#include <errno.h>
#include <stdint.h>
#include "lattice_i2c.h"

void reg_write(uint32_t addr, uint8_t value)
{
	*((volatile uint32_t*)addr) = value;
}

uint8_t reg_read(uint32_t addr)
{
	return *((volatile uint32_t*)addr);
}

/* Configure required registers before starting an I2C transaction */
void I2C_init(void)
{
	reg_write(CLK_PRESCL_REG, 0xFA);
	reg_write(SCL_TIMEOUT_REG, 0x01);
	reg_write(INT_ENABLE1_REG, 0xFF);
	reg_write(INT_ENABLE2_REG, 0xFF);
}

/* Read operation from the slave device */
int I2C_read(uint8_t addr, uint8_t* data, uint8_t len)
{
	if (!len || !data)
		return -EIO;

	/* Configure 7 bit address */
	reg_write(TARGET_ADDRL_REG, addr);
	reg_write(TARGET_ADDRH_REG, 0x00);
	/* Configure fast bus speed mode */
	reg_write(MODE_REG, (BUS_SPEED_MODE_MASK & 0x40));
	/* Configure 7 bit addressing mode */
	reg_write(MODE_REG, (reg_read(MODE_REG) & ~(1 << 5)));
	/* Set trx_mode bit for read operation */
	reg_write(MODE_REG, (reg_read(MODE_REG) | 1 << 3));
	/* Specify the number of bytes */
	reg_write(TGT_BYTE_CNT_REG, len);
	/* Starts an I2C transaction */
	reg_write(CONTROL_REG, 1);

	int bytes_left = len, count_bytes = 1, delay, i = 0;

	while (bytes_left) {
		delay = 10;

		while ((reg_read(INT_STATUS2_REG) & (1 << 3)) && delay--);
		reg_write(INT_STATUS2_REG, 0xFF);

		if (delay == 0)
			return -ENXIO;

		delay = 10;

		if (bytes_left <= FIFO_DEPTH) {
			/* Repeated start */
			if (count_bytes > 1)
				reg_write(CONTROL_REG, 1 << 3);
			/* Transfer Complete Interrupt Status */
			while (!(reg_read(INT_STATUS1_REG) >> 7) && delay--);
			if (delay == 0)
				return -EAGAIN;

			reg_write(INT_STATUS1_REG, 0xFF);
			data[i] = reg_read(RD_DATA_REG);
		} else {
			/* Repeated start */
			if (count_bytes > 1)
				reg_write(CONTROL_REG, 1 << 3);
			/* Receive FIFO Almost Full Interrupt Status */
			while (!(reg_read(INT_STATUS1_REG) >> 1) && delay--);
			if (delay == 0)
				return -EAGAIN;

			reg_write(INT_STATUS1_REG, 0xFF);
			data[i] = reg_read(RD_DATA_REG);
		}
		bytes_left--;
		count_bytes++;
		i++;
	}

	return 0;
}

/* Write operation to the slave device */
int I2C_send(uint8_t addr, uint8_t* data, uint8_t len)
{
	if (!len || !data)
		return -EIO;

	/* Configure 7 bit address */
	reg_write(TARGET_ADDRL_REG, addr);
	reg_write(TARGET_ADDRH_REG, 0x00);
	/* Configure fast bus speed mode */
	reg_write(MODE_REG, (BUS_SPEED_MODE_MASK & 0x40));
	/* Configure 7 bit addressing mode */
	reg_write(MODE_REG, (reg_read(MODE_REG) & ~(1 << 5)));
	/* Clear trx_mode bit for write operation */
	reg_write(MODE_REG, (reg_read(MODE_REG) & ~(1 << 3)));
	/* Specify the number of bytes */
	reg_write(TGT_BYTE_CNT_REG, len);
	/* Starts an I2C transaction */
	reg_write(CONTROL_REG, 0x01);

	int bytes_left = len, count_bytes = 1, delay;
	uint32_t write_data;

	while (bytes_left) {
		delay = 10;

		while ((reg_read(INT_STATUS2_REG) & (1 << 3)) && delay--);
		reg_write(INT_STATUS2_REG, 0xFF);

		if (delay == 0)
			return -ENXIO;
		delay = 10;

		if (bytes_left <= FIFO_DEPTH) {
			/* Repeated start */
			if (count_bytes > 1)
				reg_write(CONTROL_REG, 1 << 3);
			/* Transfer Complete Interrupt Status */
			while (!(reg_read(INT_STATUS1_REG) >> 7) && delay--);
			if (delay == 0)
				return -EAGAIN;

			reg_write(INT_STATUS1_REG, 0xFF);
			write_data = *data++;
			reg_write(WR_DATA_REG, write_data);
		} else {
			/* Repeated start */
			if (count_bytes > 1)
				reg_write(CONTROL_REG, 1 << 3);
			/* Transmit FIFO Almost Full Interrupt Status */
			while (!(reg_read(INT_STATUS1_REG) >> 4) && delay--);
			if (delay == 0)
				return -EAGAIN;

			reg_write(INT_STATUS1_REG, 0xFF);
			write_data = *data++;
			reg_write(WR_DATA_REG, write_data);
		}
		bytes_left--;
		count_bytes++;
	}

	return 0;
}
