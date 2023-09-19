#include "shell.h"

/**
 *traitrement1- verifier les traitrements
 *@ma_commande: ma_commande
 *@tampon: mon_tampon
 *Return: 1 ou 0
 */

int traitrement1(char **ma_commande, char *tampon)
{
	if (traitrement(ma_commande, tampon))
		return (1);
	else if (**ma_commande == '/')
	{
		execute(ma_commande[0], ma_commande);
		return (1);
	}
	return (0);
}
