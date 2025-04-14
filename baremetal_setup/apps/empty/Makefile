QUIET := @

#Compiler flags
CC := riscv32-unknown-elf-gcc
AS := riscv32-unknown-elf-as
LD := riscv32-unknown-elf-ld

#Startup
START := ../startup/

#Flags and linker script
CFLAGS := -Wall -Wextra -g3
LDFLAGS := -T ../../linker.ld
MFLAGS := -march=rv32imf -mabi=ilp32f
INC = -I../../i2c/include/

#Target
TARGET := main.elf

#Source code and drivers
APPS := $(wildcard *.c)

#Object files
OBJS :=
OBJS += $(patsubst %.c, %.o, $(APPS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(QUIET)echo "Linking $@"
	$(QUIET)$(LD) -g $(START)/*.o $(LDFLAGS) $^ -o $@

%.o: %.c
	$(QUIET)echo "Compiling $<"
	$(QUIET)$(CC) $(MFLAGS) $(CFLAGS) $(INC) -c $< -o $@

.PHONY : clean

clean:
	$(QUIET)rm -rf $(TARGET) $(OBJS)
