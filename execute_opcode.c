#include "monty.h"

/**
 * @line: Line containing the opcode
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
		{NULL, NULL}};
	unsigned int i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, l_num);
			return (0);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", l_num, opcode);
	exit(EXIT_FAILURE);
	return (0);
}
