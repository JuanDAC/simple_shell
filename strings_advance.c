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



