#ifndef SHELL_HEADER
#define SHELL_HEADER

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

int execmd(char **argv);
extern char **environ;
char **get_arguments(char *lineptr);

#endif
