#include "shell.h"
/**
 * eratoi - string to int
 * @str: string
 * Return: 0 or -1
 */
int eratoi(char *str)
{
	int y = 0;
	unsigned long int res = 0;

	if (*str == '+')
		str++;
	for (y = 0; str[y] != '\0'; y++)
	{
		if (str[y] >= '0' && str[y] <= '9')
		{
			res *= 10;
			res += (str[y] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}
