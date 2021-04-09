#include "shell.h"
/**
* length_string - get length to strings
* @string: string to get length
* Return: length
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

bool includes_string(
	char *string,
	char *search_string,
	const bool variadic, ...)
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
		{
			(*string_to)[i] = string_from[i];
		}
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


void buffer_concat(char **buffer, char *slash, char *command)
{
	int i, j;

	if (!buffer || !slash || !command)
		return;

	i = length_string(*buffer);
	/* remplzamos el nulo por el string slash EJ "/bin/" */
	for (j = 0; slash[j]; j++, i++)
		(*buffer)[i] = slash[j];
	/* concatenamos el commando que nos llegue EJ "/bin/ls"*/
	for (j = 0; command[j]; j++, i++)
		(*buffer)[i] = command[j];
	/*agregamos el nulo de caracter al final*/
	(*buffer)[i] = '\0';
}

unsigned int unsigned_int_to_buffer(int n, char *buffer, int i)
{
	unsigned int num = n;
	unsigned int length = 0;

	if (num / 10)
		length = unsigned_int_to_buffer(num / 10, buffer, i + 1);
	else
		length = i;

	buffer[length - i] = (num % 10 + '0');

	if (num / 10)
	{
		buffer[length + 1] = '\0';
		return (length);
	}
	else
		return (i);
}

