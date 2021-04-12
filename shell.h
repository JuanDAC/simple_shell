#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <signal.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>



#define fill_buffer_null(B)    \
do {                           \
	char *fill_buffer = (B);   \
	while (*fill_buffer)       \
		*fill_buffer++ = '\0'; \
} while (0)





typedef unsigned char bool;
#define true (1)
#define false (!true)
#define COMMAND_NOT_FOUND (127)
#define COMMAND_NOT_EXECUTE (127)
#define GENERICS_ERROR (2)

/**
 * enum Boolean - Boolean
 * @false: type data false
 * @true: type data false
 */
/*typedef enum Boolean
{
	false,
	true
} bool;
*/
char *prompt(
	char *buffer,
	size_t *length_buffer,
	unsigned int *count_prompt,
	bool print_prompt);

int length_string(char *string);
void buffer_concat(char **buffer, char *slash, char *command);
bool includes_string(char *string, char *search_string, const bool variadic, ...);
char *string_token_index(char **string_to, char *string_from, int init_index, const char *separator, int index);
void parser(char *line, char **tokens);
unsigned int unsigned_int_to_buffer(int n, char *buffer, int i);

void executor(char **, char **, char *, unsigned int *);
void buildtin(char **,char **,char *,unsigned int *);
void command_execute(char **, char **, char *, unsigned int *, char *);

void __attribute__((constructor)) add_signals(void);

#define SIGN ("$ ")
#define BUFFER_SIZE (4096)
#define PERROR perror("Error")
#define DEADED_CHILD (256)
#define PRINT_PRONPT write(1, SIGN, 2)
#define NEW_LINE write(1, "\n", 1)


#endif /*SHELL_H*/
