#include "monty.h"

/**
 * _pall - prints all values on the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number being executed
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL, *top = NULL;
	(void)line_number;

	if (*stack == NULL)
		return;

	current = *stack;

	while (current->next != NULL)
		current = current->next;

	top = current;
	while (top != NULL)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}
