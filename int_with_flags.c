#include "main.h"

/**
 * print_integer_with_flags - Print an integer with flag characters
 * @args: Argument list
 * @buffer: Buffer to store printed characters
 * @printed_chars: Pointer to the number of characters printed
 * @flags: Flags for the format specifier
 *
 * Return: Number of characters printed for the integer
 */
int print_integer_with_flags(va_list args, char *buffer, int *printed_chars, char flags)
{
    int num = va_arg(args, int);
    int count = 0;

    if (num < 0)
    {
        buffer[(*printed_chars)++] = '-';
        num = -num;
    }
    else if (flags & PLUS_FLAG)
        buffer[(*printed_chars)++] = '+';
    else if (flags & SPACE_FLAG)
        buffer[(*printed_chars)++] = ' ';

    count += print_integer(num, printed_chars);

    return count;
}

