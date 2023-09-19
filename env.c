#include "shell.h"

/**
* afficher_environ - prints the environment string to stdout
* Return: rien
*/

void afficher_environ(void)
{
	int i = 0;
	char **env = environ;

	while (env[i])
	{
		write(STDOUT_FILENO, (const void *)env[i], strlenght(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
