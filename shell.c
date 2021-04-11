#include "shell.h"

void sigint_handler()
{
	signal(SIGINT, sigint_handler);
	NEW_LINE;
	PRINT_PRONPT;
	fflush(stdout);
}

void add_signals(void)
{
	/* signal SIGINT of Ctrl+C */
	signal(SIGINT, sigint_handler);
}

int _atoi(char *string_number)
{
	int i, resolve, scale;

	i = length_string(string_number) - 1;
	resolve = 0;
	for (scale = 1; i >= 0; i -= 1, scale *= 10)
	{
		resolve += (string_number[i] & 0x0F) * scale;
	}

	return (resolve);
}

void buildtin(char **tokens, char **env, char *call_to_execute, unsigned int *count_prompt)
{
	(void)env;
	(void)call_to_execute;
	(void)count_prompt;
	if (includes_string(*tokens, "exit", false))
	{
		exit(_atoi(tokens[1] ? tokens[1] : "98"));
	}
}

/**
 * main - entry point
 * @ARGS_UNUSED: argc and argv
 * @env: argc and argv
 * Return: o if success
 */
int main(
	int c __attribute__((unused)),
	char **arguments_value,
	char **env)
{
	char *tokens[BUFFER_SIZE];
	char current_line[BUFFER_SIZE];
	size_t length_current_line = BUFFER_SIZE;
	unsigned int count_prompt = 0;
	char *call_to_execute = *arguments_value;

	if (isatty(STDIN_FILENO))
	{
		do {
			/* (void) -> prompt() -> string */
			prompt(
				current_line,
				&length_current_line,
				&count_prompt,
				true
			);
			/* (string) -> parser() -> tokens[] */  
			parser(current_line, (char **)tokens);
			/* (tokens[]) -> (evn) -> executor() -> "status" */
			
			buildtin((char **)tokens, env, call_to_execute, &count_prompt);
			executor((char **)tokens, env, call_to_execute, &count_prompt);
		} while (1);
	}
	else
	{
		prompt(
			current_line,
			&length_current_line,
			&count_prompt,
			false
		);
		parser(current_line, (char **)tokens);
		buildtin((char **)tokens, env, call_to_execute, &count_prompt);
		executor((char **)tokens, env, call_to_execute, &count_prompt);
	}

	return (0);
}

