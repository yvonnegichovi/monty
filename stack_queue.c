#include "monty.h"

/**
 * _stack - sets the mode to stack (LIFO)
 * @stack: pointer to the pointer of the top of the stack
 * @line_number: current line number in the Monty file
 */

void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	glob.mode = 0;
}

/**
 * _queue - sets the mode to queue (FIFO)
 * @stack: pointer to the pointer of the top of the stack
 * @line_number: current line number in the Monty file
 */

void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	glob.mode = 1;
}
