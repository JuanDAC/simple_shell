#include "shell.h"


int count_includes_characters(char *string, char character)
{
	if (!string || !*string)
		return (0);

	if (*string == character)
		return (1 + count_includes_characters(string + 1, character));

	return (count_includes_characters(string + 1, character));
}


void hsh_print(int file_descriptor, const char *format, ...)
{
	char finaly_string[1024], string_number[1024];
	char *string, *buffer;
	va_list argumets;
	int number;

	va_start(argumets, format);

	fill_buffer_null(string_number);

	buffer = finaly_string;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 's':
					string = va_arg(argumets, char *);
					while (*string)
						*buffer++ = *string++;
					break;
				case 'd':
					number = va_arg(argumets, int);
					unsigned_int_to_buffer(number, string_number, 0);
					string = string_number;
					while (*string)
						*buffer++ = *string++;
					break;
			}
			format++;
		}
		else
		{
			*buffer++ = *format++;
		}
	}
	*buffer = '\0';
	va_end(argumets);
	write(file_descriptor, finaly_string, length_string(finaly_string));
}

void error_handler(char **tokens, char *menssage_err,
char *call_to_execute, unsigned int *count_prompt)
{
	int index = 0, i;
	char *command_name;

	(void)menssage_err;
	if (access(*tokens, F_OK) == 0 && access(*tokens, X_OK) == -1)
	{
		index = count_includes_characters(*tokens + 1, '/');
		for (i = 0; i <= index; i++)
			command_name = strtok(i ? NULL : *tokens, "/");
		hsh_print(STDERR_FILENO, "%s: %d: %s: Permission denied\n",
			call_to_execute, *count_prompt, command_name
		);
	}
	else if (access(*tokens, F_OK) == 0 && access(*tokens, R_OK) == -1)
	{
		hsh_print(STDERR_FILENO, "%s: 0: Can't open %s\n",
			call_to_execute, *tokens
		);
	}
	else if (length_string(*tokens) >= 256)
	{
		hsh_print(STDERR_FILENO, "%s: %d: %s: File name too long\n",
			call_to_execute, *count_prompt, *tokens
		);
	}
	else
	{
		hsh_print(STDERR_FILENO, "%s: %d: %s: not found\n",
			call_to_execute, *count_prompt, *tokens
		);
	}
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



