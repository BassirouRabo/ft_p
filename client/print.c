#include "client.h"

void	print_help(void)
{
	printf("*** CMD ***\n");
	printf("help\n");
	printf("ls\n");
	printf("cd\n");
	printf("get _file_\n");
	printf("put _file_\n");
	printf("pwd\n");
	printf("quit\n");
}

void	print_usage(char *str)
{
	printf("Usage: %s <address> <port>\n", str);
	exit(ERROR);
}

void	print_error(char *str)
{
	printf("ERROR : %s\n", str);
}
