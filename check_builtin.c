#include "holberton.h"
/**
 * check_builtin - checks if the argument is a builtin
 * @s: builtin to search
 *
 * Return: 0 if a builtin is founded, -1 if not.
 */
int check_builtin(char **s)
{
	builtin_t builtin[] = {
		{"env", display_env},
		{"setenv", builtin_setenv},
		{"unsetenv", builtin_unsetenv},
		{NULL, NULL},
	};
	int i = 0;

	while (builtin[i].command != NULL)
	{
		if (_strcmp(*s, builtin[i].command) == 0)
		{
			builtin[i].fp(s);
			return (0);
		}
		i++;
	}
	return (-1);
}
