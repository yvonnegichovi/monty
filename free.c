#include "monty.h"

/**
 * free_stack - free the allocated memory for the stack
 * @stack: the stack to be freed
 */

void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
