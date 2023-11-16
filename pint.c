#include "monty.h"

/**
 * _pint - prints the value at the top of the stack, followed by a new line
 * @stack: the stack containing the values
 * @line_number: value to be printed
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	if (glob.TOP1 == -99)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", glob.TOP1);
}
