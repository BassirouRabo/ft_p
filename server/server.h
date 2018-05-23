#ifndef SERVER_H
# define SERVER_H

# include "../header.h"

# define IS_NOT_CMD(x) (x != LS && x != CD && x != GET && x != PUT && x != PWD)

/*
** server.h
*/
void	print_usage(char *str);

/*
** setting.c
*/
int		create_server(int port);
void	parse(int sock, t_cmd cmd);

/*
** cmd.c
*/
void	cmd_ls(int sock);
void	cmd_cd(int sock);
void	cmd_get(int sock);
void	cmd_put(int sock);
void	cmd_pwd(int sock);

/*
** help.c
*/
char	*advance(char *str);

#endif
