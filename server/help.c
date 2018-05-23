#include "server.h"

char	*advance(char *str)
{
	while (str && *str && SED(*str))
		str++;
	return (str);
}
