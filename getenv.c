#include "holberton.h"

/**
 * _getenv - function that gets an enviromental variable
 *@name: the name of the variable to get its value
 *Return: pointer to a string with the value of the enviroment variable.
 */
char *_getenv(const char *name)
{
	char **env, *env1 = NULL, *tok, *path;
	char *env_name_val[500], *env2[100];
	char *err = "Name not found";
	int i = 0, j = 0;

	if (name == NULL || *name == '\0')
		name = "PATH";
	env = environ;
	while (env[i] != NULL)
	{
		env1 = _strdup(env[i]);
		env2[i] = env1;
		tok = strtok(env1, "=");
		while (tok != NULL)
		{
			env_name_val[j] = tok;
			j++;
			tok = strtok(NULL, "=");
		}
		env_name_val[j] = NULL;
		i++;
	}
	j = 0;
	while (env_name_val[j] != NULL)
	{
		if (_strcmp(env_name_val[j], name) == 0)
		{
			path = _strdup(env_name_val[j + 1]);
			i = 0;
			while (env2[i] != NULL)
			{
				free(env2[i]);
				i++;
			}
			return (path);
		}
		j++;
	}
	return (err);
}

/**
 *_setenv -  set a envirment value to a value
 *@name: name of the variable to set
 *@value: value to set for name
 *@overwrite: flag that allow the overwrite to an existing
 *enviroment variable, 1 to overwrite, 0 to not overwrite
 *Return: 0 on sucess, -1 on failure
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
 * _unsetenv - unset a variable on the enviroment
 *@name: the variable to unset
 *Return: 0 on sucess, -1 on failure.
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
