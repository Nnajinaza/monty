#include "monty.h"

/**
 * nop - function that does nothing
 * @stack: pointer to the list
 * @line_number: current line
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) *stack;
	(void) line_number;
}
