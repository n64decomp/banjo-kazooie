BASENAME = banjo
VERSION  := us.v10

SUBCODE := core1 core2 MM TTC CC BGS FP lair GV CCW RBB MMM SM fight cutscenes

BUILD_DIR = build

ASM_DIRS  = asm
BIN_DIRS  = bin
SRC_DIRS  = src


SUB_BUILD_DIRS = $(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(BIN_DIRS), build/$(dir))
SUB_BUILD_DIRS += $(foreach subdir, $(SUBCODE), $(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(BIN_DIRS), build/$(dir)/$(subdir)/.))

SUB_BUILD_DIRS = $(SUBCODE)
SUB_BUILD_DIRS += $(foreach dir,$(CORE2_DIRS), core2/$(dir))

SPLIT_DIR := $(BUILD_DIR)/split

ASM_PROCESSOR_DIR := tools/asm-processor

TARGET = $(BUILD_DIR)/$(BASENAME).$(VERSION)



ifneq ($(TARGET), $(BUILD_DIR)/banjo.$(VERSION))
S_FILES   = $(shell find $(ASM_DIRS) -name '*.s' 2>/dev/null)
C_FILES   = $(shell find $(SRC_DIRS) -name '*.c' 2>/dev/null)
H_FILES   = $(shell find $(SRC_DIRS) -name '*.h' 2>/dev/null)
BIN_FILES = $(shell find $(BIN_DIRS) -name '*.bin' 2>/dev/null)
else
S_FILES   = $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
C_FILES   = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
H_FILES   = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.h))
BIN_FILES = $(foreach dir,$(BIN_DIRS),$(wildcard $(dir)/*.bin))
endif



O_FILES := $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file:.s=.o)) \
           $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file:.c=.o)) \
           $(foreach file,$(BIN_FILES),$(BUILD_DIR)/$(file:.bin=.o))


O_DIRS := $(sort $(dir $(O_FILES)))


# Files requiring pre/post-processing
GREP := grep -rl
GLOBAL_ASM_C_FILES := $(shell $(GREP) GLOBAL_ASM src </dev/null)
GLOBAL_ASM_O_FILES := $(foreach file,$(GLOBAL_ASM_C_FILES),$(BUILD_DIR)/$(file:.c=.o))


LD_SCRIPT = $(BASENAME).ld

SUB_TARGET := $(foreach submod,$(SUBCODE), $(BUILD_DIR)/$(submod)/$(submod).$(VERSION))
SUB_TARGET_BIN := $(foreach target,$(SUB_TARGET), $(target).bin)
SUB_TARGET_ELF := $(foreach target,$(SUB_TARGET), $(target).elf)
SUB_TARGET_LD_SCRIPT := $(foreach submod, $(SUBCODE), $(submod).ld)
SUB_LD_SCRIPT := $(foreach submod,$(SUBCODE), $(BUILD_DIR)/$(submod)/$(submod).ld)

SUBCODE_SRC_BIN := $(foreach submod,$(SUBCODE), bin/$(submod).$(VERSION).rzip.bin)
SUBCODE_SRC := $(foreach submod,$(SUBCODE), bin/$(submod).$(VERSION).bin)
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

OPT_FLAGS = -O2
MIPSBIT = -mips2

INCLUDE_CFLAGS := -I . -I include -I include/2.0L -I include/2.0L/PR -I include/libc -I src/libultra/os -I src/libultra/audio

ASFLAGS = -EB -mtune=vr4300 -march=vr4300 -mabi=32 -I include

CFLAGS = -c -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm -Xfullwarn -signed $(OPT_FLAGS) $(INCLUDE_CFLAGS) $(MIPSBIT)
# ignore compiler warnings about anonymous structs
CFLAGS += -woff 649,838

LDFLAGS = -T $(BUILD_DIR)/$(LD_SCRIPT) -Map $(TARGET).map -T symbol_addrs.core1.$(VERSION).txt -T undefined_syms.$(VERSION).txt -T undefined_syms_auto.txt -T undefined_funcs_auto.txt  --no-check-sections

### Targets

default: main

main: dirs main_extract
	@$(MAKE) --no-print-directory $(TARGET).z64
	@$(MAKE) -s verify
	@echo -e "def apply(config, args):" > diff_settings.py
	@echo -e "\tconfig[\"baseimg\"] = \"baserom.$(VERSION).z64\"" >> diff_settings.py
	@echo -e "\tconfig[\"myimg\"] = \"$(TARGET).z64\"" >> diff_settings.py
	@echo -e "\tconfig[\"mapfile\"] = \"$(TARGET).map\"" >> diff_settings.py
	@echo -e "\tconfig[\"source_directories\"] = ['src', 'include']" >> diff_settings.py
	@$(MAKE) -s progress/progress.bk_boot.csv
	@echo -n "bk_boot: "
	@$(PYTHON) tools/progress_read.py progress/progress.bk_boot.csv $(VERSION)

dirs: $(foreach dir, $(O_DIRS), $(dir).)

clean:
	rm -rf asm
	rm -rf bin
	rm -rf build
	rm -rf symbol_addrs.$(VERSION).txt

#extract
extract: $(foreach submod, $(SUBCODE), $(submod)_extract)

%_extract: bin/%.$(VERSION).bin symbol_addrs.$(VERSION).txt
	$(N64SPLAT) $< subyaml/$*.$(VERSION).yaml .

main_extract: symbol_addrs.$(VERSION).txt
	$(N64SPLAT) baserom.$(VERSION).z64 $(BASENAME).$(VERSION).yaml .

#build
all: $(SUBCODE) main
	@$(MAKE) -s progress

$(SUBCODE): % : %_extract
	@$(MAKE) --no-print-directory $@_fast
	@echo -e "def apply(config, args):" > diff_settings.py
	@echo -e "\tconfig[\"baseimg\"] = \"bin/$@.$(VERSION).bin\"" >> diff_settings.py
	@echo -e "\tconfig[\"myimg\"] = \"build/$@.$(VERSION).bin\"" >> diff_settings.py
	@echo -e "\tconfig[\"mapfile\"] = \"build/$@.$(VERSION).map\"" >> diff_settings.py
	@echo -e "\tconfig[\"source_directories\"] = ['src/$@', 'include']" >> diff_settings.py
	@echo -e "\tconfig[\"makeflags\"] = ['TARGET=$(BUILD_DIR)/$*.$(VERSION)', 'ASM_DIRS=$(ASM_DIRS)/$*', 'BIN_DIRS=$(BIN_DIRS)/$*', 'SRC_DIRS=$(SRC_DIRS)/$*', 'LD_SCRIPT=$*.ld']" >> diff_settings.py


%_fast :
	@$(MAKE) --no-print-directory $(BUILD_DIR)/$*.$(VERSION).bin TARGET=$(BUILD_DIR)/$*.$(VERSION) ASM_DIRS=$(ASM_DIRS)/$* BIN_DIRS=$(BIN_DIRS)/$* SRC_DIRS=$(SRC_DIRS)/$* LD_SCRIPT=$*.ld
	@$(MAKE) -s $(BUILD_DIR)/$*.$(VERSION).rzip.bin TARGET=$(BUILD_DIR)/$*.$(VERSION) ASM_DIRS=$(ASM_DIRS)/$* BIN_DIRS=$(BIN_DIRS)/$* SRC_DIRS=$(SRC_DIRS)/$* LD_SCRIPT=$*.ld
	@$(MAKE) -s $*_verify
	@$(MAKE) -s $*_comp_verify
	@$(MAKE) -s progress/progress.$*.csv
	@$(PYTHON) tools/progress_read.py progress/progress.$*.csv $(VERSION)


#verify
%_verify: $(BUILD_DIR)/%.$(VERSION).bin $(BUILD_DIR)/%.$(VERSION).sha1
	@echo "$$(awk '{print $$1}' $(word 2,$^))  $<" | sha1sum --check

%_comp_verify: $(BUILD_DIR)/%.$(VERSION).rzip.bin $(BUILD_DIR)/%.$(VERSION).rzip.sha1
	@echo "$$(awk '{print $$1}' $(word 2,$^))  $<" | sha1sum --check

verify: $(TARGET).z64 $(TARGET).sha1
	@echo "$$(awk '{print $$1}' $(word 2,$^))  $<" | sha1sum --check

progress: progress.csv
	@echo -n "Banjo-Kazooie: "
	@$(PYTHON) tools/progress_read.py progress.csv $(VERSION)


decompress: $(SUBCODE_SRC)

### Tools
BK_TOOLS = bk_inflate_code bk_deflate_code

tools: $(BK_TOOLS)

$(BK_TOOLS): % : ./tools/bk_tools/%

./tools/bk_tools/%:
	@cd ./tools/bk_tools/ && $(MAKE) $*


### exceptions
build/src/core1/io/%.o: OPT_FLAGS = -O1

### Recipes

%/.:
	@mkdir -p $@

$(BUILD_DIR)/$(LD_SCRIPT): $(LD_SCRIPT)
	$(CPP) -P -DBUILD_DIR=$(BUILD_DIR) -o $@ $<

LDFLAGS = -T $(BUILD_DIR)/$(LD_SCRIPT) -Map $(TARGET).map -T symbol_addrs.global.$(VERSION).txt -T symbol_addrs.core1.$(VERSION).txt -T symbol_addrs.core2.$(VERSION).txt -T undefined_syms.$(VERSION).txt -T undefined_syms_auto.txt -T undefined_funcs_auto.txt  --no-check-sections
$(BUILD_DIR)/banjo.$(VERSION).elf: LDFLAGS = -T $(BUILD_DIR)/$(LD_SCRIPT) -Map $(TARGET).map -T symbol_addrs.global.$(VERSION).txt -T undefined_syms.$(VERSION).txt -T undefined_syms_auto.txt -T undefined_funcs_auto.txt  --no-check-sections
$(BUILD_DIR)/core1.$(VERSION).elf: LDFLAGS = -T $(BUILD_DIR)/$(LD_SCRIPT) -Map $(TARGET).map -T symbol_addrs.global.$(VERSION).txt -T symbol_addrs.core2.$(VERSION).txt -T undefined_syms.$(VERSION).txt -T undefined_syms_auto.txt -T undefined_funcs_auto.txt  --no-check-sections
$(BUILD_DIR)/core2.$(VERSION).elf: LDFLAGS = -T $(BUILD_DIR)/$(LD_SCRIPT) -Map $(TARGET).map -T symbol_addrs.global.$(VERSION).txt -T symbol_addrs.core1.$(VERSION).txt -T undefined_syms.$(VERSION).txt -T undefined_syms_auto.txt -T undefined_funcs_auto.txt  --no-check-sections

$(TARGET).elf: dirs $(O_FILES) $(BUILD_DIR)/$(LD_SCRIPT) #add
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

$(TARGET).z64: $(TARGET).bin
	@cp $< $@

# decompress
$(SUBCODE_SRC): bin/%.bin : bin/%.rzip.bin ./tools/bk_tools/bk_inflate_code
	@./tools/bk_tools/bk_inflate_code $< $@

# extract
symbol_addrs.$(VERSION).txt: 
	@cat symbol_addrs.*.$(VERSION).txt > $@

bin/%.rzip.bin: $(BASENAME).$(VERSION).yaml symbol_addrs.$(VERSION).txt
	$(N64SPLAT) baserom.$(VERSION).z64 $< .

ifneq ($(TARGET), build/core1.$(VERSION))
$(TARGET).code.bin: $(TARGET).elf
	$(OBJCOPY) -O binary --only-section .code_code $< $@
else
build/core1.$(VERSION).code.bin: $(TARGET).elf
	$(OBJCOPY) -O binary --only-section .code_code --only-section .code_mips3 $< $@
endif
$(TARGET).data.bin: $(TARGET).elf
	$(OBJCOPY) -O binary --only-section .code_data $< $@

#TODO compress code
#compress code
$(TARGET).rzip.sha1: $(patsubst build%, bin%, $(TARGET)).rzip.bin
	sha1sum $< > $@

ifndef PERMUTER
$(GLOBAL_ASM_O_FILES): $(BUILD_DIR)/%.o: %.c include/variables.h include/structs.h include/functions.h
	$(PYTHON) $(ASM_PROCESSOR_DIR)/asm_processor.py $(OPT_FLAGS) $< > $(BUILD_DIR)/$<
	$(CC) -c -32 $(CFLAGS) $(OPT_FLAGS) $(LOOP_UNROLL) $(MIPSBIT) -o $@ $(BUILD_DIR)/$<
	$(PYTHON) $(ASM_PROCESSOR_DIR)/asm_processor.py $(OPT_FLAGS) $< --post-process $@ \
		--assembler "$(AS) $(ASFLAGS)" --asm-prelude $(ASM_PROCESSOR_DIR)/prelude.s
endif

$(TARGET).rzip.bin:$(TARGET).code.bin $(TARGET).data.bin $(TARGET).rzip.sha1 ./tools/bk_tools/bk_deflate_code
	cd ./tools/bk_tools/ && ./bk_deflate_code $(foreach file, $@ $< $(word 2,$^), ../../$(file))

progress.csv : $(foreach submod, $(SUBCODE), progress/progress.$(submod).csv) progress/progress.bk_boot.csv
	@cat $^ > $@

progress/progress.bk_boot.csv: progress/. $(TARGET).elf
	@$(PYTHON) tools/progress.py . build/banjo.$(VERSION).map .code_bk_boot --version $(VERSION) > $@

#PROG_CSVS = $(foreach submod, $(SUBCODE), progress/progress.$(submod).csv)
progress/progress.%.csv:  progress/. build/%.$(VERSION).elf
	@echo -n "$*: "
	@$(PYTHON) tools/progress.py . build/$*.$(VERSION).map .code_code --version $(VERSION) > $@


# settings
.PHONY: all clean dirs default decompress verify $(SUBCODE) bk_inflate_code dirs main_extract
SHELL = /bin/bash -e -o pipefail
