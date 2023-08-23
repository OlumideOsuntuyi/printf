#include "main.h"

/**
 * convert - converts a number to a string representation in a given base
 * @num: the input number
 * @base: the base for conversion
 * @lowercase: flag to indicate if hexa values should be lowercase
 *
 * Return: the result string
 */
char *convert(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}

