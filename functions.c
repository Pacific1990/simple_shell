#include "shell.h"

/**
* _putchar - writes  character
* @c: character
* Return: 1
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* print_string - prints a string
* @s: string
*
* Return: number of characters
*/

int print_string(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
	return (i);
}


