#include "cub3d.h"

bool	correct_char_set(char **map) //aggiungere qui pos_player??
{
	int	i;
	int	j;
	int	player_found;

	i = 0;
	j = 0;
	player_found = 0;
	while (map && map[j])
	{
		i = 0;
		while (map[j] && map[j][i])
		{
			if (is_player(map[j][i]) && player_found == 0)
					player_found = 1;
			else if (is_player(map[j][i]) && player_found == 1)
				return (ft_putstr_fd("Error: double player char found.\n", 2), false);
			if (!(map[j][i] == '0' || map[j][i] == '1' || map[j][i] == 'N'
				|| map[j][i] == 'S' || map[j][i] == 'E' || map[j][i] == 'W'
				|| map[j][i] == '\t' || map[j][i] == ' ' || map[j][i] == '\n'))
				return (ft_putstr_fd("Error: not allowed char found.\n", 2), false);
			i++;
		}
		j++;
	}
	if (player_found == 0)
		return (ft_putstr_fd("Error: player char not found.\n", 2), false);
	return (true);
}

bool	is_surrounded(char **map, int row, int col)
{
	int	total_rows;
	int	len;

	total_rows = count_rows(map);
	len = ft_strlen(map[row]);
	if ((is_inside_row(row, total_rows) && check_spaces(map[row - 1][col]))
		|| (is_inside_row(row, total_rows) && check_spaces(map[row + 1][col]))
		|| (is_inside_col(col, len) && check_spaces(map[row][col - 1]))
		|| (is_inside_col(col, len) && check_spaces(map[row][col + 1])))
		return (false);
	return (true);
}

bool	closed_map(char **map)
{
	int	row;
	int	col;
	int	len;

	row = 0;
	col = 0;
	while (map && map[row])
	{
		col = 0;
		len = ft_strlen(map[row]);
		if (!extern_char(map[row][col]) || !extern_char(map[row][len - 1]))
			return (ft_putstr_fd("Error: the given map is open.\n", 2), false);
		while (map[row] && map[row][col])
		{
			if (map[row][col] == '0' && !is_surrounded(map, row, col))
				return (ft_putstr_fd("Error: the given map is open.\n", 2), false);
			col++;
		}
		row++;
	}
	return (true);
}

// playability --> mappa chiusa: prima e ultima row tutti 1
//		il primo e ultimo chr prima di spazi o alla fine di ogni row == 1
// --> un solo giocatore (N S E W), no char diversi da quelli concessi

bool	is_map_playable(char **map) //free qui della matrice se errore
{
	int	rows;

	rows = count_rows(map);
	if (!is_external_row(map[0]) || !is_external_row(map[rows - 1]))
		return (free_mtx(map, rows), error(OPEN_MAP), false);
	if (!closed_map(map))
		return (free_mtx(map, rows), error(OPEN_MAP), false);
	if (!correct_char_set(map))
		return (free_mtx(map, rows), error(OPEN_MAP), false);
	return (true);
}