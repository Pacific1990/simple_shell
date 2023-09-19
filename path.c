#include "shell.h"

/**
 * chemin_found - path
 * Return: character
 */

char *chemin_found(void)
{
	int x;
	char **envment = environ, *chemin = NULL;

	while (*envment)
	{
		if (str_n_cmp(*envment, "PATH=", 5) == 0)
		{
			chemin = *envment;
			while (*chemin && x < 5)
			{
				chemin++;
				x++;
			}
			return (chemin);
		}
		
		envment++;
	}
	
	return (NULL);
}

<
