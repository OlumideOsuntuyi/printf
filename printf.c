#include <stdarg.h>
#include "main.h"

/**
 * Prints formatted output to the standard output.
 *
 * @param format The format string containing the specifiers.
 * @param ... Variadic arguments to be formatted.
 *
 * @return The number of characters printed.
 */
int _printf(const char *format, ...) {
    va_list args;
    int printed_chars = 0;

    va_start(args, format);
    select_print_function(format, args, &printed_chars);
    va_end(args);

    return printed_chars;
}

