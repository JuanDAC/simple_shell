#include "shell.h"
#include <string.h>
/**
* parser - split the lines with delimiter of spaces
* @line: line to read from _getline
* @tokens: tokens the input user
* Return: void
*/
void parser(char *line, char **tokens)
{
	int i = 0;

	do {
		tokens[i] = strtok(i ? NULL : line, " ");
	} while (tokens[i++]);
}
