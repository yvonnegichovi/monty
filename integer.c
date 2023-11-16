#include "monty.h"

/**
 * is_integer - checks if a string is a valid interger
 * @str: the string to be checked
 * Return: 0 on success, 1 on falure
 */

int is_integer(const char *str)
{
	if (!str || *str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
