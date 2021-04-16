#include "shell.h"


/**
* length_string - get length to strings
* @string: any string than last position it's a null character value
* Return: length of the @string
*/
int length_string(char *string)
{
	/* string == NULL return length 0 */
	if (!string)
		return (0);
	/* *string == '\0' return length 0 */
	if (!*string)
		return (0);
	/* add weight of a character than 1 */
	return (1 + length_string(string + 1));
}

/**
* includes_string - determines whether @string includes a search_string
* @string: string to get length
* @search_string: subtring in @string
* @variadic: active variadic
* Return: true or false as appropriate
*/
bool includes_string(
	char *string,
	char *search_string,
	const bool variadic, ...
)
{
	int from_index;
	va_list argumets;

	/* validate pointer NULL */
	va_start(argumets, variadic);
	from_index = (variadic) ? va_arg(argumets, int) : 0;
	string += from_index;

	if (!string || !search_string)
		return (false);

	if (!*string || !*search_string)
		return (true);

	if (*string != *search_string)
		return (false);

	va_end(argumets);
	return (includes_string(string + 1, search_string + 1, false));
}

/**
* string_token_index - copy index to @string_to from @string_from
* @string_to: string buffer destiny
* @string_from: from to copy
* @init_index: index to init search
* @index: index to to get
* @separator: separator becouse index
* Return: true or false as appropriate
*/
char *string_token_index(
	char **string_to,
	char *string_from,
	int init_index,
	const char *separator,
	int index
)
{
	int i;

	if (!string_to || !string_from || !separator)
		return (NULL);

	if (*string_from == '\0')
		return (NULL);

	string_from += init_index;

	/* caso base. indice indicado*/
	if (index == 0)
	{
		/*copiar en @string_to hasta el delimitador o un nulo caracter*/
		for (i = 0; !(string_from[i] == *separator || string_from[i] == '\0'); i++)
			(*string_to)[i] = string_from[i];
		(*string_to)[i] = '\0';
		return (*string_to);
	}

	/*moverte de index*/
	if (*string_from == *separator)
	{
		while (*(string_from + 1) == *separator)
			string_from++;
		index = index - 1;
	}

	return (
		string_token_index(string_to, string_from + 1, 0, separator, index)
	);
}

/**
* count_includes_characters - count includes characters
* @string: string to search
* @character: character a buscar
* Return: number of eachs character includes
*/
int count_includes_characters(char *string, char character)
{
	if (!string || !*string)
		return (0);

	if (*string == character)
		return (1 + count_includes_characters(string + 1, character));

	return (count_includes_characters(string + 1, character));
}

/**
* unsigned_int_to_buffer - determines whether @string includes a search_string
* @number: number to transform
* @buffer: buffer to save
* @idx: index of a buffer
* Return: true or false as appropriate
*/
unsigned int unsigned_int_to_buffer(int number, char *buffer, int idx)
{
	unsigned int num = number;
	unsigned int length = 0;

	if (num / 10)
		length = unsigned_int_to_buffer(num / 10, buffer, idx + 1);
	else
		length = idx;

	buffer[length - idx] = (num % 10 + '0');

	if (num / 10)
	{
		buffer[length + 1] = '\0';
		return (length);
	}
	else
		return (idx);
}

