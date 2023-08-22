#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

#define PLUS_FLAG   (1 << 0)
#define SPACE_FLAG  (1 << 1)


/* SIZES */
#define BUFSIZE 1024

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

int print_char(va_list args, int *printed_chars);
int print_string(va_list args, int *printed_chars);
int print_percent(int *printed_chars);
int print_integer_with_flags(va_list args, char *buffer, int *printed_chars, char flags);
int print_long_integer(va_list args, char *buffer, int *printed_chars, char specifier);
int print_short_integer(va_list args, char *buffer, int *printed_chars, char specifier);
int print_binary(va_list args, int *printed_chars);
int print_integer(va_list args, int *printed_chars);
int print_unsigned(va_list args, int *printed_chars);
int print_octal(va_list args, int *printed_chars);
int print_hex(va_list args, int *printed_chars, int uppercase);
int print_upper_hex(va_list args, int *printed_chars);
int print_pointer(va_list args, char *buffer, int *printed_chars);
int print_reversed_string(const char *str, char *buffer, int *printed_chars);
int print_rot13_string(const char *str, char *buffer, int *printed_chars);
int print_string_non_printable(va_list args, char *buffer, int *printed_chars);

void select_print_function(const char *format, va_list args, int *printed_chars)
#endif /* MAIN_H */


