#ifndef ZEPHYR_I2C_LATTICE
#define ZEPHYR_I2C_LATTICE

#include <zephyr/sys/util_macro.h>

#define FIFO_DEPTH	16

enum lattice_i2c_registers {
	WR_DATA_REG = 0x00,
	RD_DATA_REG = 0x00,
	TARGET_ADDRL_REG = 0x04,
	TARGET_ADDRH_REG = 0x08,
	CONTROL_REG = 0x0C,
	TGT_BYTE_CNT_REG = 0x10,
	MODE_REG = 0x14,
	CLK_PRESCL_REG = 0x18,
	INT_STATUS1_REG = 0x1C,
	INT_ENABLE1_REG = 0x20,
	INT_SET1_REG = 0x24,
	INT_STATUS2_REG = 0x28,
	INT_ENABLE2_REG = 0x2C,
	INT_SET2_REG = 0x30,
	FIFO_STATUS_REG = 0x34,
	SCL_TIMEOUT_REG = 0x38,
};

enum lattice_i2c_target_addrl_bits {
	TARGET_ADDRL_MASK = 0x7F,
};

enum lattice_i2c_target_addrh_bits {
	TARGET_ADDRH_MASK = 0x07,
};

enum lattice_i2c_cr_bits {
	rx_fifo_reset = BIT(6),
	tx_fifo_reset = BIT(5),
	repeated_start = BIT(3),
	reset = BIT(2),
	abort = BIT(1),
	start = BIT(0),
};

enum lattice_i2c_mode_bits {
	addr_mode = BIT(5),
	trx_mode = BIT(3),
	BUS_SPEED_MODE_MASK  = 0x0C,
	CLK_PRESC_HIGH_MASK  = 0x07,
};

enum lattice_i2c_irs1_bits {
	tr_cmp_int = BIT(7),
	tx_fifo_full_int = BIT(5),
	tx_fifo_aempty_int = BIT(4),
	tx_fifo_empty_int  = BIT(3),
	rx_fifo_full_int = BIT(2),
	rx_fifo_afull_int = BIT(1),
	rx_fifo_ready_int = BIT(0),
};

enum lattice_i2c_irs2_bits {
	nack_error_int = BIT(3),
	abort_ack_int = BIT(2),
	arb_lost_int = BIT(1),
	timeout_int = BIT(0),
};

enum lattice_i2c_int_set1_bits {
	tr_cmp_set = BIT(7),
	tx_fifo_full_set = BIT(5),
	tx_fifo_aempty_set = BIT(4),
	tx_fifo_empty_set = BIT(3),
	rx_fifo_full_set = BIT(2),
	rx_fifo_afull_set = BIT(1),
	rx_fifo_ready_set = BIT(0),
};

enum lattice_i2c_int_set2_bits {
	timeout_int_set = BIT(0),
	arb_lost_int_set = BIT(1),
	abort_ack_int_set = BIT(2),
	nack_error_int_set = BIT(3),
};

enum lattice_i2c_fifo_status_bits {
	tx_fifo_aempty_status = BIT(1),
	tx_fifo_empty_status = BIT(2),
	tx_fifo_full_status = BIT(3),
	rx_fifo_ready_status = BIT(4),
	rx_fifo_afull_status = BIT(5),
	rx_fifo_empty_status = BIT(6),
	rx_fifo_full_status = BIT(7),
};

#endif
