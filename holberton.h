#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <err.h>
#include <errno.h>
#define _GNU_SOURCE

extern char **environ;
extern char *program_invocation_name;

/**
 * struct builtin_s - struct to find a built_in command
 *and its associated funct
 *
 * @command: command written by the user
 * @fp: The function associated
 */
typedef struct builtin_s
{
	char *command;
	void (*fp)(char **);
} builtin_t;

int _putchar(char c);
void _puts(char *str);
char *str_concat(char *s1, char *s2);
char *_getenv(const char *name);
int _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
char *_which(char *str);
void exit_func(char **s, int *exit_st);
void display_env(char **s);
char *_strdup(char *str);
int check_builtin(char **s);
int execute(char *comm, char *argv[], char *env[], int count);
void token_func(char *buffer, char **args);
char *_strcpy(char *dest, char *src);
void builtin_setenv(char **args);
void builtin_unsetenv(char **args);
int _setenv(char *name, char *value, int overwrite);
int _unsetenv(char *name);
int _atoi(char *s);
void fork_process(char *comm, char *args[], int count, int *exit_status);
#endif /*_HOLBERTON_H_*/
