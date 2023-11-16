#include "monty.h"

/**
 * _push - pushes an element onto the stack
 * @stack: double pointer to the head of the stack
 * @line_number: value to be pushed onto the stack
 */

void _push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");
	int value;
	(void)**stack;

	if (arg == NULL || !is_integer(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(arg);
	printf("%d\n", value);
}

