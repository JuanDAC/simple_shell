#include "shell.h"

void command_execute(char **tokens, char **env)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execve(tokens[0], tokens, env) == EOF)
		{
			PERROR;
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



