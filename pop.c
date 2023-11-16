#include "monty.h"

/**
 * _pop - Removes the top element of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: line number of the opcode in the Monty file
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free(glob.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
	if (*stack != NULL)
		(*stack)->prev = NULL;
}
