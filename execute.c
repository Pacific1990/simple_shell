#include "shell.h"

/**
 * execute - executer les commandes entrees
 *@ma_commande: command
 *@entree: array of pointers to commands
 * Return: 0
 */

void execute(char *ma_commande, char **entree)
{
	pid_t child_pid;
	int state;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(ma_commande);
	if (child_pid == 0)
	{
		execve(ma_commande, entree, env);
		perror(ma_commande);
		free(ma_commande);
		liberer(entree);
		exit(98);
	}
	else
		wait(&state);
}

