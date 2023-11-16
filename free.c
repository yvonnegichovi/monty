#include "monty.h"

/**
 * free_stack - free the allocated memory for the stack
 * @stack: the stack to be freed
 */

void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
