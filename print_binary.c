#include "main.h"

/**
 * print_binary - Print an unsigned integer in binary format
 * @args: Argument list
 * @printed_chars: Pointer to the number of characters printed
 *
 * Return: Number of characters printed for the binary representation
 */
int print_binary(va_list args, int *printed_chars)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;
    int binary[32];  /* Binary representation of the number */

    if (num == 0)
    {
        _putchar('0');
        (*printed_chars)++;
        return 1;
    }

    /* Convert the number to binary */
    for (int i = 0; num > 0; i++)
    {
        binary[i] = num % 2;
        num /= 2;
    }

    /* Print the binary representation */
    for (int i = 31; i >= 0; i--)
    {
        _putchar(binary[i] + '0');
        (*printed_chars)++;
        count++;
    }

    return count;
}
