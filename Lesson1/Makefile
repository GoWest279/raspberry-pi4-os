RPI_VERSION ?= 4

BOOTMNT ?= /srv/tftpboot/

ARMGNU ?= aarch64-linux-gnu

COPS = -DRPI_VERSION=$(RPI_VERSION) -Wall -nostdlib -nostartfiles -ffreestanding \
	   -Iinclude -mgeneral-regs-only 
# -g flag gives symbol tabel, which generates source level debug information

ASMOPS = -Iinclude

BUILD_DIR = build
SRC_DIR = src

all : kernel8.img

clean :
	rm -rf $(BUILD_DIR) *.img dump.txt
dump:
	aarch64-none-linux-gnu-objdump build/kernel8.elf -d > dump.txt
$(BUILD_DIR)/%_c.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(ARMGNU)-gcc -g $(COPS) -MMD -c $< -o $@

$(BUILD_DIR)/%_s.o: $(SRC_DIR)/%.S
	mkdir -p $(@D)
	$(ARMGNU)-gcc -g $(COPS) -MMD -c $< -o $@

C_FILES = $(wildcard $(SRC_DIR)/*.c)
ASM_FILES = $(wildcard $(SRC_DIR)/*.S)
OBJ_FILES = $(C_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%_c.o)
OBJ_FILES += $(ASM_FILES:$(SRC_DIR)/%.S=$(BUILD_DIR)/%_s.o)

DEP_FILES = $(OBJ_FILES:%.o=%.d)
-include $(DEP_FILES)

kernel8.img: $(SRC_DIR)/linker.ld $(OBJ_FILES)
	@echo "Building for RPI $(value RPI_VERSION)"
	@echo "Deploy to $(value BOOTMNT)"
	@echo ""
	$(ARMGNU)-ld -T $(SRC_DIR)/linker.ld -g -o $(BUILD_DIR)/kernel8.elf $(OBJ_FILES)
	$(ARMGNU)-objcopy -g $(BUILD_DIR)/kernel8.elf -O binary kernel8.img
ifeq ($(RPI_VERSION), 4)
	cp kernel8.img $(BOOTMNT)
#else
#	cp kernel8.img $(BOOTMNT)/
endif
#	cp config.txt $(BOOTMNT)/
#	sync
