#include "shell.h"

/**
* prompt - implements features of prompt
* @current_line: current line alloc
* @length_line: length of line alloc
* @count_prompt: save the count the prints prompt
* @print_prompt: true if is a tty else false
* Return: void
*/
void prompt(
	char **current_line,
	size_t *length_line,
	/* arrive as a reference */
	unsigned int *count_prompt,
	bool print_prompt)
{
	ssize_t length_characters = 0;

	if (print_prompt)
		PRINT_PRONPT;
	/* add one in value */
	*count_prompt += 1;
	length_characters = getline(current_line, length_line, stdin);
	if (length_characters == EOF)
	{

		free(*current_line);
		if (print_prompt)
			NEW_LINE;
		exit(EXIT_SUCCESS);
	}
	/*delete '\n' in last character to replace with a '\0' */
	(*current_line)[length_characters - 1] = '\0';
}

