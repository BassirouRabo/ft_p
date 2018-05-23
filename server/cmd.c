#include "server.h"

void	cmd_ls(int sock)
{
	printf("RECIEVE SERVER LS\n");
	send(sock, "ok\n", 2, 0);
}

void	cmd_cd(int sock)
{
	printf("RECIEVE SERVER CD\n");
}

void	cmd_get(int sock)
{
	printf("RECIEVE SERVER GET\n");
}

void	cmd_put(int client_fd)
{
	char	data[MAX_DATA];
	int		len;
	int		fd;

	len = recv(client_fd, data, (MAX_DATA - 1), 0);
	data[len] = '\0';
	printf("file[%s]\n", data);
	if ((fd = open(data, O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 0644)) == ERROR)
	{
		perror("open file server:");
		return ;
	}
	printf("START FROM CLIEND PUT\n");
	while ((len = recv(client_fd, data, 1, 0)) > 0)
	{
		write(fd, data, 1);
		printf("[%c] [%d]\n", data[0], len);
	}
	printf("RECIEVED FROM CLIEND PUT\n");
}

void	cmd_pwd(int sock)
{
	printf("RECIEVE SERVER PWD\n");
}
