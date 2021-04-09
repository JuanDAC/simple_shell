#include "shell.h"

#define ARGS_UNUSED int c __attribute__((unused)), \
	char **v __attribute__((unused))

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
int main(ARGS_UNUSED, char **env)
{
	char *tokens[BUFFER_SIZE];
	char current_line[BUFFER_SIZE];
	size_t length_current_line = BUFFER_SIZE;


	if (isatty(STDIN_FILENO))
	{	
		do {
			/* (void) -> prompt() -> string */
			prompt(current_line, &length_current_line, true);
			/* (string) -> parser() -> tokens[] */  
			parser(current_line, (char **)tokens);
			if (includes_string(tokens[0], "exit", false))
				exit(atoi(tokens[1] ? tokens[1] : "98"));
			/* (tokens[]) -> (evn) -> executor() -> "status" */
			executor((char **)tokens, env);
		} while (1);
	}	
	else
	{
		prompt(current_line, &length_current_line, false);
		parser(current_line, (char **)tokens);
		executor((char **)tokens, env);
	}

	return (0);
}
