#include "shell.h"

/**
<<<<<<< HEAD
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
=======
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
	error = argv;

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
>>>>>>> 9c7aebbcb8c531cfd94f22078050f30786820a6e
}
