#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _putchar(char c);

int print_char(va_list args, int *printed_chars);
int print_string(va_list args, int *printed_chars);
int print_percent(int *printed_chars);
int print_integer_with_flags(va_list args, char *buffer, int *printed_chars, char flags);
int print_long_integer(va_list args, char *buffer, int *printed_chars, char specifier);
int print_short_integer(va_list args, char *buffer, int *printed_chars, char specifier);
int print_binary(va_list args, int *printed_chars);
int print_integer(va_list args, int *printed_chars);
int print_integer_rec(int num, int *printed_chars);
int print_padded_string(const char *str, int width, char *buffer, int *printed_chars, char padding_char);
int print_pointer(va_list args, char *buffer, int *printed_chars);
int print_reversed_string(const char *str, char *buffer, int *printed_chars);
int print_rot13_string(const char *str, char *buffer, int *printed_chars);
int print_string_non_printable(va_list args, char *buffer, int *printed_chars);
int print_unsigned(va_list args, int *printed_chars);
int print_unsigned_rec(unsigned int num, int *printed_chars);
int print_octal(va_list args, int *printed_chars);
int print_hex(va_list args, int *printed_chars, int uppercase);
int print_upper_hex(va_list args, int *printed_chars);

int _printf(const char *format, ...);

#endif /* MAIN_H */

