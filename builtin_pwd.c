#include "shell.h"

/**
 * built_in_pwd - function
 *
 */
void built_in_pwd(void)
{
	char cwd[4096];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s\n", cwd);
	}
	else
	{
		perror("getcwd()");
	}
}
