#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**
 * command - function
 * Return: integer
 */

int command(void)
{
	char *buffer = NULL;
	size_t buf_size = 2048;
	char **cmd = NULL;

	buffer = (char *)calloc(sizeof(char), buf_size);
	if (buffer == NULL)
	{
		perror("Malloc failure");
		return (EXIT_FAILURE);
	}
	write(1, "$> ", 3);
	while (getline(&buffer, &buf_size, stdin) > 0)
	{
		cmd = split(buffer, " \n\t");
		if (cmd[0] == NULL)
			printf("Command not found\n");
		else if (is_built_in(cmd[0]) == false)
		{
			get_absolute_path(cmd);
			exec_cmd(cmd);
		}
		else
			exec_built_in(cmd);
		write(1, "$> ", 3);
		free_array(cmd);
	}
	printf("Bye \n");
	free(buffer);
	return (0);
}
