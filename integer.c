#include "monty.h"

/**
 * is_integer - checks if a string is a valid interger
 * @str: the string to be checked
 * Return: 0 on success, 1 on falure
 */

int is_integer(const char *str)
{
	int i = 0;

	if (!str || *str == '\0')
		return (0);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (0);
	}
	return (1);
}
