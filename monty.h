#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define INSTRUCTION		\
	{			\
		{"push", push},	\
		{"pall", pall},	\
		{"pint", pint}, \
		{"pop", pop},	\
		{"swap", swap},	\
		{"add", add},	\
		{"nop", nop},	\
		{"sub", sub},	\
		{"div", _div},	\
		{"mod", mod},	\
		{"mul", mul},	\
		{NULL, NULL}	\
	}
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
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
 * struct args - passing the global argument
 * @format: detemine if it is stack or queue
 * @args: argument to be passed
 *
 * Description: global argument
 */
typedef struct args
{
	int format;
	char *args;
} args;
args global;

/* function to check the opcode passed*/
void get_opts(stack_t **stack, char *opt, unsigned int line_number);

/* linked list function */
stack_t *head_stack(stack_t **stack, const int n);
stack_t *tail_stack(stack_t **stack, const int n);

/* opcode funnctions */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);

/* helper function */
int _getline(FILE *fd);
void free_tokens(char **args);
int is_digit(char *str);
void free_stack(stack_t *stack);

#endif
