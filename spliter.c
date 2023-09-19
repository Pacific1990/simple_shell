#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
* split - split function
* @raw_cmd: command
* @limit: limiy
*
* Return: string
*/

char **split(char *raw_cmd, char *limit)
{
	char *ptr = NULL;
	char **cmd = NULL;
	size_t idx = 0;

	ptr = strtok(raw_cmd, limit);

	while (ptr)
	{
		cmd = (char **)realloc(cmd, ((idx + 1) * sizeof(char *)));
		cmd[idx] = strdup(ptr);
		ptr = strtok(NULL, limit);
		++idx;
	}
	cmd = (char **)realloc(cmd, ((idx + 1) * sizeof(char *)));
	cmd[idx] = NULL;
	return (cmd);
}

/**
* free_array - liberer letableau
* @array: string
*
* Return: void
*/

void free_array(char **array)
{
	int i;
	for (i = 0; array[i]; i++) {
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
}

