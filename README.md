Holberton Shell
## _simple shell readme_

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

This repository contains the files for Holberton's simple_shell. It can be compiled using GCC and will execute a simple shell that can be used for some basic tasks and programs most commonly found in the /bin/ folder.

## Pre-requisites
Authorized functions and macros:
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)

GCC command to compile:
```sh
$| gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```


This wil compile all the '.c' files and change the output's name to 'hsh'.
## Features

Simple shell made in C to interact with a linux operating system. Has an entry point who comutes arguments to the C program in the PATH enviroment .It reads the command line from the standard input, this shell allocs the tokens given by the user, it saves the print prompt in the environment variables


## Test Output

#### It works both

Interactive mode:
```sh
$| ./hsh
$ ls
AUTHORS            makefile            prompt.c   shell.h            _strtok.c
command_execute.c  man_1_simple_shell  README.md  strings_advance.c
executor.c         parser.c            shell.c    strings_basics.c
$ exit
$|
```

#### Non-interactive mode:

```sh
$| echo "ls" | ./hsh
AUTHORS            makefile            prompt.c   shell.h            _strtok.c
command_execute.c  man_1_simple_shell  README.md  strings_advance.c
executor.c         parser.c            shell.c    strings_basics.c
$|
```

#### To exit program in interactive mode:

The output of this program when executed it look like:
```sh
$ exit
```

## Example

```sh
$| ls -l *.c
```

## Description

| Function | Description |
| ------ | ------ |
| sigint_handler | sigint handler signal of Ctrl+C |
| add_signals  | add events listeners of signals |
|_atoi  |convert a string to an integer  |
| buildtin | execute builtin function |
| main | entry point |
|_strtok| string tokenization |
|count_includes_characters| count includes characters|
|hsh_print| mini printf |
|error_handler| error handler of a child command |
|command_execute | executes a command in the shell |
|which | It saves the command in @command variable |
|executor | call logic to search source and command execute|
|prompt| implements features of the prompt|
|equal_strings| determines whether @string includes a search_string|
|length_string | get the length of a string|

## License

Holberton school

## AUTHORS
Paola Carrero, Juan David Avila , Nicolas Gonzalez Delgado

