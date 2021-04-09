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
			unsigned int unsigned_int_to_buffer(int n, char *buffer, int i);
			buffer_concat(&menssage_err, call_to_execute, ": ");
			unsigned_int_to_buffer(*count_prompt, (menssage_err + length_string(menssage_err)), 0);
			buffer_concat(&menssage_err, ": ", tokens[0]);
			buffer_concat(&menssage_err, ": ", "not found\n");
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



