#include "holberton.h"

/**
 * _getenv - function that gets an enviromental variable
 *@name: the name of the variable to get its value
 *Return: pointer to a string with the value of the enviroment variable.
 */
char *_getenv(const char *name)
{
	char **env = NULL, *env1 = NULL, *tok = NULL, *path = NULL;
	int i = 0;

	if (name == NULL || *name == '\0')
		name = "PATH";
	env = environ;
	while (env[i] != NULL)
	{
		env1 = _strdup(env[i]);
		tok = strtok(env1, "=");
		while (tok != NULL)
		{
			if (_strcmp(name, tok) == 0)
			{
				tok = strtok(NULL, "=");
				path = _strdup(tok);
				free(env1);
				return (path);
			}
			else
			{
				free(env1);
				break;
			}
		}
		i++;
	}
	return (NULL);
}
