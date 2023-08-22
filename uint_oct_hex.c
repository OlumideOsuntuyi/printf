#include "main.h"

/**
 * print_unsigned - Print an unsigned integer
 * @args: Argument list
 * @printed_chars: Pointer to the number of characters printed
 *
 * Return: Number of characters printed for the unsigned integer
 */
int print_unsigned(va_list args, int *printed_chars)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    if (num == 0)
    {
        _putchar('0');
        (*printed_chars)++;
        return 1;
    }

    /* Print digits using recursion */
    if (num / 10 != 0)
        count += print_unsigned_rec(num / 10, printed_chars);

    _putchar(num % 10 + '0');
    (*printed_chars)++;
    count++;

    return count;
}

/**
 * print_unsigned_rec - Recursive helper function to print unsigned integers
 * @num: Unsigned integer to print
 * @printed_chars: Pointer to the number of characters printed
 *
 * Return: Number of characters printed for the unsigned integer
 */
int print_unsigned_rec(unsigned int num, int *printed_chars)
{
    int count = 0;

    if (num / 10 != 0)
        count += print_unsigned_rec(num / 10, printed_chars);

    _putchar(num % 10 + '0');
    (*printed_chars)++;
    count++;

    return count;
}

/**
 * print_octal - Print an unsigned integer in octal format
 * @args: Argument list
 * @printed_chars: Pointer to the number of characters printed
 *
 * Return: Number of characters printed for the octal representation
 */
int print_octal(va_list args, int *printed_chars)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;
    int octal[32];  /* Octal representation of the number */

    if (num == 0)
    {
        _putchar('0');
        (*printed_chars)++;
        return 1;
    }

    /* Convert the number to octal */
    for (int i = 0; num > 0; i++)
    {
        octal[i] = num % 8;
        num /= 8;
    }

    /* Print the octal representation */
    for (int i = 31; i >= 0; i--)
    {
        _putchar(octal[i] + '0');
        (*printed_chars)++;
        count++;
    }

    return count;
}

/**
 * print_hex - Print an unsigned integer in hexadecimal format (lowercase)
 * @args: Argument list
 * @printed_chars: Pointer to the number of characters printed
 * @uppercase: Whether to print uppercase hexadecimal (0 = lowercase, 1 = uppercase)
 *
 * Return: Number of characters printed for the hexadecimal representation
 */
int print_hex(va_list args, int *printed_chars, int uppercase)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;
    char hex[16];  /* Hexadecimal representation of the number */

    if (num == 0)
    {
        _putchar('0');
        (*printed_chars)++;
        return 1;
    }

    /* Convert the number to hexadecimal */
    for (int i = 0; num > 0; i++)
    {
        int remainder = num % 16;
        if (remainder < 10)
            hex[i] = remainder + '0';
        else
            hex[i] = (uppercase ? 'A' : 'a') + (remainder - 10);
        num /= 16;
    }

    /* Print the hexadecimal representation */
    for (int i = 15; i >= 0; i--)
    {
        _putchar(hex[i]);
        (*printed_chars)++;
        count++;
    }

    return count;
}

/**
 * print_upper_hex - Print an unsigned integer in uppercase hexadecimal format
 * @args: Argument list
 * @printed_chars: Pointer to the number of characters printed
 *
 * Return: Number of characters printed for the uppercase hexadecimal representation
 */
int print_upper_hex(va_list args, int *printed_chars)
{
    return print_hex(args, printed_chars, 1);
}
