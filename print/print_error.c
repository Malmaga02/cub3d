#include "cub3d.h"

void	error(int flag)
{
	if (flag == MALLOC_E)
		ft_putstr_fd("Error on malloc.\n", 2);
	else if (flag == OPEN_E)
		ft_putstr_fd("Error on open sys call.\n", 2);
	else if (flag == MISSING_EL)
		ft_putstr_fd("Necessary element is missing.\n", 2);
	else if (flag == MISSING_MAP)
		ft_putstr_fd("The map is missing.\n", 2);
	else if (flag == ERROR_MAP)
		ft_putstr_fd("Error on the map.\n", 2);
	else if (flag == OPEN_MAP)
		ft_putstr_fd("Error: the given map is not playable.\n", 2);
}