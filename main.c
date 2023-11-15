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
	FILE *file;
	char *line;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read_line = getline(&line, &len, file)) != -1)
	{
		line_number++;
		exec_opcode(line, &stack, line_number, file);
	}
	free_stack(&stack);
	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}

/**
 * push - pushes an element onto the stack
 * @stack: double pointer to the head of the stack
 * @line_number: value to be pushed onto the stack
 */

void push(stack_t **stack, unsigned int line_number)
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
 * pall - prints all values on the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number being executed
 */

void pall(stack_t **stack, unsigned int line_number)
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
