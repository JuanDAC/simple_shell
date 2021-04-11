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
	char command_name[256];
	int index = 0;
	printf("\n*tokens:%s\n", (*tokens));
	printf("\nF_OK:%d\n", access(*tokens, F_OK));
	printf("\nX_OK:%d\n", access(*tokens, X_OK));

	if (access(*tokens, F_OK) == 0 && access(*tokens, X_OK) == EOF)
	{
		info_message_error = "Permission denied\n";
		index = count_includes_characters(*tokens, '/');
		printf("index: %d, *tokens: %s", index, *tokens);
		string_token_index((char **)&command_name, *tokens, 1, "/", index - 3);
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
	}
	else if (pid == EOF)
	{
		error_handler(tokens, menssage_err, call_to_execute, count_prompt);
	}
}	



