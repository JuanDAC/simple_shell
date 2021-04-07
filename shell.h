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


#define SIGN ("$ ")
#define BUFFER_SIZE (4096)


#endif /*SHELL_H*/
