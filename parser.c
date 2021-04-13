#include "shell.h"

/**
* parser - split the lines with delimiter of spaces
* @line: line to read from _getline
* @tokens: tokens the input user
* Return: void
*/
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
