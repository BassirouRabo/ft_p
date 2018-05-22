#include "client.h"

int		main(int argc, char **argv)
{
	int		sock;
	int		fd;
	int		len;
	char	*str;
	char	data[MAX_DATA];

	argc--;
	argv++;
	if (argc != 2)
		print_usage(argv[-1]);
	sock = create_client(argv[0], ft_atoi(argv[1]));
	while ((len = read(0, data, MAX_DATA - 1)) > 0)
	{
		data[len] = '\0';
		str = data;
		while (str && *str && (*str == ' ' || *str == '\t'))
			str++;
		if (!ft_strncmp(str, "quit", 4) && END(str[4]))
			break ;
		if (!ft_strncmp(str, "help", 4) && END(str[4]))
			print_help();
		else if (ft_strlen(str) && !parse(sock, str))
			print_error(str);
	}
	close(sock);
	return (0);
}

/*
 fd = open("file_client.txt", O_RDONLY);
	while ((len = read(fd, buf, 256)) > 0)
	{
		buf[len] = '\0';
		send(sock, buf, len, 0);
		//printf("{%s}\n", buf);
	}
//close(fd);
 */