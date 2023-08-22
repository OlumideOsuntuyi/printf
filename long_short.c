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
        count += print_integer(num, printed_chars);
    else if (specifier == 'u')
        count += print_unsigned((unsigned long int)num, printed_chars);
    else if (specifier == 'o')
        count += print_octal((unsigned long int)num, printed_chars);
    else if (specifier == 'x' || specifier == 'X')
    {
         if(specifier == 'X')
         {
             count += print_hex((unsigned long int)num, printed_chars);           
         }else
         {
              count += print_hex_upper((unsigned long int)num, printed_chars);
         }
    }

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
        count += print_integer(num, printed_chars);
    else if (specifier == 'u')
        count += print_unsigned((unsigned int)num, printed_chars);
    else if (specifier == 'o')
        count += print_octal((unsigned int)num, printed_chars);
    else if (specifier == 'x' || specifier == 'X')
    {
         if(specifier == 'X')
         {
             count += print_hex((unsigned int)num, printed_chars);           
         }else
         {
              count += print_hex_upper((unsigned int)num, printed_chars);
         }
    }

    return count;
}

