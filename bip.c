#include "shell.h"

/**
* bip- bip function
* @b: le bip
* Return: nothing
*/

void bip(int b)
{
	(void)b;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
