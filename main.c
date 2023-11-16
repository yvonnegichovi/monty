#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

globals_t globs;

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
	globs.TOP1 = -99;
	all_lines = read_lines(argv[1]);
	globs.all_lines = all_lines;
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
