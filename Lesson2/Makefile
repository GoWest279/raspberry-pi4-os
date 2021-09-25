CFILES = $(wildcard *.c)
OFILES = $(CFILES:.c=.o)
GCCFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles
#GCCPATH = ../../gcc-arm-10.3-2021.07-x86_64-aarch64-none-elf/bin
GCC = aarch64-linux-gnu-gcc
all: clean kernel8.img

boot.o: boot.S
	$(GCC) $(GCCFLAGS) -c boot.S -o boot.o

%.o: %.c
	$(GCC) $(GCCFLAGS) -c $< -o $@

kernel8.img: boot.o $(OFILES)
	aarch64-linux-gnu-ld -nostdlib boot.o $(OFILES) -T link.ld -o kernel8.elf
	aarch64-linux-gnu-objcopy -O binary kernel8.elf kernel8.img

clean:
	/bin/rm kernel8.elf *.o *.img > /dev/null 2> /dev/null || true

run:
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -serial null -serial stdio
