#include "client.h"

int		create_client(char *addr, int port)
{
	int					server_fd;
	struct protoent *	proto;
	struct sockaddr_in	server;

	if (!(proto = getprotobyname("tcp")))
	{
		perror("proto");
		exit(ERROR);
	}
	if ((server_fd = socket(PF_INET, SOCK_STREAM, 0)) == ERROR)
	{
		perror("socket");
		exit(ERROR);
	}
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = inet_addr(addr);
	//bzero(&sin.sin_zero, 8);
	if ((connect(server_fd, (struct sockaddr *)&server, sizeof(server))) == ERROR)
	{
		perror("connect");
		exit(ERROR);
	}
	return (server_fd);
}

int		parse(int sock, char *str)
{
	if (!ft_strncmp(str, "ls", 2) && END(str[2]))
		cmd_ls(sock, advance(str + 2));
	else if (!ft_strncmp(str, "cd", 2) && END(str[2]))
		cmd_cd(sock, advance(str + 2));
	else if (!ft_strncmp(str, "get", 3) && END(str[3]))
		cmd_get(sock, advance(str + 3));
	else if (!ft_strncmp(str, "put", 3) && END(str[3]))
		cmd_put(sock, advance(str + 3));
	else if (!ft_strncmp(str, "pwd", 3) && END(str[3]))
		cmd_pwd(sock, advance(str + 3));
	else
		return (0);
	return (1);
}
