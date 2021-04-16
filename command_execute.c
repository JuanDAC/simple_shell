#include "shell.h"

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
* @data: tokens the input user
* Return: void
*/
bool error_handler(char *command_source, data_t *data)
{
	if (access(command_source, F_OK) == 0
		&& access(command_source, X_OK) == -1)
	{
		hsh_print(STDERR_FILENO, "%s: %d: %s: Permission denied\n",
			data->call_to_execute, data->count_prompt, data->tokens[0]
		);
		data->exit_status = 126;
		return (true);
	}
	else if (access(command_source, F_OK) == 0
		&& access(command_source, R_OK) == -1)
	{
		hsh_print(STDERR_FILENO, "%s: 0: Can't open %s\n",
			data->call_to_execute, command_source
		);
		data->exit_status = 2;
		return (true);
	}
	else if (length_string(data->tokens[0]) >= 256)
	{
		hsh_print(STDERR_FILENO, "%s: %d: %s: File name too long\n",
			data->call_to_execute, data->count_prompt, data->tokens[0]
		);
		data->exit_status = 2;
		return (true);
	}
	else if (access(command_source, F_OK) == -1)
	{
		hsh_print(STDERR_FILENO, "%s: %d: %s: not found\n",
			data->call_to_execute, data->count_prompt, data->tokens[0]
		);
		data->exit_status = 127;
		return (true);
	}
	return (false);
}

/**
* command_execute - command execute
* @command_source: tokens the input user
* @data: variable to save exit status
* Return: void
*/
void command_execute(data_t *data, char *command_source)
{
	pid_t pid;
	int status;

	if (error_handler(command_source, data))
		return;

	pid = fork();

	if (pid == 0)
	{
		if (execve(command_source, data->tokens, data->env) == EOF)
			error_handler(command_source, data);
		exit(data->exit_status);
	}
	else if (pid > 0) /* i'm father */
	{
		wait(&status);
		data->exit_status = (status % 255);
	}
	else if (pid == EOF)
		error_handler(command_source, data);
}



