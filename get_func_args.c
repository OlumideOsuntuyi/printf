#include "main.h"
#include <stdarg.h>

/**
 * Selects the appropriate function based on the format specifier.
 * Calls the corresponding function to print the formatted output.
 *
 * @param format The format string containing the specifier.
 * @param args The variadic arguments passed to _printf.
 * @param printed_chars A pointer to the total count of printed characters.
 */
 
void select_print_function(const char *format, va_list args, int *printed_chars) {
    char specifier;
    char buffer[BUFSIZE];

    while (*format) {
        if (*format == '%') {
            format++;
            specifier = *format;
            format++;

            switch (specifier) {
                case 'c':
                    print_char(args, printed_chars);
                    break;
                case 's':
                    print_string(args, printed_chars);
                    break;
                case '%':
                    print_percent(printed_chars);
                    break;
                case 'd':
                case 'i':
                    print_integer_with_flags(args, buffer, printed_chars, 0);
                    break;
                case 'l':
                    specifier = *format;
                    format++;
                    if (specifier == 'd' || specifier == 'i') {
                        print_long_integer(args, buffer, printed_chars, specifier);
                    }
                    break;
                case 'h':
                    specifier = *format;
                    format++;
                    if (specifier == 'd' || specifier == 'i') {
                        print_short_integer(args, buffer, printed_chars, specifier);
                    }
                    break;
                case 'b':
                    print_binary(args, printed_chars);
                    break;
                case 'u':
                    print_unsigned(args, printed_chars);
                    break;
                case 'o':
                    print_octal(args, printed_chars);
                    break;
                case 'x':
                    print_hex(args, printed_chars, 0);
                    break;
                case 'X':
                    print_upper_hex(args, printed_chars);
                    break;
                case 'p':
                    print_pointer(args, buffer, printed_chars);
                    break;
                case 'R':
                    print_reversed_string(va_arg(args, const char *), buffer, printed_chars);
                    break;
                case 'T':
                    print_rot13_string(va_arg(args, const char *), buffer, printed_chars);
                    break;
                case 'N':
                    print_string_non_printable(args, buffer, printed_chars);
                    break;
                default:
                    
                    break;
            }
        } else {
            _putchar(*format);
            (*printed_chars)++;
            format++;
        }
    }
}

