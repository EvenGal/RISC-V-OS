#define UART0_ADDR 0x10000000

void putchar(char c) {
    *(volatile char *)UART0_ADDR = c;
}

void kmain() {
    putchar('H');
    putchar('e');
    putchar('l');
    putchar('l');
    putchar('o');
    putchar(',');
    putchar(' ');
    putchar('R');
    putchar('I');
    putchar('S');
    putchar('C');
    putchar('-');
    putchar('V');
    putchar(' ');
    putchar('!');
    putchar('\n');

    while (1);
}

