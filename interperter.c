#include "monty.h"

/**
 * interpreter - interpretes opcodes instructions using a hash table
 * @ops_array: pointer to an array of functions and opcode
 * @all_lines: array of pointer to lines
 * Return: void
 */

void interpreter(instruction_t *ops_array, char **all_lines)
{
	char *opcode = NULL;
	unsigned int i = 0;
	int j = 0;
	stack_t *stack = NULL;

	for (i = 0; all_lines[i]; ++i)
	{
		opcode = strtok(all_lines[i], " \t\n");
		if (!opcode)
			continue;
		while (ops_array[j].opcode)
		{
			if (strcmp(opcode, ops_array[j].opcode) == 0)
			{
				ops_array[j].f(&stack, i + 1);
				break;
			}
			++j;
		}
		if (!ops_array[j].opcode)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", i + 1, opcode);
			free_stack(&stack);
			exit(EXIT_FAILURE);
		}
	}
	free_stack(&stack);
}
