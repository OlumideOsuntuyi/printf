#include "main.h"

/**
 * print_padded_string - Print a string with padded spaces or zeros
 * @str: String to print
 * @width: Field width
 * @buffer: Buffer to store printed characters
 * @printed_chars: Pointer to the number of characters printed
 * @padding_char: Character for padding (' ' or '0')
 *
 * Return: Number of characters printed for the padded string
 */
int print_padded_string(const char *str, int width, char *buffer, int *printed_chars, char padding_char)
{
    int count = 0;

    /* Calculate the number of padding characters needed */
    int padding = width - (int)strlen(str);

    if (padding > 0)
    {
        /* Print the padding characters */
        for (int i = 0; i < padding; i++)
        {
            buffer[(*printed_chars)++] = padding_char;
            count++;
        }
    }

    /* Print the string */
    for (int i = 0; str[i]; i++)
    {
        buffer[(*printed_chars)++] = str[i];
        count++;
    }

    return count;
}
