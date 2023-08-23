#include "main.h"

/**
 * get_flag - sets flags in the struct if _printf finds a flag modifier
 * @s: the character that holds the flag specifier
 * @f: a pointer to the struct flags where we set the flags
 *
 * Return: 1 if a flag has been set, 0 otherwise
 */
int get_flag(char s, flags_t *f)
{
	int flag_set = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			flag_set = 1;
			break;
		case ' ':
			f->space = 1;
			flag_set = 1;
			break;
		case '#':
			f->hash = 1;
			flag_set = 1;
			break;
	}

	return (flag_set);
}



