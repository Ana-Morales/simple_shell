#include "holberton.h"

/**
 *_cd - change directory function
 *@args: - command arguments
 *Return: None
 */
void _cd(char **args)
{
	int len1, len2;
	char *crtpwd = NULL, *buffer = NULL, *home, *old;
	size_t size = 1024;

	crtpwd = getcwd(buffer, size);
	if (args[1] == NULL ||  *args[1] == '\0')
	{
		home = _getenv("HOME");
		_setenv("OLDPWD", crtpwd, 1);
		_setenv("PWD", home, 1);
		if (chdir(home) == -1)
		{
			perror("change dir:");
		}

	}
	else if (*args[1] == '-')
	{
		old = getenv("OLDPWD");
		_setenv("OLDPWD", crtpwd, 1);
		_setenv("PWD", old, 1);
		if (chdir(old) == -1)
			perror("change dir:");
	}
	else
	{
		_setenv("OLDPWD", crtpwd, 1);
		_setenv("PWD", args[1], 1);
		if (chdir(args[1]) == -1)
		{
			len1 = _strlen(program_invocation_name);
			len2 = _strlen(": 1: cd: can't cd to ");
			write(STDERR_FILENO, program_invocation_name, len1);
			write(STDERR_FILENO, ": 1: cd: can't cd to ", len2);
			write(STDERR_FILENO, args[1], _strlen(args[1]));
			write(STDERR_FILENO, "\n", 1);
		}
	}
	free(crtpwd);
}
