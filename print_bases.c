#include "main.h"

/**
 * print_binary - Prints a number in base 2
 * @l: va_list arguments from _printf
 * @f: Pointer to the struct that determines if a flag is passed to _printf
 *
 * Description: The function calls convert() to convert the input number into
 * binary representation and returns it as a string.
 * Return: Number of characters printed
 */
int print_binary(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 2, 0);

	(void)f;  /* Unused parameter */
	return (_puts(str));  /* Print the binary string */
}

/**
 * print_hex - Prints a number in hexadecimal base, in lowercase
 * @l: va_list arguments from _printf
 * @f: Pointer to the struct flags that determines if a flag is passed to _printf
 *
 * Description: The function calls convert() to convert the input number into
 * hexadecimal representation and returns it as a string. If the hash flag is
 * set, it adds "0x" before the string.
 * Return: Number of characters printed
 */
int print_hex(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 16, 1);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += _puts("0x");  /* Print "0x" for non-zero values */
	count += _puts(str);  /* Print the hexadecimal string */
	return (count);
}

/**
 * print_octal - Prints a number in base 8
 * @l: va_list arguments from _printf
 * @f: Pointer to the struct that determines if a flag is passed to _printf
 *
 * Description: The function calls convert() to convert the input number into
 * octal representation and returns it as a string. If the hash flag is set,
 * it adds "0" before the string.
 * Return: Number of characters printed
 */
int print_octal(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 8, 0);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += _putchar('0');  /* Print "0" for non-zero values */
	count += _puts(str);  /* Print the octal string */
	return (count);
}

/**
 * print_hex_big - Prints a number in hexadecimal base, in uppercase
 * @l: va_list arguments from _printf
 * @f: Pointer to the struct that determines if a flag is passed to _printf
 *
 * Description: The function calls convert() to convert the input number into
 * hexadecimal representation (uppercase) and returns it as a string. If the
 * hash flag is set, it adds "0X" before the string.
 * Return: Number of characters printed
 */
int print_hex_big(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 16, 0);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += _puts("0X");  /* Print "0X" for non-zero values */
	count += _puts(str);  /* Print the hexadecimal string */
	return (count);
}

