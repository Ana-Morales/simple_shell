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

extern char **environ;

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
	void (*fp)(void);
} builtin_t;

int _putchar(char c);
void _puts(char *str);
char *str_concat(char *s1, char *s2);
char *_getenv(const char *name);
int _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
char *_which(char *str);
void exit_func(void);
void display_env(void);
char *_strdup(char *str);
int check_builtin(char *s);
int execute(char *comm, char *argv[], char *env[]);
char **token_func(char *buffer, char **argv);
#endif /*_HOLBERTON_H_*/
