#include "holberton.h"

/**
 * main - main function for our shell
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int status, chars, count = 0, exit_status;
	char *args[10], *comm, *buffer = NULL;
	size_t bufsize = 1024;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);
		count++;
		signal(SIGINT, SIG_IGN);
		chars = getline(&buffer, &bufsize, stdin);
		if (chars == 1)
			continue;
		if (chars != -1)
		{
			token_func(buffer, args);
			if (args[0] == NULL || check_builtin(&args[0]) == 0)
				continue;
			if (_strcmp(args[0], "exit") == 0)
			{
				exit_func(&args[0], &exit_status);
				continue;
			}
			comm = _which(args[0]);
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
				if (_strcmp(comm, args[0]) != 0)
					free(comm);
				if (WIFEXITED(status))
				{
					exit_status = WEXITSTATUS(status);
					if (exit_status == 1)
						exit_status = 127;
				}
			}
		}
		else
			exit(exit_status);
	}
	exit(exit_status);
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
}
/**
 * execute - executes the associated command
 * @comm: command to be executed
 * @args:  array of argument strings passed to the command
 * @env: array of strings passed as environment to command
 * @count: counter for the number of executed commands
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
