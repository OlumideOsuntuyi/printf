#include "main.h"

/**
 * print_int - Prints an integer
 * @l: va_list of arguments from _printf
 * @f: Pointer to the struct flags determining if a flag is passed to _printf
 *
 * Description: This function takes an integer argument from the va_list and
 * prints the integer. It handles formatting based on flags like space and plus.
 * Return: Number of characters printed
 */
int print_int(va_list l, flags_t *f)
{
	int n = va_arg(l, int);
	int res = count_digit(n);

	if (f->space == 1 && f->plus == 0 && n >= 0)
		res += _putchar(' ');  /* Add a space if space flag is set */
	if (f->plus == 1 && n >= 0)
		res += _putchar('+');  /* Add a plus sign if plus flag is set */
	if (n <= 0)
		res++;
	print_number(n);  /* Print the integer */
	return (res);
}

/**
 * print_unsigned - Prints an unsigned integer
 * @l: va_list of arguments from _printf
 * @f: Pointer to the struct flags determining if a flag is passed to _printf
 *
 * Description: This function takes an unsigned integer argument from the va_list
 * and prints the unsigned integer.
 * Return: Number of characters printed
 */
int print_unsigned(va_list l, flags_t *f)
{
	unsigned int u = va_arg(l, unsigned int);
	char *str = convert(u, 10, 0);

	(void)f;  /* Unused parameter */
	return (_puts(str));  /* Print the unsigned integer string */
}

/**
 * print_number - Helper function that prints all digits of an integer
 * @n: Integer to be printed
 *
 * Description: This function recursively prints each digit of the integer.
 */
void print_number(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		print_number(n1 / 10);  /* Recursively print digits */
	_putchar((n1 % 10) + '0');  /* Print the last digit */
}

/**
 * count_digit - Returns the number of digits in an integer
 * @i: Integer to evaluate
 *
 * Description: This function calculates the number of digits in an integer.
 * Return: Number of digits
 */
int count_digit(int i)
{
	unsigned int d = 0;
	unsigned int u;

	if (i < 0)
		u = i * -1;
	else
		u = i;
	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
}

