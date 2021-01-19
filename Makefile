BASENAME = banjo
VERSION  := us.v10

SUBCODE := core1 core2 MM TTC CC BGS FP lair GV CCW RBB MMM SM fight cutscenes
	
BUILD_DIR = build
SUB_BUILD_DIRS = $(foreach submod,$(SUBCODE), $(BUILD_DIR)/$(submod))

ASM_DIRS  = asm
BIN_DIRS  = bin
SRC_DIRS  = src

SPLIT_DIR := $(BUILD_DIR)/split

ASM_PROCESSOR_DIR := tools/asm-processor

S_FILES   = $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
C_FILES   = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
H_FILES   = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.h))
BIN_FILES = $(foreach dir,$(BIN_DIRS),$(wildcard $(dir)/*.bin))

O_FILES := $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file:.s=.o)) \
           $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file:.c=.o)) \
           $(foreach file,$(BIN_FILES),$(BUILD_DIR)/$(file:.bin=.o))

# Files requiring pre/post-processing
GREP := grep -rl
GLOBAL_ASM_C_FILES = $(shell $(GREP) GLOBAL_ASM $(SRC_DIR) </dev/null)
GLOBAL_ASM_O_FILES = $(foreach file,$(GLOBAL_ASM_C_FILES),$(BUILD_DIR)/$(file:.c=.o))

TARGET = $(BUILD_DIR)/$(BASENAME).$(VERSION)
LD_SCRIPT = $(BASENAME).ld

SUB_TARGET := $(foreach submod,$(SUBCODE), $(BUILD_DIR)/$(submod)/$(submod).$(VERSION))
SUB_TARGET_BIN := $(foreach target,$(SUB_TARGET), $(target).bin)
SUB_TARGET_ELF := $(foreach target,$(SUB_TARGET), $(target).elf)
SUB_TARGET_LD_SCRIPT := $(foreach submod, $(SUBCODE), $(submod).ld)
SUB_LD_SCRIPT := $(foreach submod,$(SUBCODE), $(BUILD_DIR)/$(submod)/$(submod).ld)

SUBCODE_SRC_BIN := $(foreach submod,$(SUBCODE), $(BIN_DIRS)/$(submod).$(VERSION).rzip.bin)
SUBCODE_SRC := $(foreach submod,$(SUBCODE), $(BIN_DIRS)/$(submod).$(VERSION).bin)
SUBCODE_TARGET := $(foreach submod,$(SUBCODE), $(BUILD_DIR)/$(submod).$(VERSION).bin)
SUBCODE_TARGET_BIN := $(foreach submod,$(SUBCODE), $(BUILD_DIR)/$(submod).$(VERSION).rzip.bin)

CROSS = mips-linux-gnu-
AS = $(CROSS)as
CPP = cpp
LD = $(CROSS)ld
OBJDUMP = $(CROSS)objdump
OBJCOPY = $(CROSS)objcopy
PYTHON = python3
N64SPLAT = $(PYTHON) tools/n64splat/split.py

CC = ido/ido5.3_recomp/cc

OPT_FLAGS := -O2 -g3
MIPSBIT := -mips2 -o32

INCLUDE_CFLAGS := -I . -I include -I include/2.0L -I include/2.0L/PR -I include/libc -I src/libultra/os -I src/libultra/audio

ASFLAGS = -EB -mtune=vr4300 -march=vr4300 -mabi=32 -I include

CFLAGS := -G 0 -Xfullwarn -Xcpluscomm -signed -g -nostdinc -non_shared -Wab,-r4300_mul
CFLAGS += -D_LANGUAGE_C -D_FINALROM -DF3DEX_GBI
CFLAGS += $(INCLUDE_CFLAGS)

LDFLAGS = -T $(BUILD_DIR)/$(LD_SCRIPT) -Map $(TARGET).map -T symbol_addrs.$(VERSION).txt -T undefined_syms.$(VERSION).txt -T undefined_syms_auto.txt -T undefined_funcs_auto.txt  --no-check-sections

### Targets

default: main

all: dirs $(SUBCODE) main

main: dirs main_extract
	$(MAKE) $(TARGET).z64

dirs:
	$(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(BIN_DIRS) ,$(shell mkdir -p build/$(dir)))

clean:
	rm -rf asm
	rm -rf bin
	rm -rf build

extract: $(foreach submod, $(SUBCODE), $(submod)_extract)

%_extract: bin/%.$(VERSION).bin
	$(N64SPLAT) $< subyaml/$*.$(VERSION).yaml .

main_extract: 
	$(N64SPLAT) baserom.$(VERSION).z64 $(BASENAME).$(VERSION).yaml .

%_verify: $(BUILD_DIR)/%.$(VERSION).bin $(BUILD_DIR)/%.$(VERSION).sha1
	@echo "$$(awk '{print $$1}' $(word 2,$^))  $<" | sha1sum --check


verify: $(TARGET).z64 $(TARGET).sha1
	@echo "$$(awk '{print $$1}' $(word 2,$^))  $<" | sha1sum --check

decompress: $(SUBCODE_SRC)

### Tools
bk_inflate_code: 
	cd toos/bk_tools && make $@


### Recipes

$(BUILD_DIR)/$(LD_SCRIPT): $(LD_SCRIPT)
	$(CPP) -P -DBUILD_DIR=$(BUILD_DIR) -o $@ $<

$(TARGET).elf: $(O_FILES) $(BUILD_DIR)/$(LD_SCRIPT) #add 
	@$(LD) $(LDFLAGS) -o $@

$(BUILD_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(OPT_FLAGS) $(MIPSBIT) -o $@ $<

$(BUILD_DIR)/%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: %.bin
	$(LD) -r -b binary -o $@ $<

$(TARGET).sha1: $(patsubst build%, bin%, $(TARGET)).bin
	sha1sum $< > $@

$(BIN_DIRS)/$(BASENAME).$(VERSION).bin:
	cp baserom.$(VERSION).z64 $@

$(TARGET).bin: $(TARGET).elf $(TARGET).sha1
	$(OBJCOPY) $(OBJCOPYFLAGS) -O binary $< $@
	@echo "$$(awk '{print $$1}' $(TARGET).sha1)  $@" | sha1sum --check

$(TARGET).z64: $(TARGET).bin
	@cp $< $@

# decompress
$(SUBCODE_SRC): bin/%.bin : bin/%.rzip.bin 
	./tools/bk_tools/bk_inflate_code $< $@

# extract
bin/%.rzip.bin: $(BASENAME).$(VERSION).yaml
	$(N64SPLAT) baserom.$(VERSION).z64 $(BASENAME).$(VERSION).yaml .
	#make decompress

#TODO compress code
#compress code
#build/%.rzip.bin: build/%.bin
#	./tools/bk_tools/bk_deflate_code $< $@
#build/%.rzip.bin: build/%.bin

#build/%.bin: bin/%.bin
#	cp $< $@

ifndef PERMUTER
$(GLOBAL_ASM_O_FILES): $(BUILD_DIR)/%.o: %.c include/variables.h include/structs.h include/functions.h
	$(PYTHON) $(ASM_PROCESSOR_DIR)/asm_processor.py $(OPT_FLAGS) $< > $(BUILD_DIR)/$<
	$(CC) -c -32 $(CFLAGS) $(OPT_FLAGS) $(LOOP_UNROLL) $(MIPSBIT) -o $@ $(BUILD_DIR)/$<
	$(PYTHON) $(ASM_PROCESSOR_DIR)/asm_processor.py $(OPT_FLAGS) $< --post-process $@ \
		--assembler "$(AS) $(ASFLAGS)" --asm-prelude $(ASM_PROCESSOR_DIR)/prelude.s
endif


$(BUILD_DIR)/%.rzip.bin: $(BIN_DIRS)/%.rzip.bin
	cp $< $@

%_fast : 
	$(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(BIN_DIRS) ,$(shell mkdir -p build/$(dir)/$*))
	make $(BUILD_DIR)/$*.$(VERSION).bin TARGET=$(BUILD_DIR)/$*.$(VERSION) ASM_DIRS=$(ASM_DIRS)/$* BIN_DIRS=$(BIN_DIRS)/$* SRC_DIRS=$(SRC_DIRS)/$* LD_SCRIPT=$*.ld

$(SUBCODE): % : %_extract
	$(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(BIN_DIRS) ,$(shell mkdir -p build/$(dir)/$@))
	make $(BUILD_DIR)/$@.$(VERSION).bin TARGET=$(BUILD_DIR)/$@.$(VERSION) ASM_DIRS=$(ASM_DIRS)/$@ BIN_DIRS=$(BIN_DIRS)/$@ SRC_DIRS=$(SRC_DIRS)/$@ LD_SCRIPT=$@.ld


# settings
.PHONY: all clean default decompress %_verify verify %_extract $(SUBCODE) bk_inflate_code dirs main_extract
SHELL = /bin/bash -e -o pipefail
