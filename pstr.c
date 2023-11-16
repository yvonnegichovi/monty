#include "monty.h"

/**
 * _pstr - prints the string starting at the top of the stack
 * @stack: pointer to the pointer of the top of the stack
 * @line_number: current line number in the Monty file
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	(void)line_number;

	while (curr != NULL && curr->n != 0 && (curr->n >= 0 && curr->n <= 127))
	{
		printf("%c", curr->n);
		curr = curr->next;
	}
	printf("\n");
}
