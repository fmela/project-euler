HS = ghc
HSFLAGS = -Wall
SRC = $(wildcard *.hs)
BUILD_DIR = bin
BIN = $(SRC:%.hs=$(BUILD_DIR)/%)

all : $(BUILD_DIR) $(BIN)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%: %.hs
	$(HS) $(HSFLAGS) --make $< -odir $(BUILD_DIR) -outputdir $(BUILD_DIR)

.PHONY: clean
clean:
	if test -d $(BUILD_DIR); then rm -r $(BUILD_DIR); fi
