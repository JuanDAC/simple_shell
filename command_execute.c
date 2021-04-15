#include "shell.h"

/**
* count_includes_characters - count includes characters
* @string: string to search
* @character: character a buscar
* Return: number of eachs character includes
*/
int count_includes_characters(char *string, char character)
{
	if (!string || !*string)
		return (0);

	if (*string == character)
		return (1 + count_includes_characters(string + 1, character));

	return (count_includes_characters(string + 1, character));
}
/**
* hsh_print - mini printf
* @file_descriptor: file descriptor
* @format: format printf
* Return: Alwais void
*/
void hsh_print(int file_descriptor, const char *format, ...)
{
	char finaly_string[1024], string_number[1024];
	char *string, *buffer;
	va_list argumets;
	int number;

	va_start(argumets, format);
	buffer = finaly_string;
	while (*format)
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
					fill_buffer_null(string_number);
					number = va_arg(argumets, int);
					unsigned_int_to_buffer(number, string_number, 0);
					string = string_number;
					while (*string)
						*buffer++ = *string++;
					break;
				case 'c':
					*buffer++ = (char)va_arg(argumets, int);
					break;
			}
			format++;
		}
		else
			*buffer++ = *format++;
	*buffer = '\0';
	va_end(argumets);
	write(file_descriptor, finaly_string, length_string(finaly_string));
}

/**
* error_handler - error handler of a child
* @command_source: tokens the input user
* @command_name: tokens the input user
* @call_to_execute: string type to access to this program
* @count_prompt: save the count the prints prompt
* @exit_status: variable to save exit status
* Return: void
*/
bool error_handler(
	char *command_source,
	char *command_name,
	char *call_to_execute,
	unsigned int *count_prompt,
	int *exit_status
)
{
	if (access(command_source, F_OK) == 0
		&& access(command_source, X_OK) == -1)
	{
		hsh_print(STDERR_FILENO, "%s: %d: %s: Permission denied\n",
			call_to_execute, *count_prompt, command_name
		);
		*exit_status = 126;
		return (true);
	}
	else if (access(command_source, F_OK) == 0
		&& access(command_source, R_OK) == -1)
	{
		hsh_print(STDERR_FILENO, "%s: 0: Can't open %s\n",
			call_to_execute, command_source
		);
		*exit_status = 2;
		return (true);
	}
	else if (length_string(command_name) >= 256)
	{
		hsh_print(STDERR_FILENO, "%s: %d: %s: File name too long\n",
			call_to_execute, *count_prompt, command_name
		);
		*exit_status = 2;
		return (true);
	}
	else if (access(command_source, F_OK) == -1)
	{
		hsh_print(STDERR_FILENO, "%s: %d: %s: not found\n",
			call_to_execute, *count_prompt, command_name
		);
		*exit_status = 127;
		return (true);
	}
	return (false);
}

/**
* command_execute - command execute
* @command_source: tokens the input user
* @tokens: tokens the input user
* @call_to_execute: string type to access to this program
* @count_prompt: save the count the prints prompt
* @env: environment
* @exit_status: variable to save exit status
* Return: void
*/
void command_execute(
	char *command_source,
	char **tokens,
	char **env,
	char *call_to_execute,
	unsigned int *count_prompt,
	int *exit_status
)
{
	pid_t pid;
	int status;

	if (error_handler(
		command_source,
		*tokens,
		call_to_execute,
		count_prompt,
		exit_status
	))
		return;

	pid = fork();

	if (pid == 0)
	{
		if (execve(command_source, tokens, env) == EOF)
			error_handler(
				command_source,
				*tokens,
				call_to_execute,
				count_prompt,
				exit_status
			);
		exit(*exit_status);
	}
	else if (pid > 0) /* i'm father */
	{
		wait(&status);
		*exit_status = status % 255;
	}
	else if (pid == EOF)
		error_handler(
			command_source,
			*tokens,
			call_to_execute,
			count_prompt,
			exit_status
		);
}



