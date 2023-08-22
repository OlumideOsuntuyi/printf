#include "main.h"

/**
 * print_char - Print a character
 * @args: Argument list
 * @printed_chars: Number of characters printed
 *
 * Return: Number of characters printed
 */
int print_char(va_list args, int *printed_chars)
{
    _putchar(va_arg(args, int));
    (*printed_chars)++;
    return 1;
}

/**
 * print_string - Print a string
 * @args: Argument list
 * @printed_chars: Number of characters printed
 *
 * Return: Number of characters printed
 */
int print_string(va_list args, int *printed_chars)
{
    char *str = va_arg(args, char *);
    int i = 0, count = 0;

    while (str[i])
    {
        _putchar(str[i]);
        i++;
        count++;
    }

    (*printed_chars) += count;
    return count;
}

/**
 * print_percent - Print a percent sign
 * @printed_chars: Number of characters printed
 *
 * Return: Number of characters printed
 */
int print_percent(int *printed_chars)
{
    _putchar('%');
    (*printed_chars)++;
    return 1;
}
