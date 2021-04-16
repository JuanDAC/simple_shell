#include "shell.h"


/**
 * _getline - delimited string input
 * @data: global data
 * Return: return the number of characters read -1 on failure to read a line
 */
ssize_t _getline(data_t *data)
{
	static int characters;
	static char readed[BUFFER_SIZE];
	static char *index_of;
	char *current_line;
	int i;
	ssize_t counter = 0;

	current_line = data->current_line;
	if (characters == 0)
	{
		characters = read(STDIN_FILENO, readed, sizeof(readed));
		index_of = readed;
	}

	if (characters > 0)
	{
		for (i = 0;
				*index_of != '\n'
				&& *index_of != ';'
				&& (*index_of != '&' && *(index_of + 1) != '&')
				&& (*index_of != '|' && *(index_of + 1) != '|');
			i++)
			*current_line++ = *index_of++, characters--, counter++;
		if (*index_of == ';')
		{
			data->logic_operator = true;
		}
		else
		{
			data->logic_operator = false;
		}
		*current_line = '\0', characters--, index_of++;
		return (counter);
	}

	return (EOF);
}










