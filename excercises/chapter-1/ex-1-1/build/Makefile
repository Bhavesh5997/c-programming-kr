MAKEFLAGS += --no-builtin-rules
QUIET = @
SRC = ../src
BIN = ../bin
BIN_FILE = $(BIN)/ex-1-1
CC = gcc
RM = rm -r
MAKE_DIR = mkdir -p
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard $(SRC)/*.c)
OBJ = $(patsubst %.c, %.o, $(SRCS))

all: $(BIN_FILE)

$(BIN_FILE): $(OBJ)
	$(QUIET)$(MAKE_DIR) $(BIN)
	$(QUIET)echo "Linking into $@"
	$(QUIET)$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(QUIET)echo "Compiling into $@"
	$(QUIET)$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(QUIET)$(RM) $(SRC)/*.o $(BIN)
