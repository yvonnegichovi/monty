#include "monty.h"

/**
 * read_lines - Reads all lines from file
 * @argv: Name of the Monty file
 * Return: An array of all lines
 */

char **read_lines(char *argv)
{
	FILE *file;
	size_t len = 1;
	ssize_t length = 0;
	char **all_lines = NULL, *line = NULL, *temp;
	int l_num = 0, line_number = 0;

	file = fopen(argv, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, file) != -1)
		l_num++;
	fclose(file);
	all_lines = malloc(sizeof(char *) * (len + 1));
	if (all_lines == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv, "r");
	while ((length = getline(&line, &len, file)) != -1)
	{
		temp = strtok(line, "\n");
		if (temp == NULL)
			continue;
		all_lines[line_number] = strdup(temp);
		line_number++;
	}
	all_lines[line_number] = NULL;
	fclose(file);
	if (length == -1)
		free(line);
	return (all_lines);
}
