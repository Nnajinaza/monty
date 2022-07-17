#include "monty.h"

/**
 * pop - function to remove the first node
 * @stack: pointer to the stack
 * @line_number: current line
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (*stack == NULL)
		return;
	(*stack)->prev = NULL;
}
