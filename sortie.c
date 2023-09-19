#include "shell.h"

/**
* sortie - sortir de l'invite de commande
* @ma_commande: command
* @entree: entree
*
* Return: rien
*/

void sortie(char **ma_commande, char *entree)
{
	free(entree);
	liberer(ma_commande);
	exit(0);
}

