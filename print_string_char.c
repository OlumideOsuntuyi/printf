#include "main.h"

/**
 * print_string - Loops through a string and prints every character
 * @l: va_list arguments from _printf
 * @f: Pointer to the struct flags that determines if a flag is passed to _printf
 *
 * Description: This function takes a string argument from the va_list and
 * prints each character of the string. If the string is NULL, it prints "(null)".
 * Return: Number of characters printed
 */
int print_string(va_list l, flags_t *f)
{
	char *s = va_arg(l, char *);

	(void)f;  /* Unused parameter */

	if (!s)
		s = "(null)";  /* Print "(null)" for NULL strings */
	return (_puts(s));  /* Call _puts to print the string */
}

/**
 * print_char - Prints a single character
 * @l: va_list arguments from _printf
 * @f: Pointer to the struct flags that determines if a flag is passed to _printf
 *
 * Description: This function takes a character argument from the va_list and
 * prints the character. It doesn't use any flags.
 * Return: Number of characters printed (always 1 for a single character)
 */
int print_char(va_list l, flags_t *f)
{
	(void)f;  /* Unused parameter */
	_putchar(va_arg(l, int));  /* Print the character using _putchar */
	return (1);  /* Return 1 as only one character is printed */
}

