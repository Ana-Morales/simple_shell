#include "holberton.h"

/**
 * main - main function for our shell
 *
 * Return: Always 0.
 */
int main(void)
{
	int chars, count = 0, exit_status = 0;
	char *args[100], *comm, *buffer = NULL;
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
			{
				continue;
			}
			if (_strcmp(args[0], "exit") == 0)
			{
				exit_func(&args[0], &exit_status);
				continue;
			}
			comm = _which(args[0]);
			fork_process(comm, args, count, &exit_status, buffer);

		}
		else
		{
			free(buffer);
			exit(exit_status);
		}
	}
	return (EXIT_SUCCESS);
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
		token = strtok(NULL, " \n\t");
	}
	args[i] = NULL;
}
/**
 * execute - executes the associated command
 * @comm: command to be executed
 * @args:  array of argument strings passed to the command
 * @env: array of strings passed as environment to command
 * @count: counter for the number of executed commands
 * @b: Pointer to buffer.
 * Return: Always 0.
 */
int execute(char *comm, char *args[], char *env[], int count, char *b)
{
	int len1 = 0;
	(void)count;
	if  (execve(comm, args, env) == -1)
	{
		len1 = _strlen(program_invocation_name);
		write(STDERR_FILENO, program_invocation_name, len1);
		write(STDERR_FILENO, ": 1: ", 5);
		write(STDERR_FILENO, args[0], _strlen(args[0]));
		write(STDERR_FILENO, ": not found\n", 12);
		free(b);
		exit(127);
	}
	return (0);
}
/**
 * fork_process - creates a child process
 * @comm: command to be executed by the child process
 * @args:  array of argument strings passed to the command
 * @count: counter for the number of executed commands
 * @exit_stat: pointer to set the exit status of the children process
 * @b: pointer to buffer
 */
void fork_process(char *comm, char *args[], int count, int *exit_stat, char *b)
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (child_pid == 0)
		execute(comm, args, NULL, count, b);
	else
	{
		wait(&status);
		if (_strcmp(comm, args[0]) != 0)
			free(comm);
		if (WIFEXITED(status))
			*exit_stat = WEXITSTATUS(status);
	}
}
