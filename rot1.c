#include "monty.h"

/**
 * _rot1 - rotates the stack to the top
 * @stack: pointer to the pointer of the top of the stack
 * @line_number: current line number in the Monty file
 */

void _rot1(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *last = *stack;
	(void)line_number;

	if (current == NULL || current->next == NULL)
		return;
	while (last->next != NULL)
		last = last->next;
	last->next = current;
	current->prev = last->next;
	last->next->prev = NULL;
	(*stack) = last->next;
}
