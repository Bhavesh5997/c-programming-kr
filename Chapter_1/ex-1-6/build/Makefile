SRC = ../src
BIN = ../bin/ex-1-6
CC = gcc
RM = rm
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard $(SRC)/*.c)
OBJ = $(patsubst %.c, %.o, $(SRCS))
QUITE = @

all: $(BIN)

$(BIN): $(OBJ)
	$(QUITE)$(CC) $(CFLAGS) $< -o $@

$(OBJ): $(SRCS)
	$(QUITE)$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(QUITE)$(RM) -r $(SRC)/*.o $(BIN)
