#include "main.h"

void execmd(char **argv)
{
	pid_t pid;
	int status;

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
	{
		wait(&status);
	}
}
