#include "holberton.h"
/**
 * check_builtin - checks if the argument is a builtin
 * @s: builtin to search
 *
 * Return: 0 if a builtin is founded, -1 if not.
 */
int check_builtin(char *s)
{
	builtin_t builtin[] = {{"exit", exit_func},
			       {"env", display_env},
			       {NULL, NULL},
	};
	int i = 0;

	while (builtin[i].command != NULL)
	{
		if (_strcmp(s, builtin[i].command) == 0)
		{
			builtin[i].fp();
			return (0);
		}
		i++;
	}
	return (-1);
}
