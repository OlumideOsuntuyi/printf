#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

/* Custom data structure to associate format specifiers with their handler functions */
typedef struct st_fmt
{
    char *fmt;
    int (*func)(va_list list);
} st_fmt;

/* Custom printf function */
int _printf(const char *format, ...);

/* Helper function to print a character */
int _putchar(char c);

/* Format specifier handler functions */
int print_char(va_list list, char buffer[], int *printed_chars);
int print_string(va_list list, char buffer[], int *printed_chars);
int print_padded_string(const char *str, int width, char buffer[], int *printed_chars, char padding_char);
int print_percent(char buffer[], int *printed_chars);
int print_integer_with_flags(va_list list, char buffer[], int *printed_chars, char flags);
int print_long_integer(va_list list, char buffer[], int *printed_chars, char specifier);
int print_short_integer(va_list list, char buffer[], int *printed_chars, char specifier);
int print_unsig_integer(va_list list, char buffer[], int *printed_chars, char specifier);
int print_binary_oct_hex(va_list list, char buffer[], int *printed_chars, char specifier, int upper);
int print_reversed_string(const char *str, char buffer[], int *printed_chars);
int print_rot13_string(const char *str, char buffer[], int *printed_chars);

#endif /* MAIN_H */

