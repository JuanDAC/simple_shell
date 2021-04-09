#include "shell.h"


char *prompt(
	char *buffer,
	size_t *length_buffer,
	unsigned int *count_prompt,
	bool print_prompt)
{
	ssize_t length_characters = 0;

	if (print_prompt)
		PRINT_PRONPT;
	*count_prompt += 1;
	length_characters = getline(&buffer, length_buffer, stdin);
	if (length_characters == EOF)
	{
		NEW_LINE;
		exit(EXIT_FAILURE);
	}
	/*delete '\n' in last character */
	buffer[length_characters - 1] = '\0';
	/*write(1, buffer, length_characters);*/
	return (buffer);
}
