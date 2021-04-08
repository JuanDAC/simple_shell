#include "shell.h"

void command_execute(char **tokens, char **env)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execve(tokens[0], tokens, env) == -1)
		{
			PERROR;
		}
	}
	else if (pid > 0)
	{
		wait(&status);
	}
	else if (pid == -1)
	{
		PERROR;
	}
}	



