#include "client.h"

void	cmd_ls(int sock, char *str)
{
	send(sock, "hello from ls", ft_strlen("hello from ls"), 0);
	printf("LS\n");
}

void	cmd_cd(int sock, char *str)
{
	printf("CD\n");
}

void	cmd_get(int sock, char *str)
{
	printf("GET\n");
}

void	cmd_put(int sock, char *str)
{
	printf("PUT\n");
}

void	cmd_pwd(int sock, char *str)
{
	printf("PWD\n");
}
