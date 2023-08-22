ALX Printf project

This repository contains a custom `printf` function implemented in C, following the guidelines and requirements provided. The custom `printf` function supports various format specifiers and provides functionality similar to the standard library `printf` function.

## Function Details

### int _printf(const char *format, ...)

The main custom `printf` function that takes a format string and a variable number of arguments, similar to the standard library `printf`.

### int _putchar(char c)

Helper function to print a single character to the standard output.

### Format Specifier Handler Functions

The following functions handle different format specifiers and are used by the main `_printf` function to perform specific printing tasks:

- `print_char(va_list list, char buffer[], int *printed_chars)`: Print a single character.
- `print_string(va_list list, char buffer[], int *printed_chars)`: Print a string.
- `print_padded_string(const char *str, int width, char buffer[], int *printed_chars, char padding_char)`: Print a padded string with specified width and padding character.
- `print_percent(char buffer[], int *printed_chars)`: Print a percentage character.
- `print_integer_with_flags(va_list list, char buffer[], int *printed_chars, char flags)`: Print an integer with specified flags.
- `print_long_integer(va_list list, char buffer[], int *printed_chars, char specifier)`: Print a long integer with specified format.
- `print_short_integer(va_list list, char buffer[], int *printed_chars, char specifier)`: Print a short integer with specified format.
- `print_unsig_integer(va_list list, char buffer[], int *printed_chars, char specifier)`: Print an unsigned integer with specified format.
- `print_binary_oct_hex(va_list list, char buffer[], int *printed_chars, char specifier, int upper)`: Print a binary, octal, or hexadecimal number with specified format.
- `print_reversed_string(const char *str, char buffer[], int *printed_chars)`: Print a reversed string.
- `print_rot13_string(const char *str, char buffer[], int *printed_chars)`: Print a string encoded in ROT13.

