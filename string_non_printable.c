#include "main.h"

/**
 * print_string_non_printable - Print a string with escaped non-printable characters
 * @args: Argument list
 * @buffer: Buffer to store printed characters
 * @printed_chars: Pointer to the number of characters printed
 *
 * Return: Number of characters printed for the string
 */
int print_string_non_printable(va_list args, char *buffer, int *printed_chars)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (!str)
        str = "(null)";

    for (int i = 0; str[i]; i++)
    {
        if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
        {
            /* Print non-printable character as \x followed by ASCII code */
            count += snprintf(buffer + *printed_chars, 1024 - *printed_chars,
                              "\\x%02X", (unsigned char)str[i]);
            (*printed_chars) += count;
        }
        else
        {
            buffer[*printed_chars] = str[i];
            (*printed_chars)++;
            count++;
        }

        /* Flush buffer if it's full */
        if (*printed_chars == 1024)
        {
            write(1, buffer, *printed_chars);
            *printed_chars = 0;
        }
    }

    return count;
}
