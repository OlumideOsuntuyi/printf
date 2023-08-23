#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes the character c to stdout
 * @c: The character to print
 * Return: On success, 1. On error, -1 is returned, and errno is set appropriately.
 *
 * Description: _putchar uses a local buffer of 1024 to call write as little as possible.
 */
int _putchar(char c)
{
	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);  /* Write the buffer to stdout */
		i = 0;  /* Reset the buffer index */
	}
	if (c != -1)
	{
		buf[i] = c;  /* Add character to buffer */
		i++;
	}
	return (1);
}

/**
 * _puts - Prints a string to stdout
 * @str: Pointer to the string to print
 * Return: Number of characters written
 *
 * Description: This function loops through the string and calls _putchar to print each character.
 */
int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);  /* Call _putchar for each character */
	return (i);
}

