#include "shell.h"


int count_includes_characters(char *string, char character)
{
	if (!string || !*string)
		return (0);

	if (*string == character)
		return (1 + count_includes_characters(string + 1, character));

	return (count_includes_characters(string + 1, character));
}



void error_handler(char **tokens, char *menssage_err,
char *call_to_execute, unsigned int *count_prompt)
{
	char *info_message_error;
	char *command_name;
	int index = 0;
	int i;

	
	if (access(*tokens, F_OK) == 0 && access(*tokens, X_OK) == -1)
	{
		info_message_error = "Permission denied\n";
		index = count_includes_characters(*tokens + 1, '/');
		for (i = 0; i <= index; i++)
		{
			command_name = strtok( i ? NULL : *tokens, "/");
		}
	}
	else if (access(*tokens, F_OK) == 0 && access(*tokens, R_OK) == -1)
	{
		
		buffer_concat(&menssage_err, call_to_execute, ": 0: Can't open ");
		buffer_concat(&menssage_err, tokens[0], "");
		write(STDERR_FILENO, menssage_err, length_string(menssage_err));
		return;
	}
	else if (length_string(*tokens) >= 256)
	{
		info_message_error = "File name too long\n";
	}
	else
	{
		info_message_error = "not found\n";
	}

	buffer_concat(&menssage_err, call_to_execute, ": ");
	unsigned_int_to_buffer(*count_prompt, (menssage_err + length_string(menssage_err)), 0);
	buffer_concat(&menssage_err, ": ", *info_message_error == 'P' ? command_name : tokens[0]);
	buffer_concat(&menssage_err, ": ", info_message_error);
	write(STDERR_FILENO, menssage_err, length_string(menssage_err));
}


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
			error_handler(tokens, menssage_err, call_to_execute, count_prompt);
			exit(DEADED_CHILD);
		}
	}
	else if (pid > 0)
	{
		wait(&status);
		//printf("status: %d", status);
	}
	else if (pid == EOF)
	{
		error_handler(tokens, menssage_err, call_to_execute, count_prompt);
	}
}	



