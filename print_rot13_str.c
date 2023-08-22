#include "main.h"

/**
 * print_rot13_string - Print a string with ROT13 encryption
 * @str: String to print
 * @buffer: Buffer to store printed characters
 * @printed_chars: Pointer to the number of characters printed
 *
 * Return: Number of characters printed for the ROT13'ed string
 */
int print_rot13_string(const char *str, char *buffer, int *printed_chars)
{
    int count = 0;

    /* ROT13 encryption algorithm */
    while (*str)
    {
        char c = *str;

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
                c += 13;
            else
                c -= 13;
        }

        buffer[(*printed_chars)++] = c;
        count++;
        str++;
    }

    return count;
}
