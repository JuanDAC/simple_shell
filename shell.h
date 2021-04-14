#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <signal.h>

#define fill_buffer_null(B)     \
do {                            \
	int _i = 1024;              \
	char *_fill_buffer = (B);   \
	while (_i--)                \
		_fill_buffer[_i] = '\0';\
} while (0)

#define copy_in_buffer(D, S, T)   \
do {                              \
	T *_destiny = (D);            \
	T *_source = (S);             \
	while (*_source)              \
		*_destiny++ = *_source++; \
	*_destiny = '\0';             \
} while (0)

/* TODO */
#define COMMAND_NOT_FOUND (127)
#define COMMAND_NOT_EXECUTE (126)
#define GENERICS_ERROR (2)

typedef unsigned char bool;

#define true (1)
#define false (0)

void prompt(char **, size_t *, unsigned int *, bool);
int length_string(char *);
void buffer_concat(char **, char *, char *);
bool includes_string(char *, char *, const bool, ...);
char *string_token_index(char **, char *, int, const char *, int);
void parser(char *, char **);
unsigned int unsigned_int_to_buffer(int, char *, int);
void executor(char **, char **, char *, unsigned int *);
bool buildtin(char *, char **, char **, char *, unsigned int *);
void command_execute(char *, char **, char **, char *, unsigned int *);
void __attribute__((constructor)) add_signals(void);
char *_strtok(char *, const char *);
void hsh_print(int, const char *, ...);
bool equal_strings(char *, char *);
bool is_number(char *string);
#define SIGN ("$ ")
#define BUFFER_SIZE (4096)
#define PERROR perror("Error")
#define DEADED_CHILD (256)
#define PRINT_PRONPT write(1, SIGN, 2)
#define NEW_LINE write(1, "\n", 1)

#endif /*SHELL_H*/
