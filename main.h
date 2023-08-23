#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct printHandler - Struct to map format specifiers to functions
 * @c: Format specifier character
 * @f: Pointer to the corresponding printing function
 */
typedef struct printHandler
{
    char c;
    int (*f)(va_list ap, flags_t *f);
} ph;

/**
 * struct flags - Struct to hold formatting flags for _printf
 * @plus: Flag for the '+' character
 * @space: Flag for the ' ' character
 * @hash: Flag for the '#' character
 */
typedef struct flags
{
    int plus;
    int space;
    int hash;
} flags_t;

/* print_nums */
int print_int(va_list l, flags_t *f);
void print_number(int n);
int print_unsigned(va_list l, flags_t *f);
int count_digit(int i);

/* print_bases */
int print_hex(va_list l, flags_t *f);
int print_hex_big(va_list l, flags_t *f);
int print_binary(va_list l, flags_t *f);
int print_octal(va_list l, flags_t *f);

/* converter */
/**
 * convert - Converts a number to a string representation in a given base
 * @num: The input number
 * @base: The base for conversion
 * @lowercase: Flag indicating if hexa values should be lowercase
 *
 * Return: The result string
 */
char *convert(unsigned long int num, int base, int lowercase);

/* _printf */
/**
 * _printf - Produces output according to a format
 * @format: Format string containing the characters and the specifiers
 *
 * Description: This function formats and prints the output according to the
 * format string. It handles various conversion specifiers.
 * Return: Length of the formatted output string
 */
int _printf(const char *format, ...);

/* get_print_func */
int (*handle_print(char s))(va_list, flags_t *);

/* get_func_flag */
int get_flag(char s, flags_t *f);

/* print_string and char */
int print_string(va_list l, flags_t *f);
int print_char(va_list l, flags_t *f);

/* write_funcs */
int _putchar(char c);
int _puts(char *str);

/* print_custom operators*/
int print_rot13(va_list l, flags_t *f);
int print_reverse(va_list l, flags_t *f);
int print_upperS(va_list l, flags_t *f);

/* print_address */
int print_address(va_list l, flags_t *f);

/* print_percent */
int print_percent(va_list l, flags_t *f);

#endif /* MAIN_H */


