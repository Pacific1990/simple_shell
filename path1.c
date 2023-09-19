#include "shell.h"

/**
* tester_chemin - tester le chemin
* @chemin: chemin
* @entree: entree
*
* Return: string
*/

char *tester_chemin(char **chemin, char *entree)
{
	int i = 0;
	char *entree_user;

	while (chemin[i])
	{
		entree_user = ajout_chemin(chemin[i], entree);
		if (access(entree_user, F_OK | X_OK) == 0)
			return (entree_user);
		free(entree_user);
		i++;
	}
	
	return (NULL);
}
