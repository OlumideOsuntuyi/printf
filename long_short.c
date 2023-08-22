#include "main.h"

/**
 * print_long_integer - Print a long integer
 * @args: Argument list
 * @buffer: Buffer to store printed characters
 * @printed_chars: Pointer to the number of characters printed
 * @specifier: Conversion specifier ('d', 'i', 'u', 'o', 'x', or 'X')
 *
 * Return: Number of characters printed for the long integer
 */
int print_long_integer(va_list args, char *buffer, int *printed_chars, char specifier)
{
    long int num = va_arg(args, long int);
    int count = 0;

    if (specifier == 'd' || specifier == 'i')
        count += print_number(num, buffer, printed_chars);
    else if (specifier == 'u')
        count += print_unsigned_number((unsigned long int)num, buffer, printed_chars);
    else if (specifier == 'o')
        count += print_octal_number((unsigned long int)num, buffer, printed_chars);
    else if (specifier == 'x' || specifier == 'X')
        count += print_hex_number((unsigned long int)num, buffer, printed_chars, specifier);

    return count;
}

/**
 * print_short_integer - Print a short integer
 * @args: Argument list
 * @buffer: Buffer to store printed characters
 * @printed_chars: Pointer to the number of characters printed
 * @specifier: Conversion specifier ('d', 'i', 'u', 'o', 'x', or 'X')
 *
 * Return: Number of characters printed for the short integer
 */
int print_short_integer(va_list args, char *buffer, int *printed_chars, char specifier)
{
    int num = (short int)va_arg(args, int);
    int count = 0;

    if (specifier == 'd' || specifier == 'i')
        count += print_number(num, buffer, printed_chars);
    else if (specifier == 'u')
        count += print_unsigned_number((unsigned int)num, buffer, printed_chars);
    else if (specifier == 'o')
        count += print_octal_number((unsigned int)num, buffer, printed_chars);
    else if (specifier == 'x' || specifier == 'X')
        count += print_hex_number((unsigned int)num, buffer, printed_chars, specifier);

    return count;
}
