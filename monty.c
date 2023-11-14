#define _GNU_SOURCE
#include "main.h"
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
	char *line = NULL, *opcode;
	size_t len = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (!opcode)
			continue;
		free(line);
		line = NULL;
	}
	fclose(file);
	free(line);
	return (EXIT_SUCCESS);
}

/**
 * push - pushes an element onto the stack
 * @stack: double pointer to the head of the stack
 * @value: value to be pushed onto the stack
 */

void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - prints all values on the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number being executed
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
