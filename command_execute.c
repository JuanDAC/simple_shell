#include "shell.h"

void command_execute(char **tokens, char **env, 
char *call_to_execute, unsigned int *count_prompt,
char *menssage_err)
{



	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execve(tokens[0], tokens, env) == EOF)
		{
			buffer_concat(&menssage_err, call_to_execute, ": ");	
			buffer_concat(&menssage_err, itoa(*count_prompt), ": ");
			buffer_concat(&menssage_err, tokens[0], "not found");
			write(STDERR_FILENO, menssage_err, length_string(menssage_err));
			exit(DEADED_CHILD);
		}
	}
	else if (pid > 0)
	{
		wait(&status);
	}
	else if (pid == EOF)
	{
		PERROR;
	}
}	



