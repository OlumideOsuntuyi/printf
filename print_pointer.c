#include "main.h"

/**
 * print_pointer - Print a memory address
 * @args: Argument list
 * @buffer: Buffer to store printed characters
 * @printed_chars: Pointer to the number of characters printed
 *
 * Return: Number of characters printed for the memory address
 */
int print_pointer(va_list args, char *buffer, int *printed_chars)
{
    void *ptr = va_arg(args, void *);
    unsigned long int num = (unsigned long int)ptr;
    int count = 0;
    char hex[16];  /* Hexadecimal representation of the memory address */

    buffer[(*printed_chars)++] = '0';
    buffer[(*printed_chars)++] = 'x';

    /* Convert the memory address to hexadecimal */
    for (int i = 0; i < 16; i++)
    {
        int remainder = num % 16;
        if (remainder < 10)
            hex[i] = remainder + '0';
        else
            hex[i] = 'a' + (remainder - 10);
        num /= 16;
    }

    /* Print the hexadecimal representation */
    for (int i = 15; i >= 0; i--)
    {
        buffer[*printed_chars] = hex[i];
        (*printed_chars)++;
        count++;
    }

    return count;
}
