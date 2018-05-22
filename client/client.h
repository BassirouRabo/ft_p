#ifndef CLIENT_H
# define CLIENT_H

#include "../header.h"

/*
** print.c
*/
void	print_help(void);
void	print_usage(char *str);
void	print_error(char *str);

/*
** client.c
*/

/*
** setting.c
*/
int		create_client(char *addr, int port);
int		parse(int sock, char *str);

/*
** cmd.c
*/
void	cmd_ls(int sock, char *str);
void	cmd_cd(int sock, char *str);
void	cmd_get(int sock, char *str);
void	cmd_put(int sock, char *str);
void	cmd_pwd(int sock, char *str);

/*
** help.c
*/
char	*advance(char *str);

#endif
