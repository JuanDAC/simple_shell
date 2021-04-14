#include "shell.h"
/**
 * _strtok - string token
 * @token: string
 * @delim: delimiter
 * Return: Token finded
 */
char *_strtok(char *token, const char *delim)
{
	unsigned int i;
	bool finded_delim;
	static char *next_token;

	finded_delim = false;

	if (token == NULL)
		token = next_token;

	if (token == NULL)
		return (NULL);

	for (i = 0; token[i]; i++)
	{
		for ( ; token[i] == *delim; i++)
			if (!finded_delim)
				token[i] = '\0', finded_delim = true;
		if (finded_delim)
		{
			next_token = (token + i);
			return (token);
		}
	}
	next_token = NULL;
	return (token);
}

