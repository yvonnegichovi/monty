#include "monty.h"

/**
 * add_node - adds a new node at the beginning of a stack
 * @stack: pointer to a pointer of the start of the stack
 * @n: integer to be included in node
 * Return: address of the new element or NULL if it fails
 */

stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	if (*stack == NULL)
		new->next = NULL;
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
	return (new);
}
