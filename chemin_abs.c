#include "shell.h"

/**
 * get_absolute_path - function
 *
 * @cmd: commande arg
 * Return: void
 */

char *get_absolute_path(char *cmd)
{
char *path, *path_2, *token, *file;
int cmd_length, directory_length;
struct stat buffer;
path = getenv("PATH");

if (path)
{
path_2 = strdup(path);
cmd_length = strlen(cmd);
token = strtok(path_2, ":");
while (token != NULL)
{
directory_length = strlen(token);
file = malloc(cmd_length + directory_length + 2);
strcpy(file, token);
strcat(file, "/");
strcat(file, cmd);
strcat(file, "\0");
if (stat(file, &buffer) == 0)
{
free(path_2);
return (file);
}
else
{
free(file);
token = strtok(NULL, ":");
}
}
free(path_2);
if (stat(cmd, &buffer) == 0)
{
return (cmd);
}
return (NULL);
}
return (NULL);
}
