#include "shell.h"

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
* @current_line: current line alloc
* @tokens: tokens the input user
* @call_to_execute: string type to access to this program
* @count_prompt: save the count the prints prompt
* @env: environment
* Return: void
*/
bool buildtin(
	char *current_line,
	char **tokens,
	char **env,
	char *call_to_execute,
	unsigned int *count_prompt
)
{
	int status_number;

	(void)env;
	(void)call_to_execute;
	(void)count_prompt;

	if (includes_string(*tokens, "exit", false))
	{
		/* refactorizar en una funcion */
		status_number = _atoi(tokens[1] ? tokens[1] : "98");
		free(current_line);

		exit(status_number < 0 ? 2 : status_number);
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
	char *current_line = NULL;
	size_t length_current_line = 0;
	unsigned int count_prompt = 0;
	char *call_to_execute = arguments_value[0];
	bool buildtin_excecuted;

	do {
		prompt(
			&current_line,
			&length_current_line,
			&count_prompt,
			isatty(STDIN_FILENO)
		);
		parser(
			current_line,
			(char **)tokens
		);
		buildtin_excecuted = buildtin(
			current_line,
			(char **)tokens,
			env,
			call_to_execute,
			&count_prompt
		);
		if (!buildtin_excecuted)
			executor(
				(char **)tokens,
				env,
				call_to_execute,
				&count_prompt
			);
	} while (true);

	return (EXIT_SUCCESS);
}

