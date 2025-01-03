MAKEFLAGS += --no-builtin-rules
QUIET = @
SRC = ../src
BIN = ../bin
BIN_FILE = $(BIN)/ex-5-4
CC = gcc
RM = rm -rf
MAKE_DIR = mkdir -p
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard $(SRC)/*.c)
OBJ = $(patsubst %.c, %.o, $(SRCS))
INC = -I../include

all: $(BIN_FILE)

$(BIN_FILE): $(OBJ)
	$(QUIET)$(MAKE_DIR) $(BIN)
	$(QUIET)echo "Linking into $@"
	$(QUIET)$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(QUIET)echo "Compiling into $@"
	$(QUIET)$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(QUIET)$(RM) $(SRC)/*.o $(BIN)
