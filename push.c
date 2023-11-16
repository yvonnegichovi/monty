#include "monty.h"

/**
 * _push - pushes an element onto the stack
 * @stack: double pointer to the head of the stack
 * @line_number: value to be pushed onto the stack
 */

void _push(stack_t **stack, unsigned int line_number)
{
	int value;

	if (glob.arg == NULL || !is_integer(glob.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		fclose(glob.file);
		free(glob.line);
		exit(EXIT_FAILURE);
	}
	value = atoi(glob.arg);
	if (add_node(stack, value) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		fclose(glob.file);
		free(glob.line);
		exit(EXIT_FAILURE);
	}
}

