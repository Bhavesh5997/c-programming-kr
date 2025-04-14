#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include "lattice_i2c.h"

void delay(int count)
{
	while (count--);
}

int main(void)
{
	/* To store temparature value */
	uint8_t data[2], cmd;
	uint16_t sensor_reading, temperature;
	int ret;

	/* Initialize the i2c controller */
	I2C_init();

	cmd = HTU21D_CMD_SOFTRESET;
	I2C_send(HTU21D_ADDR, &cmd, 1);

	while (1) {
		cmd = HTU21D_CMD_TEMP_HOLD;
		I2C_send(HTU21D_ADDR, &cmd, 1);
		ret = I2C_read(HTU21D_ADDR, data, 2);

		switch (ret) {
		case -EIO:
			return -EIO;
		case -ENXIO:
			return -ENXIO;
		}

		sensor_reading = data[0] | (data[1] << 8);
		temperature =  (sensor_reading * 176)/65536 - 47;

		delay(10);
	}

	return 0;
}
