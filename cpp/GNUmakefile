CC := $(shell which clang || which gcc)

CFLAGS = -Wall -W -O2 -std=c99 -Wunused
CXXFLAGS = -Wall -W -O2 -std=c++11 -Wunused
LDFLAGS =

SRC = $(wildcard *.c *.cc)
HDR = $(wildcard *.h)
BUILD_DIR = bin
BIN = $(SRC:%.c=$(BUILD_DIR)/%) $(SRC:%.cc=$(BUILD_DIR)/%)

all : $(BUILD_DIR) $(BIN)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%: %.c $(HDR)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) -lstdc++

$(BUILD_DIR)/%: %.cc $(HDR)
	$(CC) $(CXXFLAGS) -o $@ $< $(LDFLAGS) -lstdc++

.PHONY: clean
clean:
	if test -d $(BUILD_DIR); then rm -r $(BUILD_DIR); fi
