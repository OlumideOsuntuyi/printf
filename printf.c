#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    char buffer[1024];  /* Buffer to store printed characters */
    int i = 0;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
                break;
            switch (format[i])
            {
                case 'c':
                    printed_chars += print_char(args, &printed_chars);
                    i++;
                    break;
                case 's':
                    printed_chars += print_string(args, &printed_chars);
                    i++;
                    break;
                case '%':
                    printed_chars += print_percent(&printed_chars);
                    i++;
                    break;
                case 'd':
                case 'i':
                    printed_chars += print_integer_with_flags(args, buffer, &printed_chars, 0);
                    i++;
                    break;
                case 'u':
                    printed_chars += print_long_integer(args, buffer, &printed_chars, 'u');
                    i++;
                    break;
                case 'o':
                    printed_chars += print_octal(args, &printed_chars);
                    i++;
                    break;
                case 'x':
                    printed_chars += print_hex(args, &printed_chars, 0);
                    i++;
                    break;
                case 'X':
                    printed_chars += print_upper_hex(args, &printed_chars);
                    i++;
                    break;
                case 'p':
                    printed_chars += print_pointer(args, buffer, &printed_chars);
                    i++;
                    break;
                case 'r':
                    {
                        const char *str = va_arg(args, const char *);
                        printed_chars += print_reversed_string(str, buffer, &printed_chars);
                        i++;
                        break;
                    }
                case 'R':
                    {
                        const char *str = va_arg(args, const char *);
                        printed_chars += print_rot13_string(str, buffer, &printed_chars);
                        i++;
                        break;
                    }
                case 'S':
                    printed_chars += print_string_non_printable(args, buffer, &printed_chars);
                    i++;
                    break;
                default:
                    buffer[printed_chars++] = format[i++];
            }
        }
        else
            buffer[printed_chars++] = format[i++];
    }

    write(1, buffer, printed_chars);

    va_end(args);

    return printed_chars;
}

