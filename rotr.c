#include "monty.h"

/**
 * _rotr - rotates the stack to the bottom
 * @stack: pointer to the pointer of the top of the stack
 * @line_number: current line number in the Monty file
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *last = *stack;
	(void)line_number;

	if (current == NULL || current->next == NULL)
		return;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = current;
	current->prev = last;
	(*stack) = last;
}
