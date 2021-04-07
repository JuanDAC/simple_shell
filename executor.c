#include "shell.h"

void buffer_concat(char **buffer, char *slash, char *command)
{
	int i, j;

	if (!buffer || !slash || !command)
		return;

	i = length_string(*buffer);
	/* remplzamos el nulo por el slash EJ "/bin/" */
	(*buffer)[i] = *slash;
	i++;
	/* concatenamos el commando que nos llegue EJ "/bin/ls"*/
	for (j = 0; command[j]; j++, i++)
		(*buffer)[i] = command[j];
	/*agregamos el nulo de caracter al final*/
	(*buffer)[i] = '\0';
}

void which(char **tokens, char **env, char *command)
{
	int i, j;
	char *path_content;


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
		/*
		while (path_content)
		{                                          command = "/bin" "/" "ls"
			path_content = strtok(NULL, ":");
			current_string = str_concat("/", args[0]); <<<< /ls
			current_direction = str_concat(path_content, current_string); <<<< /bin/ls
			if (access(current_direction, X_OK) == 0)
				break;
			*/
	}
}


void executor(char **tokens, char **env)
{
	char command[BUFFER_SIZE];

	which(tokens, env, command);

}




