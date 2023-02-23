#include "shell.h"

/**
 * execmd - execute command
 * @argv: the argument
 *
 * Return: Always 0 (Success) -1 (Error)
 */
int execmd(char **argv)
{
	pid_t pid;
	int status;

	if (argv[0] == NULL)
	{
		free(argv);
		return (-1);
	}
	pid = fork();

	if (pid < 0)
		perror("");

	if (pid == 0)
	{
		/*execute the command with execve*/
		if (execve(argv[0], argv, environ) == -1)
			perror("Error:");
	}
	else
		wait(&status);

	free(argv);
	return (0);
}
