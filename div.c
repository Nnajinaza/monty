#include "monty.h"

/**
 * _div - function to add the first two node
 * @stack: pointer to the list
 * @line_number: current line
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
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
	sum = second / first;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	(*stack)->n = sum;
	free(tmp);
}
