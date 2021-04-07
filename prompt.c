


char *prompt(char *buffer, size_t *length_buffer)
{
	ssize_t length_characters = 0;

	write(1, SIGN, 2);
	length_characters = getline(&buffer, length_buffer, stdin);
	/*delete '\n' in last character */
	buffer[length_characters - 1] = '\0';
	/*write(1, buffer, length_characters);*/
	return (buffer);
}
