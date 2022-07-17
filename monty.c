#include "monty.h"
#include <string.h>

int status = 0;

/**
 * _getline - function to read the file
 * @fd: file to be read
 *
 * Return: exit_status
 */
int main(int argc, char **argv)
{
	FILE *fd;
	stack_t *stack = NULL;
	unsigned int line_number = 1;
	char *lineptr = NULL, *str;
	size_t len = 0;

	global.format = 1;	
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
	while (getline(&lineptr, &len, fd) != -1)
	{
		if (status)
			break;
		str = strtok(lineptr, " \t\n");
		if (str == NULL)
		{
			fprintf(stderr, "Error:");
			exit(EXIT_FAILURE);
		}
		global.args = strtok(NULL, " \t\n");
		get_opts(str, &stack, line_number);
		line_number++;
	}
	free(lineptr);
	fclose(fd);
	exit(EXIT_SUCCESS);
}
