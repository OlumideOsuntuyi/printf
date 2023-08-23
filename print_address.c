#include "main.h"

/**
 * print_address - Prints the address of input in hexadecimal format
 * @l: va_list arguments from _printf
 * @f: Pointer to the struct flags that determines if a flag is passed to _printf
 *
 * Description: This function prints the memory address of the input value
 * in hexadecimal format. It uses the convert function to convert the address
 * to a hexadecimal string.
 * Return: Number of characters printed
 */
int print_address(va_list l, flags_t *f)
{
	char *hex_str;
	unsigned long int address = va_arg(l, unsigned long int);

	register int count = 0;

	(void)f;

	if (!address)
		return (_puts("(nil)"));  /* Print "(nil)" for NULL addresses */
	hex_str = convert(address, 16, 1);
	count += _puts("0x");  /* Print "0x" before the hexadecimal address */
	count += _puts(hex_str);  /* Print the hexadecimal address */
	return (count);
}

