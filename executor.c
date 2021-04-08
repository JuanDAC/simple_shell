#include "shell.h"

void buffer_concat(char **buffer, char *slash, char *command)
{
	int i, j;

	if (!buffer || !slash || !command)
		return;

	i = length_string(*buffer);
	/* remplzamos el nulo por el string slash EJ "/bin/" */
	for (j = 0; slash[j]; j++, i++)
		(*buffer)[i] = slash[j];
	/* concatenamos el commando que nos llegue EJ "/bin/ls"*/
	for (j = 0; command[j]; j++, i++)
		(*buffer)[i] = command[j];
	/*agregamos el nulo de caracter al final*/
	(*buffer)[i] = '\0';
}

void fill_buffer_null(char *buffer)
{
	while (*buffer)
		*buffer++ = '\0';
}



void which(char **tokens, char **env, char *command)
{
	int i, j;
	char *path_content;
	

	buffer_concat(&command, tokens[0], "");
	if (access(command, X_OK) == 0)
		return;
	/* leer el PATH y traer las direcciones y concatenarlas con el comando que nos llegue*/
	for (i = 0; env[i]; i++)
	{
		if (includes_string(env[i], "PATH", false))
		{
			j = 0;
			do {
				path_content = string_token_index(&command, env[i], 5, ":", j);
				buffer_concat(&command, "/", tokens[0]);
				if (access(command, X_OK) == 0)
					return;
				j += 1;
			} while (path_content);
		}
	}
	fill_buffer_null(command);
}


void executor(char **tokens, char **env)
{
	char command[BUFFER_SIZE] = "";

	if (!*tokens)
		return;
	which(tokens, env, command);
	
	/* guardamos la direccion del comando en la primera picicion de tokens */
	tokens[0] = command;

	command_execute(tokens, env);
}




