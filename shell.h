#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <signal.h>
typedef unsigned char bool;

#define true (1)
#define false (0)


#define none_t (0)
#define separator_t (1)
#define or_t (2)
#define and_t (3)
/**
 * struct _data - struct
 * @current_line: current_line
 * @size_current_line: size_current_line
 * @current_characters_read: current_characters_read
 * @exit_status: exit_status
 * @count_prompt: count_prompt
 * @tokens: tokens
 * @env: env
 * @call_to_execute: call_to_execute
 * @remake_tokens: remake_tokens
 * @index_remake_tokens: index_remake_tokens
 * @size_remake_tokens: size_remake_tokens
 * @pid_last_child: pid_last_child
 * @currnet_pid: currnet_pid
 * @logic_operator: logic_operator
 */
typedef struct _data
{
	char *current_line;
	size_t size_current_line;
	ssize_t current_characters_read;


	int exit_status;
	unsigned int count_prompt;
	char **tokens;
	char **env;
	char *call_to_execute;

	char *remake_tokens;
	int index_remake_tokens;
	int size_remake_tokens;
	pid_t pid_last_child;
	char *currnet_pid;
	bool logic_operator;
} data_t;

#define fill_buffer_null(B, SIZE, T) \
do {                                 \
	int _i = SIZE;                   \
	T *_fill_buffer = (B);           \
	while (_i--)                     \
		_fill_buffer[_i] = '\0';     \
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

void prompt(data_t *, bool);
int length_string(char *);
bool includes_string(char *, char *, const bool, ...);
char *string_token_index(char **, char *, int, const char *, int);
void parser(data_t *);
unsigned int unsigned_int_to_buffer(int, char *, int);
void executor(data_t *);
bool buildtin(data_t *);
void command_execute(data_t *, char *);
void __attribute__((constructor)) add_signals(void);
char *_strtok(char *, const char *);
void hsh_print(int, const char *, ...);
bool equal_strings(char *, char *);
bool is_number(char *string);
void _buffer_concat(char *, bool, int, ...);
ssize_t _getline(data_t *data);

#define SIGN ("$ ")
#define BUFFER_SIZE (BUFSIZ)
#define SMALL_BUFFER_SIZE (1024)
#define PERROR perror("Error")
#define DEADED_CHILD (256)
#define PRINT_PRONPT write(1, SIGN, 2)
#define NEW_LINE write(1, "\n", 1)

#endif /*SHELL_H*/
