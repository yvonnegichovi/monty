#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: interger
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globals - structure of globals
 * @TOP1: value at top of stack (TOP 1)
 * @TOP2: value under top of stack (TOP 2)
 * @arg: argument to the opcode command
 * @top: pointer to Node at the top
 * @all_lines: all read lines
 * @file: pointer to a monty file
 * @line: pointer to an input line content
 */
typedef struct globals
{
	int TOP1;
	int TOP2;
	char *arg;
	stack_t *top;
	char **all_lines;
	char *line;
	FILE *file;
} globals_t;
extern globals_t glob;

int exec_opcode(stack_t **stack, char *opcode, unsigned int l_num);
void exec_file(stack_t **stack);
stack_t *add_node(stack_t **stack, const int n);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
int is_integer(const char *str);
void _pop(stack_t **stack, unsigned int line_number);
char **read_lines(char *argv);
int is_integer(const char *str);
void _pint(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
