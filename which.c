#include "holberton.h"
/**
 * _which - shows the full path of commands
 * @str: command
 *
 * Return: path of the command.
 */
char *_which(char *str)
{
	unsigned int j = 0;
	struct stat st;
	char *path, *path1, *path_dup;
	char *token, *str1;
	char *slash = "/";
	char *path_path[100];

	path = _getenv("PATH");
	path1 = _strdup(path);
	token = strtok(path1, ":");
	while (token != NULL)
	{
		path_path[j] = token;
		j++;
		token = strtok(NULL, ":");
	}
	path_path[j] = NULL;

	str1 = str_concat(slash, str);

	for (j = 0; path_path[j] != NULL; j++)
	{
		path_path[j] = str_concat(path_path[j], str1);
		if (stat(path_path[j], &st) == 0)
		{
			path_dup = _strdup(path_path[j]);
			while (j--)
			{
				free(path_path[j]);
			}
			free(str1);
			return (path_dup);
		}
	}
	return (str);
}
