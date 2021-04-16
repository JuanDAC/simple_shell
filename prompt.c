#include "shell.h"
#include <stdio.h>
/**
* prompt - implements features of prompt
* @data: current line alloc
* @print_prompt: save the count the prints prompt
* Return: void
*/
void prompt(data_t *data, bool print_prompt)
{
	if (print_prompt)
		PRINT_PRONPT;
	/* add one in value */
	data->count_prompt += 1;
	data->current_characters_read = getline(
		&data->current_line,
		&data->size_current_line,
		stdin
	);
	if (data->current_characters_read == EOF)
	{
		free(data->current_line);
		if (print_prompt)
			NEW_LINE;
		exit(data->exit_status);
	}
	/*delete '\n' in last character to replace with a '\0' */
	data->current_line[data->current_characters_read - 1] = '\0';
}

