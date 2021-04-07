#include "shell.h"


#define ARGS_UNUSED int c __attribute__((unused)), \
	char **v __attribute__((unused))

/**
 * main - entry point
 * @ARGS_UNUSED: argc and argv
 * @env: argc and argv
 * Return: o if success
 */
int main(ARGS_UNUSED, char **env __attribute__((unused)))
{
	char **tokens;
	char current_line[BUFFER_SIZE];
	size_t length_current_line = BUFFER_SIZE;

	/*extract_path(env, &current_path);*/

	do {
		/* (void) -> prompt() -> string */
		prompt(current_line, &length_current_line);
		/* (string) -> parser() -> tokens[] */
		tokens = parser(current_line);
		(void)tokens;
		/*write(1, *tokens, length_string(*tokens));*/
		/* (tokens[]) -> (evn) -> executor() -> "status" */
	} while (1);

	return (0);
}
