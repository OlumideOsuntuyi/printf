#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    int i, j;
    char buffer[1024] = {0};  // Buffer to store printed characters
    char flags = 0;  // Placeholder for flags (modify as needed)
    
    format_specifier_t specifiers[] = {
        {'c', print_char},
        {'s', print_string},
        {'%', print_percent},
        {'d', print_integer_with_flags},
        {'i', print_integer_with_flags},
        {'l', print_long_integer},
        {'h', print_short_integer},
        {'b', print_binary},
        {'u', print_unsigned},
        {'o', print_octal},
        {'x', print_hex},
        {'X', print_upper_hex},
        {'p', print_pointer},
        {'r', print_reversed_string},
        {'R', print_rot13_string},
        {'N', print_string_non_printable},
        {0, NULL}
    };

    va_start(args, format);

    for (i = 0; format && format[i]; i++)
    {
        if (format[i] == '%')
        {
            i++;
            for (j = 0; specifiers[j].specifier; j++)
            {
                if (format[i] == specifiers[j].specifier)
                {
                    printed_chars += specifiers[j].func(args, buffer, &printed_chars, flags);
                    break;
                }
            }
        }
        else
        {
            buffer[printed_chars++] = format[i];
        }
    }

    va_end(args);
    
    // Print the remaining characters in the buffer
    write(1, buffer, printed_chars);
    
    return printed_chars;
}
