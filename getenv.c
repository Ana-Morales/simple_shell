#include "holberton.h"

/**
 * _getenv - function that gets an enviromental variable
 *@name: the name of the variable to get its value
 *Return: pointer to a string with the value of the enviroment variable.
 */
char *_getenv(const char *name)
{

	char **env, *env1 = NULL;
	char *tok, *path;
	char *env_name_val[500], *env2[100];
	char *err = "Name not found";
	int i, j;

	env = environ;
	i = 0;
	j = 0;
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
			path = _strdup(env_name_val[j+1]);
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
