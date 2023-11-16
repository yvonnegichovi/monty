#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * main - monty interpreter main function
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
	FILE *file = NULL;
	char **all_lines;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	all_lines = read_lines(argv[1]);
	for (line_number = 0; all_lines[line_number] != NULL; line_number++)
	{
		if (exec_opcode(all_lines[line_number], &stack, line_number + 1, file) != 0)
		{
			fclose(file);
			free_stack(&stack);
			free(all_lines);
			exit(EXIT_FAILURE);
		}
	}
	free_stack(&stack);
	fclose(file);
	return (EXIT_SUCCESS);
}

/**
 * _push - pushes an element onto the stack
 * @stack: double pointer to the head of the stack
 * @line_number: value to be pushed onto the stack
 */

void _push(stack_t **stack, unsigned int line_number)
{
	char *arg = NULL;
	int value;
	(void)**stack;

	if (arg == NULL || !is_integer(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(arg);
	printf("%d\n", value);
}

/**
 * _pall - prints all values on the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number being executed
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL, *top = NULL;
	(void)line_number;

	if (*stack == NULL)
		return;

	current = *stack;

	while (current->next != NULL)
		current = current->next;

	top = current;
	while (top != NULL)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}
