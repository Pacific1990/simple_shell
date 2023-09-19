#include "shell.h"

/**
 * ajout_chemin - Ajouter un chemin à ma commande
 * @chemin: chemin
 * @cmd:  command
 *
 * Return: string
 */

char *ajout_chemin(char *chemin, char *cmd)
{
	size_t i = 0, j = 0;
	char *tampon;

	if (cmd == 0)
		cmd = "";

	if (chemin == 0)
		chemin = "";

	tampon = malloc(sizeof(char) * (strlenght(chemin) + strlenght(cmd) + 2));
	if (!tampon)
		return (NULL);

	while (chemin[i])
	{
		tampon[i] = chemin[i];
		i++;
	}

	if (chemin[i - 1] != '/')
	{
		tampon[i] = '/';
		i++;
	}
	while (cmd[j])
	{
		tampon[i + j] = cmd[j];
		j++;
	}
	tampon[i + j] = '\0';
	return (tampon);
}
