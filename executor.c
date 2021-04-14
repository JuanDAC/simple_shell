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

	buffer_concat(&command, tokens[0], "");
	if (access(command, X_OK) == 0)
		return;

	fill_buffer_null(command);
	/* search the $PATH and get directions from value*/

	for (i = 0; env[i] != NULL; i++)
		if (includes_string(env[i], "PATH=", false))
		{
			j = 0;
			do {
				/* concat the command with source directory */
				path_content = string_token_index(&command, env[i], 5, ":", j);
				if (!path_content)
				{
					continue;
				}
				buffer_concat(&command, "/", tokens[0]);
				/* stop when the true command saved in variable @command */
				if (access(command, F_OK) == 0)
					return;
				j += 1;
			} while (path_content);
		}
	fill_buffer_null(command);
}


/**
* executor - call to logic for to search source and command execute
* @tokens: tokens the input user
* @call_to_execute: string type to access to this program
* @count_prompt: save the count the prints prompt
* @env: environment
* Return: void
*/
void executor(
	char **tokens,
	char **env,
	char *call_to_execute,
	unsigned int *count_prompt,
	int *exit_status
)
{
	char command[BUFFER_SIZE] = "";

	if (!*tokens)
		return;
	which(tokens, env, command);

	/* guardamos la direccion del comando en la primera picicion de tokens */
	if (!*command)
		copy_in_buffer(command, tokens[0], char);

	command_execute(command, tokens, env, call_to_execute, count_prompt, exit_status);
}




