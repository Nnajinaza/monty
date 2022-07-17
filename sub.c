#include "monty.h"

/**
 * sub - function to add the first two node
 * @stack: pointer to the list
 * @line_number: current line
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int first, second, diff;

	if (*stack == NULL || stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	first = (*stack)->n;
	second = (*stack)->next->n;
	diff = second - first;
	pop(stack, line_number);
	(*stack)->n = diff;
}
