#include "shell.h"

/**
 * get_absolute_path - function
 *
 * @cmd: commande arg
 * Return: void
 */

void get_absolute_path(char **cmd)
{
	char *path = strdup(getenv("PATH"));
	char *bin = NULL;
	char **path_split = NULL;
	int i;

	if (path == NULL)
		path = strdup("/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin");

	if (cmd[0][0] != '/' && strncmp(cmd[0], "./", 2) != 0)
	{
		path_split = split(path, ":");
		free(path);
		path = NULL;

		for (i = 0; path_split[i]; i++)
		{
			bin = (char *)calloc(sizeof(char), (strlen(path_split[i]) + 1 + strlen(cmd[0]) + 1));
			if (bin == NULL)
				break;

			strcat(bin, path_split[i]);
			strcat(bin, "/");
			strcat(bin, cmd[0]);

			if (access(bin, F_OK) == 0)
				break;

			free(bin);
			bin = NULL;
		}
		
		free_array(path_split);

		free(cmd[0]);
		cmd[0] = bin;
	}
	else
	{
		free(path);
		path = NULL;
	}
}

