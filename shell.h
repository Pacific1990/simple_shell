#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

char *get_absolute_path(char *cmd);
void free_array(char **array);
int command(void);
char **split(char *raw_cmd, char *limit);
void exec_cmd(char **cmd);
void built_in_cd(char *path);
void built_in_pwd(void);
bool is_built_in(char *cmd);
void exec_built_in(char **built_in);
void add_env_var(char *var);
void dup_env(char **envp);
char *builte_in_pwd(void);
void built_in_env(void);
void add_tail(char *var);


/**
 * struct Mon_builtin  -  list
 * @env: string
 * @exit: a string
 */
struct Mon_builtin
{
char *env;
char *exit;
};

/**
 * struct flags - list
 * @interactive: boolean
 */
struct flags
{
bool interactive;
} flags;

/**
 * struct info - list
 * @final_exit: integer
 * @ln_count: integer
 */
struct info
{
int final_exit;
int ln_count;
} info;


/**
 * struct informations - list
 * @argc: integer
 * @argv: string
 * @args: string
 * @chemin: string
 * @line_count: integer unsigned
 * @histcount: integer
 * @linecount_flag: integer
 * @environ: string
 * @env_changed: integer
 * @cmd_entree: string
 * @err_num: integer
 * @readfd: integer
 * @status: integer
 * @fname: string
 * @cmd_buf_type: integer
 */
typedef struct informations
{
int argc;
char **argv;
char *args;
char *chemin;
unsigned int line_count;
int histcount;
int linecount_flag;
char **environ;
int env_changed;
char **cmd_entree;
int err_num;
int readfd;
int status;
char *fname;
int cmd_buf_type;
} my_info;

/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

#define ENTREE 1024
#define TAILLE_ENTREE 1024
#define FLASH -1
#define CMD_NORM 0
#define LINE 0


/* builtins */
int traitrement1(char **ma_commande, char *tampon);
void prompt(void);
void bip(int b);
char **tokenize(char *line);
char *tester_chemin(char **path, char *command);
char *ajout_chemin(char *chemin, char *cmd);
int traitrement(char **ma_commande, char *entree);
void sortie(char **ma_commande, char *entree);
ssize_t my_input(my_info *info, char **entree, size_t *longueur);
void afficher_environ(void);

/* string functions */
int strcomp(char *s1, char *s2);
int strlenght(char *s);
int str_n_cmp(char *s1, char *s2, int n);
char *str_duplicate(char *s);
char *str_locate(char *s, char c);
void execute(char *ma_commande, char **entree);
char *chemin_found(void);
/* free memory */
void liberer(char **tampon);


#endif /* SHELL_H */
