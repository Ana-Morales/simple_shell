#include "holberton.h"

/*
 * This document contains the built_in functions for the simple shell
 *
 */

/**
 * exit_func - this function closes the prompt when the exit command is passed
 * @args: Pointer with the direction to free  the allocated memory for
 * the  arguments passed to the program.
 * Return: None
 */
void exit_func(char **args)
{
	int exit_status = 0, len1 = 0, len2 = 0;

	if (args[1] == NULL)
	{
		free(*args);
		exit(EXIT_SUCCESS);
	}

	exit_status = _atoi(args[1]);
	if (exit_status == -1)
	{
		len1 = _strlen(program_invocation_name);
		len2 = _strlen(": 1: exit: Illegal number: ");
		write(STDERR_FILENO, program_invocation_name, len1);
		write(STDERR_FILENO, ": 1: exit: Illegal number: ", len2);
		write(STDERR_FILENO, args[1], _strlen(args[1]));
		write(STDERR_FILENO, "\n", 1);
	}
	else
	{
		free(*args);
		exit(exit_status);
	}
}

/**
 * display_env - This funcition prints in the stdout
 * the enviromental variables.
 * @args: Pointer with the direction to free  the allocated memory for
 * the  arguments passed to the program.
 * Return: None.
 */
void display_env(char __attribute__((__unused__)) **args)
{
	char **ep;

	for (ep = environ; *ep != NULL; ep++)
		_puts(*ep);
}
/**
 * builtin_setenv - Initialize a new environment variable,
 * or modify an existing one
 * @args: Pointer to the call to the function and its arguments
 * Return: None.
 */
void builtin_setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 29);
	}
	else
	{
		_setenv(args[1], args[2], 1);
	}
}
/**
 * builtin_unsetenv - Remove an environment variable
 * @args: Pointer to the call to the function and its arguments
 * Return: None.
 */
void builtin_unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 25);
	}
	else
		_unsetenv(args[1]);
}
/**
 * _atoi -  convert a string to an integer
 * @s: string to convert
 * Return: the integer detected
 */
int _atoi(char *s)
{
	unsigned int res = 0;


	while (*s != '\0')
	{
		if (*s == '-')
		{
			return (-1);
		}
		else if (*s >= '0' && *s <= '9')
		{
			res = (res * 10) + (*s - '0');
		}
		else
			return (-1);
		s++;

	}
	return (res);
}
