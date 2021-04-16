#include "shell.h"


/**
* which - save the sourse teh command in variable @command
* @tokens: tokens the input user
* @env: environment
* @command: buffer to save command
* Return: Alwais void
*/
void which(char **tokens, char **env, char *command)
{
	int i, j;
	char *path_content;

	if (equal_strings(*tokens, "env"))
		_buffer_concat(command, false, 2, "/usr/bin/", tokens[0]);
	else
		_buffer_concat(command, false, 1, tokens[0]);

	if (access(command, X_OK) == 0)
		return;

	fill_buffer_null(command, 1024, char);
	/* search the $PATH and get directions from value*/

	for (i = 0; env[i] != NULL; i++)
		if (includes_string(env[i], "PATH=", false))
		{
			j = 0;
			do {
				/* concat the command with source directory */
				path_content = string_token_index(&command, env[i], 5, ":", j);
				if (!path_content)
					continue;
				_buffer_concat(command, true, 2, "/", tokens[0]);
				/* stop when the true command saved in variable @command */
				if (access(command, F_OK) == 0)
					return;
				j += 1;
			} while (path_content);
		}
	fill_buffer_null(command, 1024, char);
}


/**
* executor - call to logic for to search source and command execute
* @data: tokens the input user
* Return: void
*/
void executor(data_t *data)
{
	char command[BUFFER_SIZE] = "";

	if (!data->tokens[0])
		return;
	which(data->tokens, data->env, command);

	/* guardamos la direccion del comando en la primera picicion de tokens */
	if (!*command)
		copy_in_buffer(command, data->tokens[0], char);

	command_execute(data, command);
}

