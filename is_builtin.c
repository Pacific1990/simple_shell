#include <stdbool.h>
#include <linux/limits.h>
#include "shell.h"

/**
* is_built_in  - writes  character
* @cmd: character command
* Return: boolean
*/

bool is_built_in(char *cmd)
{
	int i;
	const char *built_in[] = {"pwd", "cd", NULL};

	for (i = 0; built_in[i]; i++)
	{
		if (!strcmp(built_in[i], cmd))
		return (true);
	}
	return (false);
}

/**
* exec_built_in - writes  character
* @built_in: character
* Return: void
*/

void exec_built_in(char **built_in)
{
	if (!strcmp(built_in[0], "pwd"))
		built_in_pwd();
	else if (!strcmp(built_in[0], "cd"))
		built_in_cd(built_in[1]);
}

