#include "shell.h"

/**
* traitrement - traitrement des entrées
* @ma_commande: un tableau de commandes
* @entree: l'entrée
*
* Return: 0
*/

int traitrement(char **ma_commande, char *entree)
{
	struct Mon_builtin builtin = {"env", "exit"};

	if (strcomp(*ma_commande, builtin.env) == 0)
	{
		afficher_environ();
		return (1);
	}
	else if (strcomp(*ma_commande, builtin.exit) == 0)
	{
		sortie(ma_commande, entree);
		return (1);
	}
	
	return (0);
}
