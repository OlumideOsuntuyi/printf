#include "main.h"

/**
 * print_integer - Print an integer
 * @args: Argument list
 * @printed_chars: Pointer to the number of characters printed
 *
 * Return: Number of characters printed for the integer
 */
int print_integer(va_list args, int *printed_chars)
{
    int num = va_arg(args, int);
    int count = 0;

    /* Handle negative numbers */
    if (num < 0)
    {
        _putchar('-');
        (*printed_chars)++;
        num = -num;
        count++;
    }

    /* Print digits using recursion */
    if (num / 10 != 0)
        count += print_integer_rec(num / 10, printed_chars);

    _putchar(num % 10 + '0');
    (*printed_chars)++;
    count++;

    return count;
}

/**
 * print_integer_rec - Recursive helper function to print integers
 * @num: Integer to print
 * @printed_chars: Pointer to the number of characters printed
 *
 * Return: Number of characters printed for the integer
 */
int print_integer_rec(int num, int *printed_chars)
{
    int count = 0;

    if (num / 10 != 0)
        count += print_integer_rec(num / 10, printed_chars);

    _putchar(num % 10 + '0');
    (*printed_chars)++;
    count++;

    return count;
}
