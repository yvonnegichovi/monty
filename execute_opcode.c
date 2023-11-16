#include "monty.h"

/**
 * exec_opcode - Execute Monty opcode
 * @line: Line containing the opcode
 * @stack: Pointer to the top of the stack
 * @l_num: Current line number in the Monty file
 * @file: File pointer to the Monty file
 * Return: 0 on sucess and 1 on failure
 */

int exec_opcode(char *line, stack_t **stack, unsigned int l_num, FILE *file)
{
	instruction_t ops_array[] = {
		{"push", _push},
		{"pall", _pall},
		{"pop", _pop},
		{NULL, NULL}};
	char *op;
	unsigned int i = 0;

	op = strtok(line, " \t\n");
	if (!op)
		return(1);
	op = strtok(NULL, " \t\n");
	while (ops_array[i].opcode && op)
	{
		if (strcmp (op, ops_array[i].opcode) == 0)
		{
			ops_array[i].f(stack, l_num);
			return (0);
		}
		i++;
	}
	if (op && ops_array[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
		fclose(file);
		free_stack(stack);
		free(line);
		exit(EXIT_FAILURE);
	}
	return (1);
}
