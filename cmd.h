#ifndef CMD_H_INCLUDED
#define CMD_H_INCLUDED


#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

typedef struct cmd
{
    char * cmd_initiale;				/* La chaine initiale tapee par l'utilisateur */
    char **cmd_membres;				/* a chaque case i chaine du membre i */
    unsigned int nb_cmd_membres;	/* Nombre de membres */
    char ***cmd_args;				/* cmd_args[i][j] contient le jieme mot du ieme membre */
    unsigned int *nb_args;			/* Nombre d'arguments par membres */
    char ***redirection;			/* Pour stocker le chemin vers le fichier de redirection */
    int **type_redirection;			/* Pour stocker le type de redirection */
} cmd;

typedef enum
{
    STDIN,
    STDOUT,
    STDERR
} REDIR;

typedef enum
{
    MYSHELL_CMD_OK,
    MYSHELL_FCT_EXIT
};

typedef enum
{
    APPEND=1,
    OVERWRITE=2
} OPT;

void aff_args(cmd *c);
void free_args(cmd *c);
void parse_args(cmd *c);
void parse_membres(char *chaine,cmd *ma_cmd);
void aff_membres(cmd *ma_cmd);
void free_membres(cmd *ma_cmd);
int parse_redirection(unsigned int i,cmd *c);
void free_redirection(cmd *c);
void aff_redirection(cmd c, int i);
void init(cmd *c);
void lire_cmd(cmd *c,char * ligne);
void free_elements_cmd(cmd *c);
void aff_cmd(cmd *c);

#endif // CMD_H_INCLUDED
