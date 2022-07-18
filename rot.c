#include "monty.h"

/**
 * rotl - rotates the first element of the stack
 * @stack: stack head
 * @line_count: line count
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_count)
{
	stack_t *left;
	stack_t *right;

	(void) line_count;
	if (stack == NULL || (*stack) == NULL || (*stack)->next == NULL)
		return;

	left = right = *stack;

	while (right->next)
		right = right->next;
	right->next = left;
	left->prev = right;
	*stack = left->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - rotates the first element of the stack
 * @stack: stack head
 * @line_count: line count
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_count)
{
	stack_t *left;
	stack_t *right;

	(void) line_count;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	right = *stack;

	while (right->next)
		right = right->next;
	left = right->prev;
	right->next = *stack;
	right->prev = NULL;
	left->next = NULL;
	(*stack)->prev = right;
	*stack = right;
}
