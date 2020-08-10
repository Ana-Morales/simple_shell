#include "holberton.h"

/**
 * _getenv - function that gets an enviromental variable
 *@name: the name of the variable to get its value
 *Return: pointer to a string with the value of the enviroment variable.
 */
char *_getenv(const char *name)
{

	char **env, *env1 = NULL;
	char *tok;
	char *env_name_val[500];
	char *err = "Name not found";
	int i, j;

	env = environ;
	i = 0;
	j = 0;
	while (env[i] != NULL)
	{
		env1 = _strdup(env[i]);
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
			return (env_name_val[j + 1]);
		}
		j++;
	}

	return (err);
}
