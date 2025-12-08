# tool macros
CC = gcc
CFLAGS = -Wall -Wextra -O2 -pthread -Ilib -g
DBGFLAGS := -g

SRC_DIR = src
BIN_DIR = bin
LIB_DIR = lib

SOURCES = test3.c $(SRC_DIR)/randNum.c $(SRC_DIR)/threadFuncs.c

OBJECTS = $(SOURCES:.c=.o)

EXECUTABLE = $(BIN_DIR)/test

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCES)

clean:
	rm -rf $(BIN_DIR)

.PHONY: all clean