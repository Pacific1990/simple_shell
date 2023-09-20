#include "shell.h"
/**
 * commencer - verification
 * @foin: string
 * @aiguille: substring
 * Return: adress of aiguille
 */
char *commencer(const char *foin, const char *aiguille)
{
	while (*aiguille)
		if (*aiguille++ != *foin++)
			return (NULL);
	return ((char *)foin);
}
