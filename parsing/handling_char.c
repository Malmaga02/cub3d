#include "cubed.h"

int	check_spaces(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	outside_walls(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '1')
		return (1);
	return (0);
}

int	empty_line(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (!check_spaces(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_external_row(char *str)
{
	int	i;

	i = 0;
	if (empty_line(str))
		return (0);
	while (str && str[i])
	{
		if (!(str[i] == '1' || check_spaces(str[i])))
			return (0);
		i++;
	}
	return (1);
}

int	check_not_allowed_char(char **mtx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mtx && mtx[i])
	{
		while (mtx[i] && mtx[i][j])
		{
			if (!(mtx[i][j] == '0' || mtx[i][j] == '1' || mtx[i][j] == 'N'
				|| mtx[i][j] == 'S' || mtx[i][j] == 'E' || mtx[i][j] == 'W'
				|| mtx[i][j] == '\t' || mtx[i][j] == ' '))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}