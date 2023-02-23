#include "shell.h"

/**
 * main - the main function
 * @ac: number of arguments passed
 * @argv: arguments passed
 *
 * Return: Always 0 (Success)
 */

int main(int ac, char **argv)
{
	char *prompt = "(cisfun) $ ";
	size_t n = 0;
	ssize_t nchars_read;
	char **av, *lineptr = NULL;

	/*declaring void variables*/
	(void)ac;
	(void)argv;

	/*create an infinite loop*/
	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);

		/*check if the getline function failed or reached EOF*/
		if (nchars_read == -1)
		{
			printf("\n");
			free(lineptr);
			return (0);
		}
		av = get_arguments(lineptr);
		execmd(av);
	}

	return (0);
}
/**
 * get_arguments - get arguments passed on terminal
 * @lineptr: pointer to the line args
 *
 * Return: array of strings
 */
char **get_arguments(char *lineptr)
{
	const char *delim = " \r\t\n";
	char *token;
	int i = 0;
	char **argv = malloc(sizeof(char *) * 100);

	token = strtok(lineptr, delim);
	while (token)
	{
		argv[i] = token;
		i++;

		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	return (argv);
}
