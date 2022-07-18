#include "monty.h"

/**
 * free_stack - function to free stack
 * @stack: pointer to the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	if (stack)
	{
		next = stack->next;
		while (current)
		{
			free(current);
			current = next;
			if (next)
				next = next->next;
		}
	}
}

/**
 * is_digit - checks if a string is a digit
 * @string: string to check
 *
 * Return: 1 if success, 0 if not
 */
int is_digit(char *string)
{
	int i = 0;

	if (!string || *string == '\0')
		return (0);
	while (string[i] != '\0')
	{
		if (string[i] == '-')
			string++;
		if (isdigit(string[i]) == 0)
			return (0);
		string++;
	}
	return (1);
}
