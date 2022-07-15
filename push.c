#include "monty.h"

/**
 * _push - function to push a node to the list
 * @stack: pointer to the list
 * @line_number: current line number
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *tmp;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL || stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (args[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; args[1][i] != '\0'; i++)
	{
		if (args[1][i] == '-' && i == 0)
			continue;
		if (args[1][i] < '0' || args[1][i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	new->n = atoi(args[1]);

	if (check_type(*stack) == STACK)
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * _pall - function to print all the values of stack
 * @stack: pointer to the list
 * @line_number: the current line number
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

int check_type(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
