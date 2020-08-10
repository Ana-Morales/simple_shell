#include "holberton.h"
/**
 * main - main function for our shell
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int status, chars, satty = 0;
	char **argv, *comm, *buffer = NULL;
	size_t bufsize = 32;

	satty = isatty(0);
	while (1)
	{
		if (satty == 1)
			printf("$ ");
		signal(SIGINT, SIG_IGN);
		chars = getline(&buffer, &bufsize, stdin);
		if (chars == 1)
			continue;
		if (chars != -1)
		{
			argv = token_func(buffer, argv);
			if (argv[0] == NULL || check_builtin(argv[0]) == 0)
				continue;
			comm = _which(argv[0]);
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error");
				return (1);
			}
			if (child_pid == 0)
				execute(comm, argv, NULL);
			else
				wait(&status);
		}
		else
			break;
	}
	return (0);
}
/**
 * token_func - function to call strtok function
 * @buffer: buffer with string to be broke into tokens
 * @argv:  array of strings where tokens will be stored
 *
 * Return: pointer to array with tokens
 */
char **token_func(char *buffer, char **argv)
{
	int i = 0;
	char *token;

	token = strtok(buffer, " \n");
	for (i = 0; token != NULL; i++)
	{
		argv[i] = token;
		token = strtok(NULL, " \n");
	}
	argv[i] = NULL;
	return (argv);
}
/**
 * execute - executes the associated command
 * @comm: command to be executed
 * @argv:  array of argument strings passed to the command
 * @env: array of strings passed as environment to command
 * Return: Always 0.
 */
int execute(char *comm, char *argv[], char *env[])
{
	if  (execve(comm, argv, env) == -1)
	{
		perror("./shell");
		exit(EXIT_SUCCESS);
	}
	return (0);
}
