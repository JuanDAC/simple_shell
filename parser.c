#include "shell.h"


void parser(char *string, char **tokens)
{
	int i;
	char *current_token = NULL;

	current_token = strtok(string, " ");

	i = 0;
	while (current_token != NULL)
	{
		tokens[i] = current_token;
		current_token = strtok(NULL, " ");
		i++;
	}
	tokens[i] = NULL;

}
