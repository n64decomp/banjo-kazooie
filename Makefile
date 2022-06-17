### Configuration ###
BASENAME := banjo
VERSION  ?= us.v10

IN_CFLAGS ?= -DCODE2_CODE_CRC2=0 -DCODE2_DATA_CRC2=0
### Tools ###

# System tools
MKDIR := mkdir
CP := cp
CD := cd
RM := rm
CAT := cat
DIFF := diff

# Build tools
CROSS   := mips-linux-gnu-
CC      := ido/ido5.3_recomp/cc
CPP     := cpp
GCC     := $(CROSS)gcc
AS      := $(CROSS)as
LD      := $(CROSS)ld -b elf32-tradbigmips
OBJDUMP := $(CROSS)objdump
OBJCOPY := $(CROSS)objcopy
PYTHON  := python3
GREP    := grep -rl
SPLAT   := $(PYTHON) tools/n64splat/split.py
PRINT   := printf
PATCH_LIB_MATH    := tools/patch_libultra_math
ASM_PROCESSOR_DIR := tools/asm-processor
BK_TOOLS          := tools/bk_tools
BK_CRC            := tools/bk_crc/bk_crc
BK_INFLATE        := $(BK_TOOLS)/bk_inflate_code
BK_DEFLATE        := $(BK_TOOLS)/bk_deflate_code
BK_ASSET_TOOL     := tools/bk_asset_tool/bk_asset_tool
ASM_PROCESSOR     := $(PYTHON) $(ASM_PROCESSOR_DIR)/asm_processor.py
SPLAT_INPUTS      := $(PYTHON) tools/splat_inputs.py
PROGRESS          := $(PYTHON) tools/progress.py
PROGRESS_READ     := $(PYTHON) tools/progress_read.py

### Files and Directories ###

# Inputs
OVERLAYS := core1 core2 MM TTC CC BGS FP lair GV CCW RBB MMM SM fight cutscenes

# Creates a list of all the source files for the given overlay (e.g. BGS_C_SRCS)
# Appends that list to OVERLAY_C_FILES
define get_overlay_sources
  $(1)_C_SRCS      := $(filter $(SRC_ROOT)/$(1)/%,$(ALL_C_SRCS))
  $(1)_ASM_SRCS    := $(filter $(ASM_ROOT)/$(1)/%,$(ALL_ASM_SRCS))
  $(1)_BINS        := $(filter $(BIN_ROOT)/$(1)/%,$(ALL_BINS))
  OVERLAY_C_SRCS   += $$($(1)_C_SRCS)
  OVERLAY_ASM_SRCS += $$($(1)_ASM_SRCS)
  OVERLAY_BINS     += $$($(1)_BINS)
  # Overlay inputs
  $(1)_NEW_FILES := $$(filter $(BIN_ROOT)/$(1)/%, $(NEW_BINS)) $$(filter $(SRC_ROOT)/$(1)/%, $(NEW_C_SRCS)) $$(filter $(ASM_ROOT)/$(1)/%, $(NEW_ASM_SRCS)) $$(filter $(ASM_ROOT)/data/$(1)/%, $(NEW_ASM_SRCS))
  OVERLAY_NEW_FILES += $$($(1)_NEW_FILES)
endef

# Source files
SRC_ROOT          := src
ASM_ROOT          := asm
BIN_ROOT          := bin
ASSET_ROOT        := assets
SUBYAML           := subyaml
NONMATCHINGS      := nonmatchings
NONMATCHING_DIR   := $(ASM_ROOT)/$(NONMATCHINGS)
BUILD_ROOT        := build
BUILD_DIR         := $(BUILD_ROOT)/$(VERSION)
ALL_ASSET_FILES   := $(shell find $(ASSET_ROOT) -type f -iname '*.*' 2> /dev/null)
ALL_C_SRCS        := $(shell find $(SRC_ROOT) -type f -iname '*.c' 2> /dev/null)
ALL_ASM_SRCS      := $(filter-out $(ASM_ROOT)/$(NONMATCHINGS), $(shell find $(ASM_ROOT) -name $(NONMATCHINGS) -prune -o -iname '*.s' 2> /dev/null))
ALL_BINS          := $(shell find $(BIN_ROOT) -type f -iname '*.bin' 2> /dev/null)
# Files referenced in the splat files
YAML_CALL := $(SPLAT_INPUTS) $(BASENAME).$(VERSION).yaml $(addprefix $(SUBYAML)/, $(addsuffix .$(VERSION).yaml, $(OVERLAYS)))
YAML_SRCS   := $(shell $(SPLAT_INPUTS) $(BASENAME).$(VERSION).yaml $(addprefix $(SUBYAML)/, $(addsuffix .$(VERSION).yaml, $(OVERLAYS))))
YAML_C_SRCS := $(filter %.c, $(YAML_SRCS))
YAML_ASM_SRCS := $(filter %.s, $(YAML_SRCS))
YAML_BINS := $(filter %.bin, $(YAML_SRCS))
# Files that need to be extracted
NEW_C_SRCS := $(filter-out $(ALL_C_SRCS), $(YAML_C_SRCS))
NEW_ASM_SRCS := $(filter-out $(ALL_ASM_SRCS), $(YAML_ASM_SRCS))
NEW_BINS := $(filter-out $(ALL_BINS), $(YAML_BINS))
NEW_FILES := $(NEW_C_SRCS) $(NEW_ASM_SRCS) $(NEW_BINS)
$(foreach overlay,$(OVERLAYS),$(eval $(call get_overlay_sources,$(overlay))))
# Files for the rom itself
MAIN_C_SRCS   := $(filter-out $(OVERLAY_C_SRCS),$(ALL_C_SRCS))
MAIN_ASM_SRCS := $(filter-out $(OVERLAY_ASM_SRCS),$(ALL_ASM_SRCS))
MAIN_BINS     := $(filter-out $(OVERLAY_BINS),$(ALL_BINS))
# Files that need to be extracted for the rom itself
MAIN_NEW_FILES := $(filter-out $(OVERLAY_NEW_FILES), $(NEW_FILES))
# Any source files that have GLOBAL_ASM in them or do not exist before splitting
GLOBAL_ASM_C_SRCS := $(shell $(GREP) GLOBAL_ASM $(SRC_ROOT) </dev/null) $(NEW_C_SRCS)
CORE2_CODE_CRC_C_SRCS := $(shell $(GREP) CORE2_CODE_CRC2 $(SRC_ROOT) </dev/null)
CORE2_DATA_CRC_C_SRCS := $(shell $(GREP) CORE2_DATA_CRC2 $(SRC_ROOT) </dev/null)


# Build folders
C_DIRS         := $(sort $(dir $(ALL_C_SRCS) $(NEW_C_SRCS)))
ASM_DIRS       := $(sort $(dir $(ALL_ASM_SRCS) $(NEW_ASM_SRCS)))
BIN_DIRS       := $(sort $(dir $(ALL_BINS) $(NEW_BINS)))
C_BUILD_DIRS   := $(addprefix $(BUILD_DIR)/,$(C_DIRS))
ASM_BUILD_DIRS := $(addprefix $(BUILD_DIR)/,$(ASM_DIRS))
BIN_BUILD_DIRS := $(addprefix $(BUILD_DIR)/,$(BIN_DIRS))
ALL_DIRS       := $(C_BUILD_DIRS) $(ASM_BUILD_DIRS) $(BIN_BUILD_DIRS) $(BUILD_DIR)

# Build files
BASEROM           := baserom.$(VERSION).z64
C_OBJS            := $(addprefix $(BUILD_DIR)/,$(ALL_C_SRCS:.c=.c.o))
GLOBAL_ASM_C_OBJS := $(addprefix $(BUILD_DIR)/,$(GLOBAL_ASM_C_SRCS:.c=.c.o))
CORE2_CODE_CRC_C_OBJS := $(addprefix $(BUILD_DIR)/,$(CORE2_CODE_CRC_C_SRCS:.c=.c.o))
CORE2_DATA_CRC_C_OBJS := $(addprefix $(BUILD_DIR)/,$(CORE2_DATA_CRC_C_SRCS:.c=.c.o))
# TODO remove this when all files in GLOBAL_ASM_C_OBJS are matched
GLOBAL_ASM_C_OBJS := $(filter-out $(CORE2_DATA_CRC_C_OBJS),$(GLOBAL_ASM_C_OBJS))
C_DEPS            := $(C_OBJS:.o=.d)
ASM_OBJS          := $(addprefix $(BUILD_DIR)/,$(ALL_ASM_SRCS:.s=.s.o) $(NEW_ASM_SRCS:.s=.s.o))
BIN_OBJS          := $(addprefix $(BUILD_DIR)/,$(ALL_BINS:.bin=.bin.o) $(NEW_BINS:.bin=.bin.o))
Z64               := $(addprefix $(BUILD_DIR)/,$(BASENAME).$(VERSION).z64)
ELF               := $(Z64:.z64=.elf)
LD_SCRIPT         := $(BASENAME).ld
BK_BOOT_LD_SCRIPT := bk_boot.ld
OVERLAY_ELFS      := $(addprefix $(BUILD_DIR)/,$(addsuffix .elf,$(OVERLAYS)))
OVERLAY_CODE_BINS := $(OVERLAY_ELFS:.elf=.code)
OVERLAY_DATA_BINS := $(OVERLAY_ELFS:.elf=.data)
OVERLAY_BINS      := $(addprefix $(BUILD_DIR)/,$(addsuffix .$(VERSION).bin,$(OVERLAYS)))
ASSET_BIN         := $(BUILD_DIR)/assets.bin
OVERLAY_RZIPS     := $(addprefix $(BIN_ROOT)/,$(addsuffix .$(VERSION).rzip.bin,$(OVERLAYS)))
OVERLAY_RZIP_OUTS := $(addprefix $(BUILD_DIR)/,$(addsuffix .rzip.bin,$(OVERLAYS)))
OVERLAY_RZIP_OBJS := $(addprefix $(BUILD_DIR)/$(BIN_ROOT)/,$(addsuffix .$(VERSION).rzip.bin.o,$(OVERLAYS)))
CRC_OBJS          := $(BUILD_DIR)/$(BIN_ROOT)/crc.bin.o
ASSET_OBJS        := $(BUILD_DIR)/$(BIN_ROOT)/assets.bin.o
BIN_OBJS          := $(filter-out $(OVERLAY_RZIP_OBJS) $(CRC_OBJS) $(ASSET_OBJS),$(BIN_OBJS))
ALL_OBJS          := $(C_OBJS) $(ASM_OBJS) $(BIN_OBJS) $(OVERLAY_RZIP_OBJS) $(CRC_OBJS)
SYMBOL_ADDRS      := symbol_addrs.$(VERSION).txt
SYMBOL_ADDR_FILES := $(filter-out $(SYMBOL_ADDRS), $(wildcard symbol_addrs.*.$(VERSION).txt))
MIPS3_OBJS        := $(BUILD_DIR)/$(SRC_ROOT)/done/ll.c.o $(BUILD_DIR)/$(SRC_ROOT)/core1/done/ll.c.o
# Object files for the rom itself
MAIN_C_OBJS       := $(addprefix $(BUILD_DIR)/,$(MAIN_C_SRCS:.c=.c.o))
MAIN_ASM_OBJS     := $(addprefix $(BUILD_DIR)/,$(MAIN_ASM_SRCS:.s=.s.o))
MAIN_BIN_OBJS     := $(addprefix $(BUILD_DIR)/,$(MAIN_BINS:.bin=.bin.o))
MAIN_OBJS         := $(MAIN_C_OBJS) $(MAIN_ASM_OBJS) $(MAIN_BIN_OBJS)
# Includes the build artifacts of any files to be extracted
MAIN_ALL_OBJS := $(MAIN_OBJS) $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(MAIN_NEW_FILES)))

# Progress files
MAIN_PROG_CSV     := progress/progress.bk_boot.csv
MAIN_PROG_SVG     := progress/progress_bk_boot.svg
TOTAL_PROG_CSV    := progress/progress.total.csv
TOTAL_PROG_SVG    := progress/progress_total.svg
OVERLAY_PROG_CSVS := $(addprefix progress/progress., $(addsuffix .csv, $(OVERLAYS)))
OVERLAY_PROG_SVGS := $(addprefix progress/progress_, $(addsuffix .svg, $(OVERLAYS)))

# Creates a list of all the object files for the given overlay
define get_overlay_objects
  $(1)_C_OBJS      := $(addprefix $(BUILD_DIR)/,$($(1)_C_SRCS:.c=.c.o))
  $(1)_ASM_OBJS    := $(addprefix $(BUILD_DIR)/,$($(1)_ASM_SRCS:.s=.s.o))
  $(1)_BIN_OBJS    := $(addprefix $(BUILD_DIR)/,$($(1)_BINS:.bin=.bin.o))
  $(1)_OBJS        := $$($(1)_C_OBJS) $$($(1)_ASM_OBJS) $$($(1)_BIN_OBJS)
  $(1)_ALL_OBJS    := $$($(1)_OBJS) $$(addprefix $(BUILD_DIR)/, $$(addsuffix .o, $$($(1)_NEW_FILES)))
  OVERLAY_OBJS     += $$($(1)_OBJS)
endef

$(foreach overlay,$(OVERLAYS),$(eval $(call get_overlay_objects,$(overlay))))

### Functions ###

# Colorful text printing
NO_COL  := \033[0m
RED     := \033[0;31m
GREEN   := \033[0;32m
BLUE    := \033[0;34m
YELLOW  := \033[0;33m
BLINK   := \033[33;5m

# Print message with zero arguments (i.e. message)
define print0
  @$(PRINT) "$(GREEN)$(1)$(NO_COL)\n"
endef

# Print message with one argument (i.e. message arg)
define print1
  @$(PRINT) "$(GREEN)$(1) $(BLUE)$(2)$(NO_COL)\n"
endef

# Print message with two arguments (i.e. message arg1 -> arg2)
define print2
  @$(PRINT) "$(GREEN)$(1) $(YELLOW)$(2)$(GREEN) -> $(BLUE)$(3)$(NO_COL)\n"
endef

### Flags ###

# Build tool flags
CFLAGS         := -c -Wab,-r4300_mul -non_shared -G 0 -Xfullwarn -Xcpluscomm $(OPT_FLAGS) $(MIPSBIT) -D_FINALROM -DF3DEX_GBI
CFLAGS         += -woff 649,654,838,807
CFLAGS         += $(IN_CFLAGS)
CPPFLAGS       := -D_FINALROM -DN_MICRO
INCLUDE_CFLAGS := -I . -I include -I include/2.0L -I include/2.0L/PR
OPT_FLAGS      := -O2 
MIPSBIT        := -mips2
ASFLAGS        := -EB -mtune=vr4300 -march=vr4300 -mabi=32 -I include
GCC_ASFLAGS    := -c -x assembler-with-cpp -mabi=32 -ffreestanding -mtune=vr4300 -march=vr4300 -mfix4300 -G 0 -O -mno-shared -fno-PIC -mno-abicalls
LDFLAGS_COMMON := -T symbol_addrs.core1.$(VERSION).txt -T symbol_addrs.core2.$(VERSION).txt -T symbol_addrs.global.$(VERSION).txt -T undefined_syms.$(VERSION).txt -T undefined_syms.libultra.txt --no-check-sections --accept-unknown-input-arch
LDFLAGS        := -T $(LD_SCRIPT) -Map $(ELF:.elf=.map) --no-check-sections --accept-unknown-input-arch -T undefined_syms.libultra.txt
BINOFLAGS      := -I binary -O elf32-tradbigmips

### Rules ###

# Default target, all
all: verify

# Shows progress for all overlays, boot, and total
progress: $(OVERLAY_PROG_CSVS) $(MAIN_PROG_CSV) $(TOTAL_PROG_CSV)
	@$(foreach overlay,$(OVERLAYS),$(PROGRESS_READ) progress/progress.$(overlay).csv $(VERSION) $(overlay) &&) \
	$(PROGRESS_READ) $(MAIN_PROG_CSV) $(VERSION) bk_boot
	@$(PROGRESS_READ) $(TOTAL_PROG_CSV) $(VERSION) total

# Shows progress for a single overlay (e.g. progress-SM)
$(addprefix progress-,$(OVERLAYS)) : progress-% : progress/progress.%.csv
	@$(PROGRESS_READ) $< $(VERSION) $*

# Verify that the roms match, also sets up diff_settings
verify: $(Z64)
	@$(DIFF) $(BASEROM) $(Z64) > /dev/null && \
	$(PRINT) "$(YELLOW)        _\n      _( )_\n     [     ]_\n      ) _   _)\n     [_( )_]\n$(BLUE)$(BASENAME).$(VERSION).z64$(NO_COL): $(GREEN)OK$(NO_COL)\n" || \
	$(PRINT) "$(BLUE)$(BASEROM) $(RED)differs$(NO_COL)\n"
	@$(PRINT) "def apply(config, args):\n" > diff_settings.py
	@$(PRINT) "\tconfig[\"baseimg\"] = \"$(BASEROM)\"\n" >> diff_settings.py
	@$(PRINT) "\tconfig[\"myimg\"] = \"$(Z64)\"\n" >> diff_settings.py
	@$(PRINT) "\tconfig[\"mapfile\"] = \"$(Z64:.z64=.map)\"\n" >> diff_settings.py
	@$(PRINT) "\tconfig[\"source_directories\"] = ['$(SRC_ROOT)', 'include']\n" >> diff_settings.py
	@$(PRINT) "\tconfig[\"makeflags\"] = ['-s']\n" >> diff_settings.py

# Musical note print for individual overlays
# Need to figure out how to print this only when building a single overlay
# $(YELLOW)    ╒════╕\n    │    │\n   _│   _│\n  └─┘  └─┘\n

# Verify that any given overlay matches, also sets up diff_settings
verify-%: $(BUILD_DIR)/%.rzip.bin $(BIN_ROOT)/%.$(VERSION).rzip.bin $(BUILD_DIR)/%.full progress/progress_%.svg
	@$(DIFF) $< $(BIN_ROOT)/$*.$(VERSION).rzip.bin > /dev/null && \
	$(PRINT) "$(BLUE)%-10s$(NO_COL): $(GREEN)OK$(NO_COL)\n" "$*" || \
	$(PRINT) "$(BLUE)$* $(RED)differs$(NO_COL)\n"
	@$(PRINT) "def apply(config, args):\n" > diff_settings.py
	@$(PRINT) "\tconfig[\"baseimg\"] = \"$(BUILD_DIR)/$*.$(VERSION).bin\"\n" >> diff_settings.py
	@$(PRINT) "\tconfig[\"myimg\"] = \"$(BUILD_DIR)/$*.full\"\n" >> diff_settings.py
	@$(PRINT) "\tconfig[\"mapfile\"] = \"$(BUILD_DIR)/$*.map\"\n" >> diff_settings.py
	@$(PRINT) "\tconfig[\"source_directories\"] = ['$(SRC_ROOT)/$*', 'include']\n" >> diff_settings.py
	@$(PRINT) "\tconfig[\"makeflags\"] = ['TARGET=$*','-s']\n" >> diff_settings.py

$(OVERLAY_PROG_SVGS) : progress/progress_%.svg: progress/progress.%.csv
	$(call print1,Creating progress svg for:,$*)
	@$(PROGRESS_READ) $< $(VERSION) $*

$(OVERLAY_PROG_CSVS) : progress/progress.%.csv: $(BUILD_DIR)/%.elf
	$(call print1,Calculating progress for:,$*)
	@$(PROGRESS) . $(BUILD_DIR)/$*.elf .$*_code --version $(VERSION) --subcode $* > $@

$(MAIN_PROG_SVG): $(MAIN_PROG_CSV)
	$(call print1,Creating progress svg for:,boot)
	@$(PROGRESS_READ) $< $(VERSION) bk_boot

$(MAIN_PROG_CSV): $(ELF)
	$(call print1,Calculating progress for:,boot)
	@$(PROGRESS) . $< .boot_bk_boot --version $(VERSION) > $@

$(TOTAL_PROG_SVG): $(TOTAL_PROG_CSV)
	$(call print0,Creating total progress svg)
	@$(PROGRESS_READ) $< $(VERSION) total

$(TOTAL_PROG_CSV): $(OVERLAY_PROG_CSVS) $(MAIN_PROG_CSV)
	$(call print0,Calculating total progress)
	@cat $^ > $@

# Verify that each overlay matches
verify-each: $(addprefix verify-,$(OVERLAYS)) 

# per-overlay rules
define overlay_rules
  # .o -> .elf (overlay)
  $(BUILD_DIR)/$(1).elf : $$($(1)_ALL_OBJS) $(1).ld
	$(LD) -T $(1).ld -R core2.elf --allow-multiple-definition -Map $(BUILD_DIR)/$(1).map $$(LDFLAGS_COMMON) -T undefined_syms_auto.$(1).us.v10.txt -T undefined_funcs_auto.$(1).us.v10.txt -o $$@
  # split overlay
  $(BUILD_DIR)/$(1)_SPLAT_TIMESTAMP : $(SUBYAML)/$(1).$(VERSION).yaml $(BUILD_DIR)/$(1).$(VERSION).bin $(SYMBOL_ADDRS)
	$(call print1,Splitting bin:,$$<)
	$(SPLAT) --target $(BUILD_DIR)/$(1).$(VERSION).bin $(SUBYAML)/$(1).$(VERSION).yaml --basedir .
	@touch $$@
	@touch $(1).ld
  # Dummy target to make sure extraction happens before compilation, mainly for extracted asm
  $$($(1)_C_SRCS) $$($(1)_ASM_SRCS) $$($(1)_BINS) : | $(BUILD_DIR)/$(1)_SPLAT_TIMESTAMP
	@:
  # Dummy target to make sure extraction happens before processing extracted files and linking
  $$($(1)_NEW_FILES) $(1).ld: $(BUILD_DIR)/$(1)_SPLAT_TIMESTAMP
	@:
endef
$(foreach overlay,$(OVERLAYS),$(eval $(call overlay_rules,$(overlay))))

# Additional symbols for core2
$(BUILD_DIR)/core2.elf: LDFLAGS_COMMON = -T symbol_addrs.core1.$(VERSION).txt -T symbol_addrs.core2.$(VERSION).txt -T symbol_addrs.global.$(VERSION).txt -T undefined_syms.$(VERSION).txt -T undefined_syms.libultra.txt --no-check-sections --accept-unknown-input-arch -T level_symbols.us.v10.txt
$(BUILD_DIR)/core2.temp.elf: LDFLAGS_COMMON = -T symbol_addrs.core1.$(VERSION).txt -T symbol_addrs.core2.$(VERSION).txt -T symbol_addrs.global.$(VERSION).txt -T undefined_syms.$(VERSION).txt -T undefined_syms.libultra.txt --no-check-sections --accept-unknown-input-arch -T level_symbols.us.v10.txt

# mkdir
$(ALL_DIRS) :
	$(call print1,Making folder:,$@)
	@$(MKDIR) -p $@

# .s -> .o (assemble with gcc for preprocessor support)
$(BUILD_DIR)/%.s.o: %.s | $(ASM_BUILD_DIRS)
	$(call print2,Assembling:,$<,$@)
	@$(GCC) $(GCC_ASFLAGS) $(INCLUDE_CFLAGS) -o $@ $<

# .bin -> .o
$(BIN_OBJS) : $(BUILD_DIR)/%.bin.o : %.bin | $(BIN_BUILD_DIRS)
	$(call print2,Objcopying:,$<,$@)
	@$(OBJCOPY) $(BINOFLAGS) $< $@

# .bin -> .o (overlay)
$(OVERLAY_RZIP_OBJS) : $(BUILD_DIR)/$(BIN_ROOT)/%.$(VERSION).rzip.bin.o : $(BUILD_DIR)/%.rzip.bin
	$(call print2,Objcopying:,$<,$@)
	@$(OBJCOPY) $(BINOFLAGS) $< $@

$(BUILD_DIR)/bk_boot.full: $(BUILD_DIR)/bk_boot.elf
	@mips-linux-gnu-objcopy -I elf32-tradbigmips -O binary --only-section .boot_bk_boot $(BUILD_DIR)/bk_boot.elf $@

$(BUILD_DIR)/crc.bin : $(BUILD_DIR)/bk_boot.full $(BUILD_DIR)/core1.code $(BUILD_DIR)/core1.data $(BK_CRC)
	@$(BK_CRC) $(BUILD_DIR)/bk_boot.full > $(BUILD_DIR)/crc.bin
	@$(BK_CRC) $(BUILD_DIR)/core1.code >> $(BUILD_DIR)/crc.bin
	@$(BK_CRC) $(BUILD_DIR)/core1.data >> $(BUILD_DIR)/crc.bin

# .bin -> .o (overlay crc check)
$(CRC_OBJS) : $(BUILD_DIR)/crc.bin
	$(call print2,Objcopying:,$<,$@)
	@$(OBJCOPY) $(BINOFLAGS) $< $@

# .c -> .o
$(BUILD_DIR)/%.c.o : %.c | $(C_BUILD_DIRS)
	$(call print2,Compiling:,$<,$@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDE_CFLAGS) $(OPT_FLAGS) $(MIPSBIT) -o $@ $<

# .c -> .o (mips3)
$(MIPS3_OBJS) : $(BUILD_DIR)/%.c.o : %.c | $(C_BUILD_DIRS)
	$(call print2,Compiling:,$<,$@)
	@$(CC) -c -32 $(CFLAGS) $(CPPFLAGS) $(INCLUDE_CFLAGS) $(OPT_FLAGS) $(LOOP_UNROLL) $(MIPSBIT) -o $@ $<
	@tools/set_o32abi_bit.py $@

# .c -> .o with asm processor
$(GLOBAL_ASM_C_OBJS) : $(BUILD_DIR)/%.c.o : %.c | $(C_BUILD_DIRS)
	$(call print2,Compiling (with ASM Processor):,$<,$@)
	@$(ASM_PROCESSOR) $(OPT_FLAGS) $< > $(BUILD_DIR)/$<
	@$(CC) -32 $(CFLAGS) $(CPPFLAGS) $(INCLUDE_CFLAGS) $(OPT_FLAGS) $(MIPSBIT) -o $@ $(BUILD_DIR)/$<
	@$(ASM_PROCESSOR) $(OPT_FLAGS) $< --post-process $@ \
		--assembler "$(AS) $(ASFLAGS)" --asm-prelude include/prelude.s

# Split baserom
$(BUILD_DIR)/SPLAT_TIMESTAMP: $(BASENAME).$(VERSION).yaml $(SYMBOL_ADDRS) | $(BUILD_DIR)
	$(call print1,Splitting rom:,$<)
	@touch $@
	@$(SPLAT) $(BASENAME).$(VERSION).yaml
	@touch $(LD_SCRIPT)
# Dummy target to make the LD script and overlay rzips depend on splat being run
#   without causing it to be rerun once for every overlay
# Bin files are also dependent on the splat timestamp since they get overwritten on resplit
$(MAIN_NEW_FILES) $(LD_SCRIPT) $(MAIN_BINS) : $(BUILD_DIR)/SPLAT_TIMESTAMP
	@:
# Dummy target to make sure extraction happens before compilation, mainly for extracted asm
$(MAIN_C_SRCS) $(MAIN_ASM_SRCS) : | $(BUILD_DIR)/SPLAT_TIMESTAMP
	@:

# .rzip.bin -> .bin
$(OVERLAY_BINS) : $(BUILD_DIR)/%.$(VERSION).bin : $(BIN_ROOT)/%.$(VERSION).rzip.bin $(BK_INFLATE) | $(BUILD_DIR)
	$(call print1,Decompressing rzip:,$<)
	@$(BK_INFLATE) $< $@

# Special rules to handle core2 code checksumming
ifneq ($(CORE2_CODE_CRC_C_OBJS),)
  CORE2_TEMP_LD := core2.temp.ld
  CORE2_CODE_CRC_C_TEMP_OBJS := $(CORE2_CODE_CRC_C_OBJS:.c.o=.c.o_)
  core2_NON_CRC_OBJS := $(filter-out $(CORE2_CODE_CRC_C_OBJS),$(core2_ALL_OBJS))
  
  # core2.ld -> core2.temp.ld
 $(CORE2_TEMP_LD) : core2.ld
	$(call print0,Creating linker script for initial core2 linking step)
	@$(CP) $< $@
	$(foreach obj, $(CORE2_CODE_CRC_C_OBJS), sed -i 's:$(obj):$(obj)_:g' $@)
  
  # core2 .c -> .o with zero for core2 code CRC
  $(CORE2_CODE_CRC_C_TEMP_OBJS) : $(BUILD_DIR)/%.c.o_ : %.c | $(C_BUILD_DIRS)
	$(call print2,Compiling temp file:,$<,$@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDE_CFLAGS) $(OPT_FLAGS) $(MIPSBIT) -o $@ $<
  
  # core2 objects with zero for code CRC -> core2.temp.elf
  $(BUILD_DIR)/core2.temp.elf : $(core2_NON_CRC_OBJS) $(CORE2_TEMP_LD) $(CORE2_CODE_CRC_C_TEMP_OBJS)
	$(call print1,Linking elf:,$@)
	@$(LD) -T $(CORE2_TEMP_LD) -Map $(BUILD_DIR)/core2.map $(LDFLAGS_COMMON) -T undefined_syms_auto.core2.us.v10.txt -T undefined_funcs_auto.core2.us.v10.txt -o $@
  
  # core2.temp.elf -> core2.temp.code
  $(BUILD_DIR)/core2.temp.code : $(BUILD_DIR)/core2.temp.elf
	$(call print2,Converting initial core2 code:,$<,$@)
	@$(OBJCOPY) -O binary --only-section .core2_code $< $@
  
  # core2 code -> core2 code crc
  $(BUILD_DIR)/core2.code.crc : $(BUILD_DIR)/core2.temp.code $(BK_CRC)
	$(call print0,Calculating core2 code CRC)
	@$(BK_CRC) -D CORE2_CODE $< > $@
  
  # core2 .c -> .o with correct core2 code CRC
  $(CORE2_CODE_CRC_C_OBJS) : $(BUILD_DIR)/%.c.o : %.c $(BUILD_DIR)/core2.code.crc | $(C_BUILD_DIRS)
	$(call print2,Compiling:,$<,$@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDE_CFLAGS) $(OPT_FLAGS) $(MIPSBIT) $(shell cat $(BUILD_DIR)/core2.code.crc) -o $@ $<
endif

# core2 data -> core2 data CRC
$(BUILD_DIR)/core2.data.crc : $(BUILD_DIR)/core2.data $(BK_CRC)
	$(call print0,Calculating core2 data CRC)
	@$(BK_CRC) -D CORE2_DATA $< > $@

# core1 .c -> .o with correct core2 data CRC
$(CORE2_DATA_CRC_C_OBJS) : $(BUILD_DIR)/%.o : % $(BUILD_DIR)/core2.data.crc | $(C_BUILD_DIRS)
	$(call print2,Compiling file with core2 data CRC (with ASM Processor):,$<,$@)
	@$(ASM_PROCESSOR) $(OPT_FLAGS) $< > $(BUILD_DIR)/$<
	@$(CC) -32 $(CFLAGS) $(CPPFLAGS) $(INCLUDE_CFLAGS) $(OPT_FLAGS) $(MIPSBIT) $(shell cat $(BUILD_DIR)/core2.data.crc) -o $@ $(BUILD_DIR)/$<
	@$(ASM_PROCESSOR) $(OPT_FLAGS) $< --post-process $@ \
		--assembler "$(AS) $(ASFLAGS)" --asm-prelude include/prelude.s

# .elf -> .code
$(OVERLAY_CODE_BINS) : $(BUILD_DIR)/%.code : $(BUILD_DIR)/%.elf
	$(call print2,Converting overlay code:,$<,$@)
	@$(OBJCOPY) -I elf32-tradbigmips -O binary --only-section .$*_code --only-section .$*_mips3 $< $@

# .elf -> .data
$(OVERLAY_DATA_BINS) : $(BUILD_DIR)/%.data : $(BUILD_DIR)/%.elf
	$(call print2,Converting overlay data:,$<,$@)
	@$(OBJCOPY) -I elf32-tradbigmips -O binary --only-section .$*_data --only-section .*_data_* $< $@

# .elf -> .full
$(BUILD_DIR)/%.full : $(BUILD_DIR)/%.elf
	@$(OBJCOPY) -I elf32-tradbigmips -O binary $< $@

# .data + .code -> .rzip.bin
$(BUILD_DIR)/%.rzip.bin : $(BUILD_DIR)/%.code $(BUILD_DIR)/%.data $(BK_DEFLATE)
	$(call print1,Compressing overlay:,$@)
	@cd $(BK_TOOLS) && ../../$(BK_DEFLATE) ../../$@ ../../$(BUILD_DIR)/$*.code ../../$(BUILD_DIR)/$*.data

# .bin -> .yaml
$(ASSET_ROOT)/assets.yaml : $(BIN_ROOT)/assets.bin $(BK_ASSET_TOOL)
	$(call print1,Extracting Assets:,$@)
	$(BK_ASSET_TOOL) -e $< $(ASSET_ROOT)

# .yaml -> .bin
ifneq (,$(shell which cargo))
$(ASSET_BIN): $(ASSET_ROOT)/assets.yaml $(BK_ASSET_TOOL) $(ALL_ASSET_FILES)
	$(call print2,Constructing Asset Binary:,$<,$@)
	$(BK_ASSET_TOOL) -c $< $@
else
$(ASSET_BIN): $(BIN_ROOT)/assets.bin
	$(call print2,Copying Asset Binary (install cargo to construct instead):,$<,$@)
	@$(CP) $< $@
endif

# .bin -> .o
$(ASSET_OBJS): $(ASSET_BIN)
	$(call print2,Objcopying:,$<,$@)
	@$(OBJCOPY) $(BINOFLAGS) $< $@

# .o -> .elf (game)
$(ELF): $(MAIN_ALL_OBJS) $(LD_SCRIPT) $(OVERLAY_RZIP_OBJS) $(addprefix $(BUILD_DIR)/, $(addsuffix .full, $(OVERLAYS))) $(ASSET_OBJS)
	$(call print1,Linking elf:,$@)
	@$(LD) $(LDFLAGS) -T undefined_syms_auto.us.v10.txt -o $@

$(BK_BOOT_LD_SCRIPT): $(LD_SCRIPT)
	sed '\|$(CRC_OBJS)|d'  $< > $@

# .o -> .elf (game)
$(BUILD_DIR)/bk_boot.elf: $(filter-out $(CRC_OBJS),$(MAIN_ALL_OBJS)) $(BK_BOOT_LD_SCRIPT) $(OVERLAY_RZIP_OBJS) $(addprefix $(BUILD_DIR)/, $(addsuffix .full, $(OVERLAYS)))
	$(call print1,Linking elf:,$@)
	@$(LD) -T $(BK_BOOT_LD_SCRIPT) -Map $(ELF:.elf=.map) --no-check-sections --accept-unknown-input-arch -T undefined_syms.libultra.txt -T undefined_syms_auto.us.v10.txt -o $@

# .elf -> .z64
$(Z64) : $(ELF) $(OVERLAY_PROG_SVGS) $(MAIN_PROG_SVG) $(TOTAL_PROG_SVG)
	$(call print1,Creating z64:,$@)
	@$(OBJCOPY) $< $@ -O binary $(OCOPYFLAGS)

$(BK_TOOLS)/gzip-1.2.4/gzip: $(BK_TOOLS)/gzip-1.2.4/Makefile
	@$(CD) $(BK_TOOLS)/gzip-1.2.4 && $(MAKE) gzip

$(BK_TOOLS)/gzip-1.2.4/Makefile:
	@$(CD) $(BK_TOOLS)/gzip-1.2.4 && ./configure

$(BK_ASSET_TOOL):
	@$(CD) tools/bk_asset_tool && cargo build --release
	@$(CP) tools/bk_asset_tool/target/release/bk_asset_tool $@

# Build tools
$(BK_TOOLS)/%: $(BK_TOOLS)/gzip-1.2.4/gzip
	$(call print1,Compiling build tool:,$@)
	@$(CD) $(BK_TOOLS) && $(MAKE) $*

$(BK_CRC) :
	g++ $@.cpp -o $@

# Combined symbol addresses file
$(SYMBOL_ADDRS): $(SYMBOL_ADDR_FILES)
	$(call print0,Combining symbol address files)
	@$(CAT) symbol_addrs.*.$(VERSION).txt > $@

# Shorthand rules for each overlay (e.g. SM)
$(OVERLAYS): %: verify-%

clean:
	$(call print0,Cleaning build artifacts)
	@$(RM) -rf $(BUILD_ROOT)
	@$(RM) -rf $(BIN_ROOT)
	@$(RM) -rf $(NONMATCHING_DIR)
	@$(RM) -rf $(ASM_ROOT)/*.s
	@$(RM) -rf $(addprefix $(ASM_ROOT)/,$(filter-out core1,$(OVERLAYS)))
	@$(RM) -rf $(ASM_ROOT)/core1/*.s
	@$(RM) -rf $(ASM_ROOT)/core1/os
	@$(RM) -f undefined_syms_auto* undefined_funcs_auto*
	@$(RM) -f *.ld
	@$(RM) -f $(SYMBOL_ADDRS)

# Per-file flag definitions
build/us.v10/src/core1/io/%.c.o: OPT_FLAGS = -O1
build/us.v10/src/core1/io/pimgr.c.o: OPT_FLAGS = -O1
build/us.v10/src/core1/done/io/%.c.o: OPT_FLAGS = -O1
build/us.v10/src/core1/os/%.c.o: OPT_FLAGS = -O1
build/us.v10/src/core1/code_2D2D0.c.o: OPT_FLAGS = -O1
build/us.v10/src/core1/done/os/%.c.o: OPT_FLAGS = -O1
build/us.v10/src/core1/code_21A10.c.o: INCLUDE_CFLAGS = -I . -I include -I include/2.0L -I include/2.0L/PR
build/us.v10/src/core1/code_21A10.c.o: OPT_FLAGS = -O3
build/us.v10/src/core1/done/gu/%.c.o: OPT_FLAGS = -O3
build/us.v10/src/core1/done/gu/%.c.o: INCLUDE_CFLAGS = -I . -I include -I include/2.0L -I include/2.0L/PR
build/us.v10/src/core1/gu/mtxutil.c.o: OPT_FLAGS = -O2
build/us.v10/src/core1/gu/rotate.c.o: OPT_FLAGS = -O2
build/us.v10/src/core1/done/audio/%.c.o: INCLUDE_CFLAGS = -I . -I include -I include/2.0L -I include/2.0L/PR
build/us.v10/src/core1/done/audio/%.c.o: OPT_FLAGS = -O3
# build/us.v10/src/core1/code_21CB0.c.o: INCLUDE_CFLAGS = -I . -I include -I include/2.0L -I include/2.0L/PR
# build/us.v10/src/core1/code_21CB0.c.o: OPT_FLAGS = -O3
build/us.v10/src/core1/done/io/sptask.c.o: OPT_FLAGS = -O1
build/us.v10/src/core1/done/ll.c.o: OPT_FLAGS := -O1
build/us.v10/src/core1/done/ll.c.o: MIPSBIT := -mips3 -o32

build/us.v10/src/bk_boot_27F0.c.o: OPT_FLAGS = -O2
build/us.v10/src/done/destroythread.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/pirawdma.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/thread.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/pimgr.c.o: OPT_FLAGS := -O1
build/us.v10/src/getthreadid.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/setthreadpri.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/createthread.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/yieldthread.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/setglobalintmask.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/recvmesg.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/startthread.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/devmgr.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/sendmesg.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/pigetstat.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/si.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/resetglobalintmask.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/epirawwrite.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/epirawread.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/createmesgqueue.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/leodiskinit.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/virtualtophysical.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/ll.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/ll.c.o: MIPSBIT := -mips3 -o32
build/us.v10/src/done/sirawwrite.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/sirawread.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/initialize.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/pirawread.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/seteventmesg.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/siacs.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/cartrominit.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/leointerrupt.c.o: OPT_FLAGS := -O1
build/us.v10/src/done/epirawdma.c.o: OPT_FLAGS := -O1

# Disable implicit rules
MAKEFLAGS += -r

# Disable built-in rules
.SUFFIXES:

# Phony targets
.PHONY: all clean verify $(OVERLAYS) progress $(addprefix progress-,$(OVERLAYS))

# Set up pipefail
SHELL = /bin/bash -e -o pipefail

# Debug variable print target
print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
