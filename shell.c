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

	(void)call_to_execute;
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
			if (includes_string(tokens[0], "exit", false))
				exit(atoi(tokens[1] ? tokens[1] : "98"));
			/* (tokens[]) -> (evn) -> executor() -> "status" */
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
		executor((char **)tokens, env, call_to_execute, &count_prompt);
	}

	return (0);
}
