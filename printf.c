#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Variable number of arguments
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int len = 0, printed_chars = 0, total_printed = 0;
    char buffer[1024];      /* Local buffer for printing */

    if (!format)
        return -1;

    va_start(args, format);

    while (format[len])
    {
        if (format[len] == '%')
        {
            len++;

            /* Handle format specifiers */
            if (format[len] == 'c')
                total_printed += print_char(args, buffer, &printed_chars);
            else if (format[len] == 's')
            {
                char *str = va_arg(args, char *);
                if (!str)
                    str = "(null)";
                total_printed += width ? print_padded_string(str, width, buffer, &printed_chars, padding_char) : print_string(args, buffer, &printed_chars);
            }
            else if (format[len] == '%')
                total_printed += print_percent(buffer, &printed_chars);
            else if (strchr("diouxX", format[len]) != NULL)
            {
                if (length & LONG_FLAG)
                    total_printed += print_long_integer(args, buffer, &printed_chars, format[len]);
                else if (length & SHORT_FLAG)
                    total_printed += print_short_integer(args, buffer, &printed_chars, format[len]);
                else
                    total_printed += print_integer_with_flags(args, buffer, &printed_chars, flags);
            }
            else if (format[len] == 'r' || format[len] == 'R')
            {
                char *str = va_arg(args, char *);
                if (!str)
                    str = "(null)";
                total_printed += format[len] == 'r' ? print_reversed_string(str, buffer, &printed_chars) : print_rot13_string(str, buffer, &printed_chars);
            }
            // Handle other conversion specifiers and custom specifiers here
        }
        else
        {
            /* Add the character to the buffer */
            buffer[printed_chars++] = format[len];
            total_printed++;
        }

        /* Flush buffer if it's full or at end of format */
        if (printed_chars == 1024 || format[len + 1] == '\0')
        {
            write(1, buffer, printed_chars);
            printed_chars = 0;
        }

        len++;
    }

    va_end(args);

    return total_printed;
}

