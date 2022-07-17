#include "monty.h"

/**
 * mod - function to add the first two node
 * @stack: pointer to the list
 * @line_number: current line
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int first, second, sum;

	if (*stack == NULL || stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	first = (*stack)->n;
	if (first == '0')
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	second = (*stack)->next->n;
	sum = second % first;
	pop(stack, line_number);
	(*stack)->n = sum;
}
