#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include <stdio.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <arpa/inet.h>
# include <stdlib.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define ERROR -1
# define MAX_CLIENTS 2
# define MAX_DATA 256
# define END(x) (x == '\t' || x == '\n' || x == ' ')

#endif
