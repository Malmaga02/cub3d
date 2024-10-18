#include "../cubed.h"

void	print_mtx(char **mtx)
{
	int	i;

	i = -1;
	while (mtx && mtx[i++])
		printf("[%d] %s\n", i, mtx[i]);
}