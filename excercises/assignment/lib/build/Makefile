MAKEFLAGS += --no-builtin-rules
QUIET = @
SRC = ../src
LIB = ../lib
AR = ar rcs
CC = gcc
RM = rm -rf
MAKE_DIR = mkdir -p
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard $(SRC)/*.c)
OBJ = $(patsubst %.c, %.o, $(SRCS))
INC = -I../include
DOX_DIC = ../docs
DOX = doxygen $(DOX_DIC)
HTML = ../docs/html
TARGET = $(LIB)/doubly.a

all: $(TARGET) dox

$(TARGET): $(OBJ)
	$(QUIET)$(MAKE_DIR) $(LIB)
	$(QUIET)echo "Linking into $@"
	$(QUIET)$(AR) $@ $^

dox:
	$(QUIET)$(DOX)/Doxyfile

%.o: %.c
	$(QUIET)echo "Compiling into $@"
	$(QUIET)$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(QUIET)$(RM) $(OBJ) $(LIB) $(HTML)
