#include "holberton.h"

/**
 * main - main function for our shell
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int status, chars, satty = 0, checkcommand = 0, count = 0;
	char *args[10], *comm, *buffer = NULL;
	size_t bufsize = 1024;



	satty = isatty(STDIN_FILENO);
	while (1)
	{
		if (satty == 1)
			write(STDOUT_FILENO, "$ ", 2);
		count++;
		signal(SIGINT, SIG_IGN);
		chars = getline(&buffer, &bufsize, stdin);
		if (chars == 1)
			continue;
		if (chars != -1)
		{
			token_func(buffer, args);
			if (args[0] == NULL || check_builtin(args[0]) == 0)
				continue;
			comm = _which(args[0]);
			if (_strcmp(comm, args[0]) == 0)
				checkcommand = 1;
			else if (_strcmp(comm, args[0]) != 0)
				checkcommand = 0;
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error");
				return (1);
			}
			if (child_pid == 0)
				execute(comm, args, NULL, count);
			else
			{
				wait(&status);
				if (checkcommand == 0)
					free(comm);
			}
		}
		else
			break;
	}
	return (0);
}
/**
 * token_func - function to call strtok function
 * @buffer: buffer with string to be broke into tokens
 * @args:  array of strings where tokens will be stored
 *
 * Return: pointer to array with tokens
 */
void token_func(char *buffer, char **args)
{
	int i = 0;
	char *token;

	token = strtok(buffer, " \n\t");
	for (i = 0; token != NULL; i++)
	{
		args[i] = token;
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;
	return;
}
/**
 * execute - executes the associated command
 * @comm: command to be executed
 * @args:  array of argument strings passed to the command
 * @env: array of strings passed as environment to command
 * Return: Always 0.
 */
int execute(char *comm, char *args[], char *env[], int count)
{
	if  (execve(comm, args, env) == -1)
	{
		write(STDERR_FILENO, "./", 2);
		errx(EXIT_FAILURE, "%d: %s: not found", count, comm);
	}
	return (0);
}
