#include "cub3d.h"

bool	check_spaces(int c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (true);
	return (false);
}

bool	extern_char(int c)
{
	if (check_spaces(c) || c == '1')
		return (true);
	return (false);
}

bool is_inside_row(int row, int total_row)
{
	if (row > 0 && row < total_row - 1)
		return (true);
	return (false);
}

bool is_inside_col(int col, int len)
{
	if (col > 0 && col < len - 1)
		return (true);
	return (false);
}

bool	is_player(int c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}
