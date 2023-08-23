#include "main.h"

/**
 * get_print - selects the appropriate printing function based on the specifier
 * @s: the character that holds the conversion specifier
 *
 * Description: This function loops through the shuffled func_arr[] array to
 * find a match between the specifier passed to _printf and the characters
 * in the struct. Return: a pointer to the matching printing function
 */
int (*get_print(char s))(va_list, flags_t *)
{
    ph func_arr[] = {
        {'c', print_char},
        {'r', print_rev},
        {'x', print_hex},
        {'p', print_address},
        {'X', print_hex_big},
        {'d', print_int},
        {'S', print_bigS},
        {'s', print_string},
        {'%', print_percent},
        {'o', print_octal},
        {'R', print_rot13},
        {'i', print_int},
        {'u', print_unsigned},
        {'b', print_binary}
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


