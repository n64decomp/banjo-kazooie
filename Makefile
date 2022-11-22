### Configuration ###
BASENAME := banjo
VERSION  ?= us.v10

ifeq ($(VERSION),us.v10)
	C_VERSION=0
endif

ifeq ($(VERSION),pal)
	C_VERSION=1
endif

ifeq ($(VERSION),us.v11)
	C_VERSION=2
endif

ifeq ($(VERSION),jp)
	C_VERSION=3
endif

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
BK_ROM_COMPRESS   := tools/bk_rom_compressor/target/release/bk_rom_compress
BK_ROM_DECOMPRESS := tools/bk_rom_compressor/target/release/bk_rom_decompress
BK_ASSET_TOOL     := tools/bk_asset_tool/bk_asset_tool
ASM_PROCESSOR     := $(PYTHON) $(ASM_PROCESSOR_DIR)/asm_processor.py
SPLAT_INPUTS      := $(PYTHON) tools/splat_inputs.py
PROGRESS          := $(PYTHON) tools/progress.py
PROGRESS_READ     := $(PYTHON) tools/progress_read.py

### Files and Directories ###

# Inputs
OVERLAYS := core1 core2 MM TTC CC BGS FP lair GV CCW RBB MMM SM fight cutscenes

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
C_SRCS            := $(shell find $(SRC_ROOT) -type f -iname '*.c' 2> /dev/null)
BOOT_C_SRCS       := $(wildcard $(SRC_ROOT)/done/*.c)
ALL_ASM_SRCS      := $(filter-out $(ASM_ROOT)/$(NONMATCHINGS), $(shell find $(ASM_ROOT) -name $(NONMATCHINGS) -prune -o -iname '*.s' 2> /dev/null))
ALL_BINS          := $(shell find $(BIN_ROOT) -type f -iname '*.bin' 2> /dev/null)
# Files referenced in the splat file
YAML_CALL := $(SPLAT_INPUTS) decompressed.$(VERSION).yaml
YAML_SRCS   := $(sort $(shell $(SPLAT_INPUTS) decompressed.$(VERSION).yaml))
YAML_C_SRCS := $(filter %.c, $(YAML_SRCS))
YAML_ASM_SRCS := $(filter %.s, $(YAML_SRCS))
YAML_BINS := $(filter %.bin, $(YAML_SRCS))
# Files that need to be extracted
NEW_C_SRCS := $(filter-out $(C_SRCS), $(YAML_C_SRCS))
NEW_ASM_SRCS := $(filter-out $(ALL_ASM_SRCS), $(YAML_ASM_SRCS))
NEW_BINS := $(filter-out $(ALL_BINS), $(YAML_BINS))
NEW_FILES := $(NEW_C_SRCS) $(NEW_ASM_SRCS) $(NEW_BINS)
BOOT_ASM_SRCS := $(filter-out asm/core1/%,$(NEW_ASM_SRCS) $(ALL_ASM_SRCS))
# Any source files that have GLOBAL_ASM in them or do not exist before splitting
GLOBAL_ASM_C_SRCS := $(shell $(GREP) GLOBAL_ASM $(SRC_ROOT) </dev/null) $(NEW_C_SRCS)

# Build folders
C_DIRS         := $(sort $(dir $(C_SRCS) $(NEW_C_SRCS)))
ASM_DIRS       := $(sort $(dir $(ALL_ASM_SRCS) $(NEW_ASM_SRCS)))
BIN_DIRS       := $(sort $(dir $(ALL_BINS) $(NEW_BINS)))
C_BUILD_DIRS   := $(addprefix $(BUILD_DIR)/,$(C_DIRS))
ASM_BUILD_DIRS := $(addprefix $(BUILD_DIR)/,$(ASM_DIRS))
BIN_BUILD_DIRS := $(addprefix $(BUILD_DIR)/,$(BIN_DIRS))
ALL_DIRS       := $(C_BUILD_DIRS) $(ASM_BUILD_DIRS) $(BIN_BUILD_DIRS) $(BUILD_DIR)

# Build files
BASEROM              := baserom.$(VERSION).z64
DECOMPRESSED_BASEROM := decompressed.$(VERSION).z64
C_OBJS               := $(addprefix $(BUILD_DIR)/,$(C_SRCS:.c=.c.o))
BOOT_C_OBJS          := $(addprefix $(BUILD_DIR)/,$(BOOT_C_SRCS:.c=.c.o))
GLOBAL_ASM_C_OBJS    := $(addprefix $(BUILD_DIR)/,$(GLOBAL_ASM_C_SRCS:.c=.c.o))
C_DEPS               := $(C_OBJS:.o=.d)
ASM_OBJS             := $(addprefix $(BUILD_DIR)/,$(ALL_ASM_SRCS:.s=.s.o) $(NEW_ASM_SRCS:.s=.s.o))
BOOT_ASM_OBJS        := $(addprefix $(BUILD_DIR)/,$(BOOT_ASM_SRCS:.s=.s.o))
BIN_OBJS             := $(addprefix $(BUILD_DIR)/,$(ALL_BINS:.bin=.bin.o) $(NEW_BINS:.bin=.bin.o))
Z64                  := $(addprefix $(BUILD_DIR)/,$(BASENAME).$(VERSION).uncompressed.z64)
FINAL_Z64            := $(addprefix $(BUILD_DIR)/,$(BASENAME).$(VERSION).z64)
ELF                  := $(Z64:.z64=.elf)
LD_SCRIPT            := $(BASENAME).ld
BK_BOOT_LD_SCRIPT    := bk_boot.ld
ASSET_BIN            := $(BUILD_DIR)/assets.bin
DUMMY_CRC_OBJ        := $(BUILD_DIR)/$(BIN_ROOT)/dummy_crc.bin.o
ASSET_OBJS           := $(BUILD_DIR)/$(BIN_ROOT)/assets.bin.o
BIN_OBJS             := $(filter-out $(ASSET_OBJS),$(BIN_OBJS))
ALL_OBJS             := $(C_OBJS) $(ASM_OBJS) $(BIN_OBJS)
SYMBOL_ADDRS         := symbol_addrs.$(VERSION).txt
SYMBOL_ADDR_FILES    := $(filter-out $(SYMBOL_ADDRS), $(wildcard symbol_addrs.*.$(VERSION).txt))
MIPS3_OBJS           := $(BUILD_DIR)/$(SRC_ROOT)/core1/done/ll.c.o
BOOT_MIPS3_OBJS      := $(BUILD_DIR)/$(SRC_ROOT)/done/ll.c.o
BOOT_C_OBJS          := $(filter-out $(BOOT_MIPS3_OBJS),$(BOOT_C_OBJS))
COMPRESSED_SYMBOLS   := $(BUILD_DIR)/compressed_symbols.txt

# Progress files
MAIN_PROG_CSV     := progress/progress.bk_boot.csv
MAIN_PROG_SVG     := progress/progress_bk_boot.svg
TOTAL_PROG_CSV    := progress/progress.total.csv
TOTAL_PROG_SVG    := progress/progress_total.svg
OVERLAY_PROG_CSVS := $(addprefix progress/progress., $(addsuffix .csv, $(OVERLAYS)))
OVERLAY_PROG_SVGS := $(addprefix progress/progress_, $(addsuffix .svg, $(OVERLAYS)))
README_MD         := README.md

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
CFLAGS         := -c -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm $(OPT_FLAGS) $(MIPSBIT) -D_FINALROM -DF3DEX_GBI -DVERSION='$(C_VERSION)'
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
verify-decompressed: $(DECOMPRESSED_BASEROM) $(Z64)
	@$(DIFF) $(DECOMPRESSED_BASEROM) $(Z64) > /dev/null && \
	$(PRINT) "$(YELLOW)        _\n      _( )_\n     [     ]_\n      ) _   _)\n     [_( )_]\n$(BLUE)$(BASENAME).$(VERSION).uncompressed.z64$(NO_COL): $(GREEN)OK$(NO_COL)\n" || \
	$(PRINT) "$(BLUE)$(BASEROM) $(RED)differs$(NO_COL)\n"

verify: $(BASEROM) $(FINAL_Z64)
	@$(DIFF) $(BASEROM) $(FINAL_Z64) > /dev/null && \
	$(PRINT) "$(YELLOW)        _\n      _( )_\n     [     ]_\n      ) _   _)\n     [_( )_]\n$(BLUE)$(BASENAME).$(VERSION).z64$(NO_COL): $(GREEN)OK$(NO_COL)\n" || \
	$(PRINT) "$(BLUE)$(BASEROM) $(RED)differs$(NO_COL)\n"

$(OVERLAY_PROG_SVGS) : progress/progress_%.svg: progress/progress.%.csv
	$(call print1,Creating progress svg for:,$*)
	@$(PROGRESS_READ) $< $(VERSION) $*

$(OVERLAY_PROG_CSVS) : progress/progress.%.csv: $(ELF)
	$(call print1,Calculating progress for:,$*)
	@$(PROGRESS) . $(ELF) .$* --version $(VERSION) --subcode $* > $@

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

$(README_MD): $(TOTAL_PROG_SVG)
	@head -n 21 $< | tail -n 1 | head -c -8 | tail -c +32 | xargs -i sed -i "/# banjo*/c\# banjo ({})" $@

# mkdir
$(ALL_DIRS) :
	$(call print1,Making folder:,$@)
	@$(MKDIR) -p $@

# .s -> .o (assemble with gcc for preprocessor support)
$(BUILD_DIR)/%.s.o: %.s | $(ASM_BUILD_DIRS)
	$(call print2,Assembling:,$<,$@)
	@$(GCC) $(GCC_ASFLAGS) $(INCLUDE_CFLAGS) -o $@ $<

# .s -> .o (boot)
$(BOOT_ASM_OBJS) : $(BUILD_DIR)/%.s.o : %.s | $(ASM_BUILD_DIRS)
	$(call print2,Assembling:,$<,$@)
	@$(GCC) $(GCC_ASFLAGS) $(INCLUDE_CFLAGS) -o $@ $<
	$(OBJCOPY) --prefix-symbols=boot_ $@

# .bin -> .o
$(BIN_OBJS) : $(BUILD_DIR)/%.bin.o : %.bin | $(BIN_BUILD_DIRS)
	$(call print2,Objcopying:,$<,$@)
	@$(OBJCOPY) $(BINOFLAGS) $< $@

$(BUILD_DIR)/bk_boot.full: $(BUILD_DIR)/bk_boot.elf
	@mips-linux-gnu-objcopy -I elf32-tradbigmips -O binary --only-section .boot_bk_boot $(BUILD_DIR)/bk_boot.elf $@

# Creates a dummy crc file of 32 bytes to use in the initial link
$(BUILD_DIR)/dummy_crc.bin:
	$(call print1,Creating dummy crc file:$@)
	truncate -s 32 $@

# .bin -> .o (dummy crc)
$(DUMMY_CRC_OBJ) : $(BUILD_DIR)/dummy_crc.bin
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

# .c -> .o (boot)
$(BOOT_C_OBJS) : $(BUILD_DIR)/%.c.o : %.c | $(C_BUILD_DIRS)
	$(call print2,Compiling:,$<,$@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDE_CFLAGS) $(OPT_FLAGS) $(MIPSBIT) -o $@ $<
	mips-linux-gnu-strip $@ -N asdasdasasdasd
	$(OBJCOPY) --prefix-symbols=boot_ $@
	$(OBJCOPY) --strip-unneeded $@

# .c -> .o (mips3, boot)
$(BOOT_MIPS3_OBJS) : $(BUILD_DIR)/%.c.o : %.c | $(C_BUILD_DIRS)
	$(call print2,Compiling:,$<,$@)
	@$(CC) -c -32 $(CFLAGS) $(CPPFLAGS) $(INCLUDE_CFLAGS) $(OPT_FLAGS) $(LOOP_UNROLL) $(MIPSBIT) -o $@ $<
	@tools/set_o32abi_bit.py $@
	$(OBJCOPY) --prefix-symbols=boot_ $@
	$(OBJCOPY) --strip-unneeded $@

# Split baserom
$(BUILD_DIR)/SPLAT_TIMESTAMP: decompressed.$(VERSION).yaml $(SYMBOL_ADDRS) $(DECOMPRESSED_BASEROM) | $(BUILD_DIR)
	$(call print1,Splitting rom:,$<)
	@$(SPLAT) decompressed.$(VERSION).yaml
	@touch $@
	@touch $(LD_SCRIPT)

# Dummy target to make the LD script and overlay rzips depend on splat being run
#   without causing it to be rerun once for every overlay
# Bin files are also dependent on the splat timestamp since they get overwritten on resplit
$(NEW_FILES) $(LD_SCRIPT) $(ALL_BINS) : $(BUILD_DIR)/SPLAT_TIMESTAMP
	@:
# Dummy target to make sure extraction happens before compilation, mainly for extracted asm
$(C_SRCS) $(ASM_SRCS) : | $(BUILD_DIR)/SPLAT_TIMESTAMP
	@:

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
$(ELF): $(ALL_OBJS) $(LD_SCRIPT) $(ASSET_OBJS)
	$(call print1,Linking elf:,$@)
	@$(LD) $(LDFLAGS) -T undefined_syms_auto.$(VERSION).txt -T undefined_syms.$(VERSION).txt -T rzip_dummy_addrs.txt -o $@

$(BK_BOOT_LD_SCRIPT): $(LD_SCRIPT)
	sed 's|$(CRC_OBJS)|$(DUMMY_CRC_OBJ)|'  $< > $@

# .o -> .elf (game)
$(BUILD_DIR)/bk_boot.elf: $(DUMMY_CRC_OBJ) $(filter-out $(CRC_OBJS),$(MAIN_ALL_OBJS)) $(BK_BOOT_LD_SCRIPT) $(ASSET_OBJS)
	$(call print1,Linking elf:,$@)
	@$(LD) -T $(BK_BOOT_LD_SCRIPT) -Map $(ELF:.elf=.map) --no-check-sections --accept-unknown-input-arch -T undefined_syms.libultra.txt -T undefined_syms_auto.$(VERSION).txt  -T undefined_syms.$(VERSION).txt -T rzip_dummy_addrs.txt -o $@

# decompress baserom
$(DECOMPRESSED_BASEROM): $(BASEROM) $(BK_ROM_DECOMPRESS)
	@$(BK_ROM_DECOMPRESS) $< $@

# generate compressed ROM symbols
$(COMPRESSED_SYMBOLS): $(ELF) $(Z64) $(BK_ROM_COMPRESS)
	@$(BK_ROM_COMPRESS) --symbols $(ELF) $(Z64) $@

# compress ROM
$(FINAL_Z64) : $(ELF) $(Z64) $(BK_ROM_COMPRESS)
	@$(BK_ROM_COMPRESS) $(ELF) $(Z64) $@

# .elf -> .z64
$(Z64) : $(ELF)
#$(OVERLAY_PROG_SVGS) $(MAIN_PROG_SVG) $(TOTAL_PROG_SVG) $(README_MD)
	$(call print1,Creating z64:,$@)
	@$(OBJCOPY) $< $@ -O binary $(OCOPYFLAGS)

$(COMPRESSED_Z64) : $(Z64) $(ELF) $(BK_ROM_COMPRESS)
	$(BK_ROM_COMPRESS) --version $(VERSION) --symbols

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

$(BK_ROM_COMPRESS):
	@$(CD) tools/bk_rom_compressor && cargo build --release --bin bk_rom_compress

$(BK_ROM_DECOMPRESS):
	@$(CD) tools/bk_rom_compressor && cargo build --release --bin bk_rom_decompress

# Combined symbol addresses file
$(SYMBOL_ADDRS): $(SYMBOL_ADDR_FILES)
	$(call print0,Combining symbol address files)
	@$(CAT) symbol_addrs.*.$(VERSION).txt > $@

clean:
	$(call print0,Cleaning build artifacts)
	@$(RM) -rf $(BUILD_ROOT)
	@$(RM) -rf $(DECOMPRESSED_BASEROM)
	@$(RM) -rf $(BIN_ROOT)
	@$(RM) -rf $(NONMATCHING_DIR)
	@$(RM) -rf $(ASM_ROOT)/*.s
	@$(RM) -rf $(addprefix $(ASM_ROOT)/,$(filter-out core1,$(OVERLAYS)))
	@$(RM) -rf $(ASM_ROOT)/core1/*.s
	@$(RM) -rf $(ASM_ROOT)/core1/os
	@$(RM) -f undefined_syms_auto* undefined_funcs_auto*
	@$(RM) -f *.ld

# Per-file flag definitions
build/$(VERSION)/src/core1/io/%.c.o: OPT_FLAGS = -O1
build/$(VERSION)/src/core1/io/pimgr.c.o: OPT_FLAGS = -O1
build/$(VERSION)/src/core1/done/io/%.c.o: OPT_FLAGS = -O1
build/$(VERSION)/src/core1/os/%.c.o: OPT_FLAGS = -O1
build/$(VERSION)/src/core1/code_2D2D0.c.o: OPT_FLAGS = -O1
build/$(VERSION)/src/core1/done/os/%.c.o: OPT_FLAGS = -O1
build/$(VERSION)/src/core1/code_21A10.c.o: INCLUDE_CFLAGS = -I . -I include -I include/2.0L -I include/2.0L/PR
build/$(VERSION)/src/core1/code_21A10.c.o: OPT_FLAGS = -O3
build/$(VERSION)/src/core1/done/gu/%.c.o: OPT_FLAGS = -O3
build/$(VERSION)/src/core1/done/gu/%.c.o: INCLUDE_CFLAGS = -I . -I include -I include/2.0L -I include/2.0L/PR
build/$(VERSION)/src/core1/gu/mtxutil.c.o: OPT_FLAGS = -O2
build/$(VERSION)/src/core1/gu/rotate.c.o: OPT_FLAGS = -O2
build/$(VERSION)/src/core1/done/audio/%.c.o: INCLUDE_CFLAGS = -I . -I include -I include/2.0L -I include/2.0L/PR
build/$(VERSION)/src/core1/done/audio/%.c.o: OPT_FLAGS = -O3
# build/$(VERSION)/src/core1/code_21CB0.c.o: INCLUDE_CFLAGS = -I . -I include -I include/2.0L -I include/2.0L/PR
# build/$(VERSION)/src/core1/code_21CB0.c.o: OPT_FLAGS = -O3
build/$(VERSION)/src/core1/done/io/sptask.c.o: OPT_FLAGS = -O1
build/$(VERSION)/src/core1/done/ll.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/core1/done/ll.c.o: MIPSBIT := -mips3 -o32

build/$(VERSION)/src/bk_boot_27F0.c.o: OPT_FLAGS = -O2
build/$(VERSION)/src/done/destroythread.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/pirawdma.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/thread.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/pimgr.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/getthreadid.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/setthreadpri.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/createthread.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/yieldthread.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/setglobalintmask.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/recvmesg.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/startthread.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/devmgr.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/sendmesg.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/pigetstat.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/si.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/resetglobalintmask.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/epirawwrite.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/epirawread.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/createmesgqueue.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/leodiskinit.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/virtualtophysical.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/ll.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/ll.c.o: MIPSBIT := -mips3 -o32
build/$(VERSION)/src/done/sirawwrite.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/sirawread.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/initialize.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/pirawread.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/seteventmesg.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/siacs.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/cartrominit.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/leointerrupt.c.o: OPT_FLAGS := -O1
build/$(VERSION)/src/done/epirawdma.c.o: OPT_FLAGS := -O1

# Disable implicit rules
MAKEFLAGS += -r

# Disable built-in rules
.SUFFIXES:

# Phony targets
.PHONY: all clean verify verify-decompressed $(OVERLAYS) progress $(addprefix progress-,$(OVERLAYS))

# Set up pipefail
SHELL = /bin/bash -e -o pipefail

# Debug variable print target
print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
