#define UART0_ADDR 0x10000000
#define UART0_LSR  0x10000005

void putchar(char c) {
    *(volatile char *)UART0_ADDR = c;
}

char getchar() {
    while ((*(volatile char *)UART0_LSR & 0x01) == 0);
    return *(volatile char *)UART0_ADDR;
}

void print(const char *s) {
    while (*s) putchar(*s++);
}

void print_prompt() {
    putchar('>');
    putchar(' ');
}

void print_typed() {
    putchar('Y'); putchar('o'); putchar('u'); putchar(' ');
    putchar('t'); putchar('y'); putchar('p'); putchar('e');
    putchar('d'); putchar(':'); putchar(' ');
}

void kmain() {
    char line[128];
    int index = 0;

    print_prompt();

    while (1) {
        char c = getchar();

        if (c == '\r') { 
            putchar('\r');
            putchar('\n');

            line[index] = '\0'; 
            print_typed();
            print(line);
            putchar('\r');
            putchar('\n');

            index = 0;           
            print_prompt();
        } else if (c == '\b' || c == 127) {
            if (index > 0) {
                index--;
                putchar('\b');
                putchar(' ');
                putchar('\b');       
            }
        } else if (index < 127) {
            line[index++] = c;
            putchar(c); 
        }
    }
}