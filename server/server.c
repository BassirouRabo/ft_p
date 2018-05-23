#include "server.h"

int		main(int argc, char **argv)
{
	int					server_fd;
	int					client_fd;
	struct sockaddr_in	client;
	unsigned int		client_len;
	int					data_len;
	char				data[MAX_DATA];
	int					fd;
	int					len;
	char				buf[MAX_DATA];

	argc--;
	argv++;
	if (argc != 1)
		print_usage(argv[-1]);
	if ((server_fd = create_server(ft_atoi(argv[0]))) == ERROR)
		exit(ERROR);
	while ((client_fd = accept(server_fd, (struct sockaddr *)&client, &client_len)) > ERROR)
	{
		printf("NEW CLIENT CONNECTED port[%d] ip[%s]\n", ntohs(client.sin_port), inet_ntoa(client.sin_addr));
		send(client_fd, "You are connected!\n", 19, 0);
		while ((data_len = recv(client_fd, data, MAX_DATA - 1, 0)) > 0)
		{
			data[data_len] = '\0';
			if (IS_NOT_CMD(atoi(data)))
			{
				printf("ERROR server\n");
				exit(-1);
			}
			parse(client_fd, ft_atoi(data));
		}
		printf("CLIENT DISCONNECTED!\n");
		close(client_fd);
	}
	close(server_fd);
	if (client_fd == ERROR)
		exit(ERROR);
	return (0);
}

/*
 fd = open("file_server.txt", O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 0644);
		if (fd == ERROR)
		{
			printf("fd %d\n", fd);
			perror("open server");
			exit(ERROR);
		}
		while ((data_len = recv(client_fd, data, MAX_DATA, 0)) > 0)
		{
			data[data_len] = '\0';
			printf("SENT data [%d] : %s\n", data_len, data);
			write(fd, data, data_len);
			//send(client_fd, data, data_len, 0);
			//printf("SENT data : %s\n", data);
		}
		close(fd);
		if (data_len == ERROR)
			exit(ERROR);
 */