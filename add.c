#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number being executed
 */

void _add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	_pop(stack, line_number);
}
