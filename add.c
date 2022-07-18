#include "monty.h"

/**
 * add - function to add the first two node
 * @stack: pointer to the list
 * @line_number: current line
 */
void add(stack_t **stack, unsigned int line_number)
{
	int first, second, sum;

	if (*stack == NULL || stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = (*stack)->n;
	second = (*stack)->next->n;
	sum = first + second;
	pop(stack, line_number);
	(*stack)->n = sum;
}
