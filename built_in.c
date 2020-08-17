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
	free(args);
	exit(EXIT_SUCCESS);
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
