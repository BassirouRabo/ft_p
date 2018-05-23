#include "server.h"

int		create_server(int port)
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
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	if ((bind(server_fd, (struct sockaddr *)&server, sizeof(server))) == ERROR)
	{
		perror("bind");
		exit(ERROR);
	}
	if ((listen(server_fd, MAX_CLIENTS) == ERROR))
		exit(ERROR);
	return (server_fd);
}

void		parse(int sock, t_cmd cmd)
{
	if (cmd == LS)
		cmd_ls(sock);
	else if (cmd == CD)
		cmd_cd(sock);
	else if (cmd == GET)
		cmd_get(sock);
	else if (cmd == PUT)
		cmd_put(sock);
	else if (cmd == PWD)
		cmd_pwd(sock);
}
