#include "monty.h"

/**
 * exec_opcode - executes opcodes
 * @stack: Pointer to the top of the stack
 * @opcode: the instruction given
 * @l_num: Current line number in the Monty file
 * Return: 0 on sucess and 1 on failure
 */

int exec_opcode(stack_t **stack, char *opcode, unsigned int l_num)
{
	instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pop", _pop},
		{"pint", _pint},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL}
	};
	unsigned int i = 0;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, l_num);
			return (0);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", l_num, opcode);
	free_stack(*stack);
	fclose(glob.file);
	free(glob.line);
	exit(EXIT_FAILURE);
	return (0);
}

/**
 * exec_file - reads and executes opcodes from a file
 * @stack: pointer to the pointer of the top of the stack
 */

void exec_file(stack_t **stack)
{
	char *opcode = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int l_num = 0;

	while ((nread = getline(&glob.line, &len, glob.file)) != -1)
	{
		l_num++;
		opcode = strtok(glob.line, " \t\r\n\\a");
		glob.arg = strtok(NULL, " \n\t");
		if (opcode == NULL || *opcode == '#')
			continue;
		exec_opcode(stack, opcode, l_num);
	}
}
