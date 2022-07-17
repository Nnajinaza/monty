#include "monty.h"

/**
 * get_opts - function to return the corresponding function
 * @opcode: the opcode passed
 * Return: A pointer to the corresponding function
 */
void get_opts(char *opt, stack_t **stack, unsigned int line_number)
{
	instruction_t opts[] = INSTRUCTION;

	int i = 0;

	if (!strcmp(opt, "stack"))
	{
		global.format = 1;
		return;
	}
	if (!strcmp(opt, "queue"))
	{
		global.format = 0;
		return;
	}			
	while (opts[i].opcode)
	{
		if (strcmp(opts[i].opcode, opt) == 0)
		{
			opts[i].f(line_number, stack);
			return;
		}
		i++;
	}
}
