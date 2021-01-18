BASENAME := core1

BUILD_DIR = build
VERSION  := us.v10


ASM_DIRS  = asm
BIN_DIRS  = bin
SRC_DIRS  = src

SPLIT_DIR := $(BUILD_DIR)/split

ASM_PROCESSOR_DIR := ../tools/asm-processor

S_FILES   = $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
C_FILES   = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
H_FILES   = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.h))
BIN_FILES = $(foreach dir,$(BIN_DIRS),$(wildcard $(dir)/*.bin))

O_FILES := $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file:.s=.o)) \
           $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file:.c=.o)) \
           $(foreach file,$(BIN_FILES),$(BUILD_DIR)/$(file:.bin=.o))

# Files requiring pre/post-processing
GREP := grep -rl
GLOBAL_ASM_C_FILES := $(shell $(GREP) GLOBAL_ASM $(SRC_DIR) </dev/null)
GLOBAL_ASM_O_FILES := $(foreach file,$(GLOBAL_ASM_C_FILES),$(BUILD_DIR)/$(file:.c=.o))

TARGET = $(BUILD_DIR)/$(BASENAME).$(VERSION)
LD_SCRIPT = $(BASENAME).ld

CROSS = mips-linux-gnu-
AS = $(CROSS)as
CPP = cpp
LD = $(CROSS)ld
OBJDUMP = $(CROSS)objdump
OBJCOPY = $(CROSS)objcopy
PYTHON = python3

CC = ../ido/ido7.1_recomp/cc

OPT_FLAGS := -O2 -g3
MIPSBIT := -mips2 -o32

INCLUDE_CFLAGS := -I . -I include -I include/2.0L -I include/2.0L/PR -I include/libc -I src/libultra/os -I src/libultra/audio

ASFLAGS = -EB -mtune=vr4300 -march=vr4300 -mabi=32 -I include

CFLAGS := -G 0 -Xfullwarn -Xcpluscomm -signed -g -nostdinc -non_shared -Wab,-r4300_mul
CFLAGS += -D_LANGUAGE_C -D_FINALROM -DF3DEX_GBI
CFLAGS += $(INCLUDE_CFLAGS)

LDFLAGS = -T $(BUILD_DIR)/$(LD_SCRIPT) -Map $(TARGET).map -T undefined_syms.$(VERSION).txt -T undefined_syms_auto.txt -T undefined_funcs_auto.txt  --no-check-sections

### Targets

default: all

all: dirs $(TARGET).bin verify

dirs:
	$(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(BIN_DIRS) ,$(shell mkdir -p build/$(dir)))

clean:
	rm -rf asm
	rm -rf bin
	rm -rf build

extract:
	$(PYTHON) ../tools/n64splat/split.py $(BASENAME).$(VERSION).bin $(BASENAME).$(VERSION).yaml .


verify: $(TARGET).bin
	@echo "$$(cat $(BASENAME).$(VERSION).sha1)  $(TARGET).bin" | sha1sum --check

### Recipes

$(BUILD_DIR)/$(LD_SCRIPT): $(LD_SCRIPT)
	$(CPP) -P -DBUILD_DIR=$(BUILD_DIR) -o $@ $<

$(TARGET).elf: $(O_FILES) $(BUILD_DIR)/$(LD_SCRIPT)
	@$(LD) $(LDFLAGS) -o $@

ifndef PERMUTER
$(GLOBAL_ASM_O_FILES): $(BUILD_DIR)/%.o: %.c include/variables.h include/structs.h include/functions.h
	$(PYTHON) $(ASM_PROCESSOR_DIR)/asm_processor.py $(OPT_FLAGS) $< > $(BUILD_DIR)/$<
	$(CC) -c -32 $(CFLAGS) $(OPT_FLAGS) $(LOOP_UNROLL) $(MIPSBIT) -o $@ $(BUILD_DIR)/$<
	$(PYTHON) $(ASM_PROCESSOR_DIR)/asm_processor.py $(OPT_FLAGS) $< --post-process $@ \
		--assembler "$(AS) $(ASFLAGS)" --asm-prelude $(ASM_PROCESSOR_DIR)/prelude.s
endif

$(BUILD_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(OPT_FLAGS) $(MIPSBIT) -o $@ $<

$(BUILD_DIR)/%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: %.bin
	$(LD) -r -b binary -o $@ $<

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) $(OBJCOPYFLAGS) -O binary $< $@


# settings
.PHONY: all clean default
SHELL = /bin/bash -e -o pipefail
