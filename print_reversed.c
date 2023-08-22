#include "main.h"

/**
 * print_reversed_string - Print a string in reverse
 * @str: String to print
 * @buffer: Buffer to store printed characters
 * @printed_chars: Pointer to the number of characters printed
 *
 * Return: Number of characters printed for the reversed string
 */
int print_reversed_string(const char *str, char *buffer, int *printed_chars)
{
    int count = 0;

    /* Calculate the length of the string */
    int length = strlen(str);

    /* Print the string in reverse */
    for (int i = length - 1; i >= 0; i--)
    {
        buffer[(*printed_chars)++] = str[i];
        count++;
    }

    return count;
}
