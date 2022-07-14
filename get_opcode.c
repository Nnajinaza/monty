#include "monty.h"

/**
 * get_opts - function to return the corresponding function
 * @opcode: the opcode passed
 * Return: A pointer to the corresponding function
 */
void (*get_opts(char *opcode))(stack_t**, unsigned int)
{
	instruction_t opts[] = {
		{"push", _push},
		{"pall", _pall},
		{"NULL", NULL}
	};

	int i;

	for (i = 0; opts[i].opcode != NULL; i++)
	{
		if (strcmp(opts[i].opcode, opcode) == 0)
			return (opts[i].f);
	}

	return (NULL);
}
