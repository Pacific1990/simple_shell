#include "shell.h"

/**
 * built_in_cd - function
 *
 * @path: argument path
 * Return: void
 */

void built_in_cd(char *path)
{
	if (chdir(path) == -1)
	{
		perror("chdir()");
	}
}
