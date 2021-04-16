#include "shell.h"

/**
* equal_strings - determines whether @string includes a search_string
* @string: string to get length
* @search_string: subtring in @string
* Return: true or false as appropriate
*/
bool equal_strings(
	char *string,
	char *search_string
)
{
	if (!string || !search_string)
		return (false);

	if (!*string && !*search_string)
		return (true);

	if (*string != *search_string)
		return (false);

	return (equal_strings(string + 1, search_string + 1));
}

/**
*is_number - check number
*@string: string to check
*Return: true in case its a number else false
*/
bool is_number(char *string)
{
	if (*string == '\0')
		return (true);
	return ((*string >= '0' && *string <= '9') && is_number(string + 1));
}

/**
* _buffer_concat - determines whether @string includes a search_string
* @buffer: string to get length
* @in_last: string to get length
* @count: string to get length
* Return: true or false as appropriate
*/
void _buffer_concat(char *buffer, bool in_last, int count, ...)
{
	int i, j;
	va_list argumets;
	char *current_string;

	if (!buffer)
		return;

	va_start(argumets, count);
	i = (in_last) ? length_string(buffer) : 0;

	while (count--)
	{
		current_string = va_arg(argumets, char *);
		for (j = 0; current_string[j] != '\0'; i++, j++)
			buffer[i] = current_string[j];
	}

	buffer[i] = '\0';
	va_end(argumets);
}

