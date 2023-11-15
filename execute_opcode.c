#include "monty.h"

/**
 * exec_opcode - Execute Monty opcode
 * @line: Line containing the opcode
 * @stack: Pointer to the top of the stack
 * @l_num: Current line number in the Monty file
 * @file: File pointer to the Monty file
 */

void exec_opcode(char *line, stack_t **stack, unsigned int l_num, FILE *file)
{
	char *opcode;

	opcode = strtok(line, " \t\n");
	if (!opcode)
		return;
	opcode = strtok(NULL, " \t\n");
	if (strcmp(opcode, "pall") == 0)
		pall(stack, l_num);
	else if (strcmp(opcode, "push") == 0)
		push(stack, l_num);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, l_num);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", l_num, opcode);
		fclose(file);
		free_stack(*stack);
		free(line);
		exit(EXIT_FAILURE);
	}
}
