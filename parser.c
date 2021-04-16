#include "shell.h"
#include <string.h>
/**
* parser - split the lines with delimiter of spaces
* @data: tokens the input user
* Return: void
*/
void parser(data_t *data)
{
	int i = 0;

	do {
		data->tokens[i] = strtok(i ? NULL : data->current_line, " ");
		/*if (count_includes_characters(, )) */
	} while (data->tokens[i++]);
}
