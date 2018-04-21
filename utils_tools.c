#include "fillit.h"
#include <stdlib.h>

void	ft_exit_error(void)
{
	ft_putstr(MSG_ERROR);
	exit(0);
}

void	ft_exit_clean(void)
{
	ft_putstr(MSG_ERROR);
	exit(0);
}

void	ft_exit_usage(void)
{
	ft_putstr(MSG_USAGE);
	exit(0);
}

int		tile_ishash(char c)
{
	return (c == '#') ? 1 : 0;
}

int		tile_notvalid(char c)
{
	return (c == '.' || c == '#') ? 0 : 1;
}
