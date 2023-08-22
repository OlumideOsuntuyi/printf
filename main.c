#include "main.h"

int main(void)
{
    int printed_chars = 0;

    _printf("Hello, world!\n");
    _printf("Integer: %d\n", 12345);
    _printf("String: %s\n", "Custom printf implementation");
    _printf("Character: %c\n", 'A');
    _printf("Percentage: %%\n");
    _printf("Binary: %b\n", 42);
    _printf("Hexadecimal (lowercase): %x\n", 255);
    _printf("Hexadecimal (uppercase): %X\n", 255);
    _printf("Unsigned Integer: %u\n", 98765);
    _printf("Octal: %o\n", 63);
    _printf("Pointer: %p\n", (void *)0x12345678);
    _printf("Reversed String: %r\n", "Hello, world!");
    _printf("ROT13: %R\n", "Hello, world!");
    _printf("Non-Printable String: %S\n", "Hello\n\x7F\x80\xFF");
    
    return (0);
}

