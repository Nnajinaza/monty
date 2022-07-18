#include "monty.h"

/**
 * get_opts - function to return the corresponding function
 * @opt: the opcode passed
 * @stack: pointer to the stack
 * @line_number: current line number
 *
 * Return: A pointer to the corresponding function
 */
void get_opts(stack_t **stack, char *opt, unsigned int line_number)
{
	instruction_t opts[] = INSTRUCTION;

	int i;

	if (!strcmp(opt, "stack"))
	{
		global.format = 0;
		return;
	}
	if (!strcmp(opt, "queue"))
	{
		global.format = 1;
		return;
	}
	for (i = 0; opts[i].opcode != NULL; i++)
	{
		if (strcmp(opts[i].opcode, opt) == 0)
		{
			opts[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opt);
	exit(EXIT_FAILURE);
}
