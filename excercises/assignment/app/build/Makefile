MAKEFLAGS += --no-builtin-rules
QUIET = @
SRC = ../src
BIN = ../bin
LIB_LIB = ../../lib/lib
LIB_HEAD = ../../lib/include
LIB = ../lib
HEAD = ../include
CC = gcc
CP = cp -rp
RM = rm -rf
MAKE_DIR = mkdir -p
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard $(SRC)/*.c)
OBJ = $(patsubst %.c, %.o, $(SRCS))
INC = -I $(HEAD)
TARGET = $(BIN)/app

all: install $(TARGET)

install:
	$(QUIET)$(CP) $(LIB_LIB) ..
	$(QUIET)$(CP) $(LIB_HEAD) ..

$(TARGET): $(OBJ)
	$(QUIET)$(MAKE_DIR) $(BIN)
	$(QUIET)echo "Linking into $@"
	$(QUIET)$(CC) $(CFLAGS) $^ -o $@ -L. $(LIB)/doubly.a

%.o: %.c
	$(QUIET)echo "Compiling into $@"
	$(QUIET)$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(QUIET)$(RM) $(OBJ) $(BIN) $(LIB) $(HEAD)
