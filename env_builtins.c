#include "holberton.h"
/**
 * _setenv -  Initialize a new environment variable, or modify an existing one
 * @name: Variable to be initialized
 * @value: value
 * @overwrite: indicator to overwtrite or not de variable
 * Return: 0 on success, -1 on fail.
 */
int _setenv(char *name, char *value, int overwrite)
{
	char *str1, *tok, **env, *env1 = NULL;
	int i = 0;

	if (name == NULL || *name == '\0')
		return (-1);
	while (name[i] != '\0')
	{
		if (name[i] == '=')
			return (-1);
		i++;
	}
	env = environ;
	while (env[i] != NULL)
	{
		env1 = _strdup(env[i]);
		tok = strtok(env1, "=");
		if (_strcmp(name, tok) == 0)
		{
			if (overwrite != 0)
			{
				str1 = str_concat(name, "=");
				env[i] = str_concat(str1, value);
				free(str1);
				free(env1);
				return (0);
			}
			free(env1);
			return (0);
		}
		free(env1);
		i++;
	}
	str1 = str_concat(name, "=");
	env[i] = str_concat(str1, value);
	free(str1);
	env[i + 1] = NULL;
	return (0);
}
/**
 * _unsetenv - Remove an environment variable
 * @name: Variable to be removed
 * Return: 0 on success, -1 on fail.
 */
int _unsetenv(char *name)
{
	char *tok, **env, *env1 = NULL;
	int i = 0;

	if (name == NULL || *name == '\0')
		return (-1);
	while (name[i] != '\0')
	{
		if (name[i] == '=')
			return (-1);
		i++;
	}
	env = environ;
	while (env[i] != NULL)
	{
		env1 = _strdup(env[i]);
		tok = strtok(env1, "=");
		if (_strcmp(name, tok) == 0)
		{
			while (env[i + 1] != NULL)
			{
				env[i] = env[i + 1];
				i++;
			}
			env[i] = NULL;
			free(env1);
			return (0);
		}
		free(env1);
		i++;
	}
	return (0);
}
