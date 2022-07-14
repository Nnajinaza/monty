#include "monty.h"
#include <string.h>

char **args = NULL;

unsigned int token_len(void)
{
	unsigned int len = 0;

	while (args[len])
		len++;
	return(len);
}
int _getline(FILE *fd)
{
	stack_t *stack = NULL;
	unsigned int line_number = 0, len_tok = 0;
	char *lineptr = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	void (*cmd_opt)(stack_t**, unsigned int);

	while (getline(&lineptr, &len, fd) != EOF)
	{
		line_number++;
		args[1] = strtok(lineptr, DELIMS);
		if (args == NULL)
		{
			fprintf(stderr, "Error:");
			exit(EXIT_FAILURE);
		}
		cmd_opt = get_opts(args[1]);
		if (!cmd_opt)
		{
			fprintf(stderr, "L%d: unknown instruction %s", line_number, *args);
			exit(EXIT_FAILURE);
		}
		cmd_opt(&stack, line_number);
		if (token_len() != len_tok)
		{
			if (args[len_tok])
				exit_status = atoi(args[len_tok]);
			else
				exit_status = EXIT_FAILURE;
		}
	}
	return (exit_status);
}

int main(int argc, char **argv)
{
	FILE *fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	exit_code = _getline(fd);
	return (exit_code);
}
