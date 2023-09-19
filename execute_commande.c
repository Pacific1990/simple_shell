#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

/**
* exec_cmd -execute command  function
* @cmd: arg cmd
*
* Return: void
*/

void exec_cmd(char **cmd)
{
	pid_t pid = 0;
	int status = 0;
	pid = fork();
	
	if (pid == -1)
		perror("fork");
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		if (execve(cmd[0], cmd, NULL) == -1)
			perror("shell");
		exit(EXIT_FAILURE);
	}
}

