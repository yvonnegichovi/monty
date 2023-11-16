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
	char *line = NULL, *opcode;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	size_t len = 0;
	ssize_t read;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode == NULL)
			continue;
		exec_opcode(&stack, opcode, line_number);
	}
	free(line);
	fclose(file);
	exit(EXIT_SUCCESS);
}
