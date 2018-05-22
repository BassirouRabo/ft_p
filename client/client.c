#include "../header.h"

void	usage(char *str)
{
	printf("Usage: %s <address> <port>\n", str);
	exit(ERROR);
}

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

int		main(int argc, char **argv)
{
	int		sock;

	argc--;
	argv++;
	if (argc != 2)
		usage(argv[-1]);
	sock = create_client(argv[0], ft_atoi(argv[1]));
	write(sock, "Hello world!\n", 12);
	close(sock);
	return (0);
}
