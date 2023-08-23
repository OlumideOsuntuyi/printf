#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
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

/* conv_case */
char *convert(unsigned long int num, int base, int lowercase);

/* printf */
int _printf(const char *format, ...);

/* handle_print */
int (*get_print(char s))(va_list, flags_t *);

/* get_flag_func */
int get_flag(char s, flags_t *f);

/* char_string */
int print_string(va_list l, flags_t *f);
int print_char(va_list l, flags_t *f);

/* putchar */
int _putchar(char c);
int _puts(char *str);

/* custom_operators */
int print_rot13(va_list l, flags_t *f);
int print_rev(va_list l, flags_t *f);
int print_bigS(va_list l, flags_t *f);

/* print_addr */
int print_address(va_list l, flags_t *f);

/* print_percent */
int print_percent(va_list l, flags_t *f);

#endif /* MAIN_H */


