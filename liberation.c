#include "shell.h"

/**
* liberer - liberer le tampon
* @tampon: tampon
* Return: vide
*/

void liberer(char **tampon)
{
	int k = 0;

	if (!tampon || tampon == NULL)
		return;
	while (tampon[k])
	{
		free(tampon[k]);
		k++;
	}
	free(tampon);
}

