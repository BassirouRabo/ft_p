#include "../header.h"

void	usage(char *str)
{
	printf("Usage: %s <port>\n", str);
	exit(ERROR);
}

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

int		main(int argc, char **argv)
{
	int				server_fd;
	int				client_fd;
	struct sockaddr_in	client;
	unsigned int	client_len;
	int		data_len;
	char	data[MAX_DATA];

	argc--;
	argv++;
	if (argc != 1)
		usage(argv[-1]);
	if ((server_fd = create_server(ft_atoi(argv[0]))) == ERROR)
		exit(ERROR);
	while ((client_fd = accept(server_fd, (struct sockaddr *)&client, &client_len)) > ERROR)
	{
		printf("NEW CLIENT port [%d] IP [%s]\n", ntohs(client.sin_port), inet_ntoa(client.sin_addr));
		while ((data_len = recv(client_fd, data, MAX_DATA, 0)) > 0)
		{
			send(client_fd, data, data_len, 0);
			data[data_len] = '\0';
			printf("SENT data : %s\n", data);
		}
		if (data_len == ERROR)
			exit(ERROR);
		printf("CLIENT DISCONNECTED!\n");
		close(client_fd);
	}
	close(server_fd);
	if (client_fd == ERROR)
		exit(ERROR);
	return (0);
}
