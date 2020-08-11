#include "holberton.h"

/**
 * _getenv - function that gets an enviromental variable
 *@name: the name of the variable to get its value
 *Return: pointer to a string with the value of the enviroment variable.
 */
char *_getenv(const char *name)
{

	char **env, *env1= NULL;
	char *tok;
	char *err = "Name not found";
	int i = 0, j = 0;

	env = environ;
	while (env[i] != NULL)
	{

		env1 =strdup(env[i]);
		tok = strtok(env1, "=");

		while (tok != NULL)
		{
			if(_strcmp(tok, name) == 0)
			{

				tok = strtok(NULL, "=");
				return(tok);
			}
			else
			{
			
				j++;
				tok = strtok(NULL, "=");
				break;
			}
		}
		i++;
	}
	return (err);
}
