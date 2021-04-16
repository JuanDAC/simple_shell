#include "shell.h"
#include <string.h>

#define EXPAND_PID                                    \
do {                                                  \
	if (data->tokens[i][j + 1] == '$')                \
	{                                                 \
		copy_in_buffer(data->remake_tokens + k,       \
			data->currnet_pid, char);                 \
		k += length_string(data->remake_tokens + k);  \
	}                                                 \
} while (false)

#define PROCEESS_EXPAND                                                  \
do {                                                                     \
	data->remake_tokens[k + 1] = '\0';                                   \
	data->tokens[i] = data->remake_tokens;                               \
	data->index_remake_tokens += length_string(data->remake_tokens) + 1; \
	data->remake_tokens += length_string(data->remake_tokens) + 1;       \
	expand = false;                                                      \
} while (false)

/**
* parser - split the lines with delimiter of spaces
* @data: tokens the input user
* Return: void
*/
void parser(data_t *data)
{
	int i = 0, j, k;
	bool expand = false;


	fill_buffer_null(
		(char *)(data->remake_tokens),
		data->size_remake_tokens - (data->index_remake_tokens + 1),
		char
	);
	do {
		data->tokens[i] = strtok(i ? NULL : data->current_line, " ");
		for (j = 0, k = 0; data->tokens[i] && data->tokens[i][j]; j++, k++)
		{
			if (data->tokens[i][j] == '$')
			{
				EXPAND_PID;
				expand = true;
			}
			else
			{
				data->remake_tokens[k] = data->tokens[i][j];
			}
			if (data->tokens[i][j + 1] == '\0' && expand)
			{
				PROCEESS_EXPAND;
			}
			else if (!expand)
			{
				fill_buffer_null((char *)(data->remake_tokens),
					data->size_remake_tokens - (data->index_remake_tokens + 1),
					char);
			}
		}
	} while (data->tokens[i++]);
}
