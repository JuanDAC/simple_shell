#include "shell.h"


void parser(char *line, char **tokens)
{
	int i;
	char *current_token = NULL;

	current_token = strtok(line, " ");

	i = 0;
	while (current_token != NULL)
	{
		tokens[i] = current_token;
		current_token = strtok(NULL, " ");
		i++;
	}
	tokens[i] = NULL;

}
