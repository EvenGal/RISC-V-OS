.section .text
.global _start

_start:
	la sp, stack_top
	call kmain
	j .

.section .bss
.balign 16
stack: .skip 4096
stack_top:
