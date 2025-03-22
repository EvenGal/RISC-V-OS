CROSS=riscv64-unknown-elf
CFLAGS=-Wall -O0 -nostdlib -nostartfiles -ffreestanding
LDFLAGS=-Tlinker.ld -nostdlib -nostartfiles

SRC=src
BUILD=build

OBJS=$(BUILD)/boot.o $(BUILD)/kernel.o

all: $(BUILD)/kernel.elf

$(BUILD)/kernel.elf: $(OBJS)
	$(CROSS)-gcc $(LDFLAGS) -o $@ $^

$(BUILD)/boot.o: $(SRC)/boot.S
	@mkdir -p $(BUILD)
	$(CROSS)-gcc $(CFLAGS) -c -o $@ $<

$(BUILD)/kernel.o: $(SRC)/kernel.c
	$(CROSS)-gcc $(CFLAGS) -c -o $@ $<

run: all
	qemu-system-riscv64 -machine virt -nographic -bios none -kernel $(BUILD)/kernel.elf

clean:
	rm -rf $(BUILD)

