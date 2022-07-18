#include "monty.h"

/**
 * pstr - function that prints the top stack ascii value
 * @stack: pointer to the stack
 * @line_number: current line
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	if (*stack == NULL || stack == NULL)
	{
		printf("\n");
	}
	while (*stack != NULL)
	{
		if ((*stack)->n <= 0 || (*stack)->n > 127)
			break;
		printf("%c", (*stack)->n);
		(*stack) = (*stack)->next;
	}
	printf("\n");
}
