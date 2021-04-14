#include "shell.h"
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void expand_variables(
	char **current_token,
	char **env,
	int *index_expand_tokens,
	char *expand_tokens
)
{
	int i, j;

	//pid_t my_pid;
	(void)env;
	(void)index_expand_tokens;
	(void)expand_tokens;

	for (i = 0; (*current_token)[i] != '\0'; i++, j = 0)
	{
		if ((*current_token)[i] == '$')
		{
			if ((*current_token)[i + j] == '$')
			{
				//my_pid = getpid();
			}
		}
	}
}

/**
* parser - split the lines with delimiter of spaces
* @line: line to read from _getline
* @tokens: tokens the input user
* @index_expand_tokens: tokens the input user
* @expand_tokens: tokens the input user
* Return: void
*/
void parser(
	char *line,
	char **tokens,
	char **env,
	int *index_expand_tokens,
	char *expand_tokens
)
{
	int i = 0;

	do {
		tokens[i] = strtok(i ? NULL : line, " ");
		if (i)
			expand_variables(tokens + i, env, index_expand_tokens, expand_tokens);
	} while (tokens[i++]);
}

