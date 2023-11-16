#include "monty.h"

/**
 * _mul - multiplies the second top element of the stack with the top element
 * @stack: pointer to the pointer of the top of the stack
 * @line_number: current line number in the Monty file
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		fclose(glob.file);
		free(glob.line);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	_pop(stack, line_number);
}
