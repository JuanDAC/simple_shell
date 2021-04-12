#include "shell.h"



void which(char **tokens, char **env, char *command)
{
	int i, j;
	char *path_content;
	

	buffer_concat(&command, tokens[0], "");
	if (access(command, X_OK) == 0)
		return;
	fill_buffer_null(command);
	/* leer el PATH y traer las direcciones y concatenarlas con el comando que nos llegue*/
	for (i = 0; env[i]; i++)
	{
		if (includes_string(env[i], "PATH", false))
		{
			j = 0;
			do {
				path_content = string_token_index(&command, env[i], 5, ":", j);
				buffer_concat(&command, "/", tokens[0]);
				if (access(command, F_OK) == 0)
					return;
				j += 1;
			} while (path_content);
		}
	}
	fill_buffer_null(command);
}


void executor(char **tokens, char **env, char *call_to_execute, 
unsigned int *count_prompt)
{	
	char message_err[BUFFER_SIZE] = "";
	char command[BUFFER_SIZE] = "";

	if (!*tokens)
		return;
	which(tokens, env, command);

	/* guardamos la direccion del comando en la primera picicion de tokens */
	if (*command)
		tokens[0] = command;

	command_execute(tokens, env, call_to_execute, count_prompt, message_err);
}




