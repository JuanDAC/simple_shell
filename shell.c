#include "shell.h"
#include <stdlib.h>
/**
* sigint_handler - sigint handler signal of Ctrl+C
* @number: string within number
* Return: void if success
*/
void sigint_handler(int number __attribute__((unused)))
{
	signal(SIGINT, sigint_handler);
	NEW_LINE;
	PRINT_PRONPT;
	fflush(stdout);
}

/**
* add_signals - add events listeners of signals
* Return: void if success
*/
void add_signals(void)
{
	/* signal SIGINT of Ctrl+C */
	signal(SIGINT, sigint_handler);
}
/**
* _atoi - convert a string to an integer
* @string_number: string within number
* Return: integer resove of the @string_number
*/
int _atoi(char *string_number)
{
	int i, resolve, scale;

	if (!string_number)
		return (0);

	i = length_string(string_number) - 1;
	resolve = 0;
	for (scale = 1; i >= 0; i -= 1, scale *= 10)
		if (string_number[i] == '-')
			resolve *= -1;
		else
			resolve += (string_number[i] & 0x0F) * scale;
	return (resolve);
}

/**
* buildtin - buildtin execute
* @data: current line alloc
* Return: void
*/
bool buildtin(data_t *data)
{

	if  (equal_strings(data->tokens[0], "exit"))
	{
		/*refactorizar en una funcion */
		if (!data->tokens[1] || is_number(data->tokens[1]))
		{
			data->exit_status = data->tokens[1]
				? _atoi(data->tokens[1])
				: data->exit_status;
			free(data->current_line);
			exit(data->exit_status < 0 ? 2 : data->exit_status);
		}
		else
		{
			hsh_print(STDERR_FILENO, "%s: %d: exit: Illegal number: %s\n",
				data->call_to_execute, data->count_prompt, data->tokens[1]);
			data->exit_status = 2;
		}
		return (true);
	}
	return (false);
}

/**
* main - entry point
* @c: conunter of arguments the program
* @arguments_value: arguments the program
* @env: environment
* Return: o if success
*/
int main(
	int c __attribute__((unused)),
	char **arguments_value,
	char **env
)
{
	char *tokens[BUFFER_SIZE];
	char remake_tokens[BUFFER_SIZE];
	data_t data = {NULL};

	data.tokens = (char **)tokens, data.current_line = NULL, data.env = env;
	data.size_current_line = 0, data.current_characters_read = 0;
	data.index_remake_tokens = 0, data.exit_status = 0, data.count_prompt = 0;
	data.remake_tokens = remake_tokens, data.call_to_execute = arguments_value[0];

	do {
		prompt(&data, isatty(STDIN_FILENO));
		parser(&data);
		if (!buildtin(&data))
			executor(&data);
	} while (true);

	return (EXIT_SUCCESS);
}

