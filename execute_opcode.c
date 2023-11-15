#include "monty.h"

/**
 * execute_opcode - Execute Monty opcode
 * @line: Line containing the opcode
 * @stack: Pointer to the top of the stack
 * @line_number: Current line number in the Monty file
 * @file: File pointer to the Monty file
 */

void execute_opcode(char *line, stack_t **stack, unsigned int line_number, FILE *file)
{
	char *opcode;

	opcode = strtok(line, " \t\n");
	if (!opcode)
		return;
	else
		opcode = strtok(NULL, " \t\n");
	if (strcmp(opcode, "pall") == 0)
		pall(stack, line_number);
	else if (strcmp(opcode, "push") == 0)
		push(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		fclose(file);
		free_stack(*stack);
		free(line);
		exit(EXIT_FAILURE);
	}
}
