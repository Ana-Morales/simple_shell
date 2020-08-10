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
	char *path, *path1;
	char *token, *str1, *path_3;
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
	free(path1);
	path_path[j] = NULL;

	str1 = str_concat(slash, str);

	for (j = 0; path_path[j] != NULL; j++)
	{
		path_3 = str_concat(path_path[j], str1);
		if (stat(path_3, &st) == 0)
		{
			return (path_3);
		}
	}
	return (str);
}
