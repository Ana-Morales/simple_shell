#include "holberton.h"

/*
 * This document contains the built_in functions for the virtual shell
 *
 */

/**
 * exit_func - this function closes the prompt when the exit command is passed
 * Return: None
 */
void exit_func(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * display_env - This funcition prints in the stdout
 *the enviromental variables.
 * Return: None.
 */
void display_env(void)
{
	char **ep;

	for (ep = environ; *ep != NULL; ep++)
		_puts(*ep);
}
