#include "monty.h"

/** free_tokens- Frees the global op_toks array of strings.
 */
void free_tokens(char **args)
{
	size_t i = 0;

	if (args == NULL)
		return;
	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
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
	if (string[i] == '-')
		string++;
	while (string[i])
	{
		if (isdigit(string[i]) == 0)
			return (1);
		string++;
	}
	return (0);
}
