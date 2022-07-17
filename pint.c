#include "monty.h"

/**
 * pint - function to print the top value
 * @stack: pointer to the list
 * @line_number: current line
 *
 * Return: value of the top stack
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", top->n);
}
