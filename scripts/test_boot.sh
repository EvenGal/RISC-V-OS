#!/bin/bash
set -e

make clean && make

timeout 5 qemu-system-riscv64 \
  -machine virt -nographic -bios none -kernel build/kernel.elf \
  | tee qemu_output.txt

grep -q "Hello" qemu_output.txt && echo "Boot test passed" || {
    echo "Boot test failed"
    exit 1
}