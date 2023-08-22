#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct format_specifier - Struct for format specifiers and corresponding functions
 * @specifier: The format specifier
 * @func: The corresponding function to handle the specifier
 */
typedef struct format_specifier
{
    char specifier;
    int (*func)(va_list args, char *buffer, int *printed_chars, char flags);
} format_specifier_t;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args, char *buffer, int *printed_chars, char flags);
int print_string(va_list args, char *buffer, int *printed_chars, char flags);
int print_percent(va_list args, char *buffer, int *printed_chars, char flags);
int print_integer_with_flags(va_list args, char *buffer, int *printed_chars, char flags);
int print_long_integer(va_list args, char *buffer, int *printed_chars, char specifier);
int print_short_integer(va_list args, char *buffer, int *printed_chars, char specifier);
int print_binary(va_list args, char *buffer, int *printed_chars, char flags);
int print_integer(va_list args, char *buffer, int *printed_chars, char flags);
int print_unsigned(va_list args, char *buffer, int *printed_chars, char flags);
int print_octal(va_list args, char *buffer, int *printed_chars, char flags);
int print_hex(va_list args, char *buffer, int *printed_chars, char flags);
int print_upper_hex(va_list args, char *buffer, int *printed_chars, char flags);
int print_pointer(va_list args, char *buffer, int *printed_chars, char flags);
int print_reversed_string(const char *str, char *buffer, int *printed_chars, char flags);
int print_rot13_string(const char *str, char *buffer, int *printed_chars, char flags);
int print_string_non_printable(va_list args, char *buffer, int *printed_chars, char flags);

#endif /* MAIN_H */

