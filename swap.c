#include "monty.h"

/**
 * swap - function to swap the first two nodes
 * @stack: pointer to the list
 * @line_number: current line
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int swap;

	if (*stack == NULL || (*stack)->next == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	swap = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = swap;
}
