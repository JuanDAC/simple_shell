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

/**
 * enum Boolean - Boolean
 * @false: type data false
 * @true: type data false
 */
typedef enum Boolean
{
	false,
	true
} bool;

char *prompt(char *buffer, size_t *length_buffer);
int length_string(char *string);
bool includes_string(char *string, char *search_string, const bool variadic, ...);
char *string_token_index(char **string_to, char *string_from, int init_index, const char *separator, int index);
void parser(char *, char **);

#define SIGN ("$ ")
#define BUFFER_SIZE (4096)


#endif /*SHELL_H*/