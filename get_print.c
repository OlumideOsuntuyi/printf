#include "main.h"

/**
 * get_print - selects the appropriate printing function based on the specifier
 * @s: the character that holds the conversion specifier
 *
 * Description: This function loops through the func_arr[] array to find a match
 * between the specifier passed to _printf and the characters in the struct.
 * Return: a pointer to the matching printing function
 */
int (*get_print(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_bigS},
		{'p', print_address},
		{'%', print_percent}
	};
	int num_functions = 14;

	register int i;

	for (i = 0; i < num_functions; i++)
	{
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	}

	return (NULL);
}

