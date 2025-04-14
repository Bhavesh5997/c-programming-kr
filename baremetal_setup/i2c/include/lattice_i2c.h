#ifndef _LATTICE_I2C_H
#define _LATTICE_I2C_H

#define FIFO_DEPTH		16
#define BASE	 		0xF0020000
#define HTU21D_ADDR		0x40
#define HTU21D_CMD_TEMP_HOLD	0xE3
#define HTU21D_CMD_SOFTRESET	0xFE

enum lattice_i2c_registers {
	WR_DATA_REG = BASE + 0x00,
	RD_DATA_REG = BASE + 0x00,
	TARGET_ADDRL_REG = BASE + 0x04,
	TARGET_ADDRH_REG = BASE + 0x08,
	CONTROL_REG = BASE + 0x0C,
	TGT_BYTE_CNT_REG = BASE + 0x10,
	MODE_REG = BASE + 0x14,
	CLK_PRESCL_REG = BASE + 0x18,
	INT_STATUS1_REG = BASE + 0x1C,
	INT_ENABLE1_REG = BASE + 0x20,
	INT_SET1_REG = BASE + 0x24,
	INT_STATUS2_REG = BASE + 0x28,
	INT_ENABLE2_REG = BASE + 0x2C,
	INT_SET2_REG = BASE + 0x30,
	FIFO_STATUS_REG = BASE + 0x34,
	SCL_TIMEOUT_REG = BASE + 0x38,
};

enum lattice_i2c_mode {
	BUS_SPEED_MODE_MASK  = 0xC0,
	CLK_PRESC_HIGH_MASK  = 0x07,
};

void I2C_init(void);
int I2C_read(uint8_t addr, uint8_t* data, uint8_t len);
int I2C_send(uint8_t addr, uint8_t* data, uint8_t len);

#endif
