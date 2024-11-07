#include "../cubed.h"

bool	correct_char_set(char **map) //aggiungere qui pos_player??
{
	int	i;
	int	player_found;

	i = 0;
	player_found = 0;
	while (map && *map)
	{
		while (*map && *map[i])
		{
			if (is_player(*map[i]) && player_found == 0)
					player_found = 1;
			else if (is_player(*map[i]) && player_found == 1)
				return (perror("Error: double player char found.\n"), false);
			if (!(*map[i] == '0' || *map[i] == '1' || *map[i] == 'N'
				|| *map[i] == 'S' || *map[i] == 'E' || *map[i] == 'W'
				|| *map[i] == '\t' || *map[i] == ' ' || *map[i] == '\n'))
				return (perror("Error: not allowed char found.\n"), false);
			i++;
		}
		*map++;
	}
	return (true);
}

bool	is_surrounded(char **map, int row, int col)
{
	int	total_rows;
	int	len;

	total_rows = count_rows(map);
	len = ft_strlen(map[row][col]);
	if (is_inside_row(row, total_rows) && check_spaces(map[row - 1][col])
		|| is_inside_row(row, total_rows) && check_spaces(map[row + 1][col])
		|| is_inside_col(col, len) && check_spaces(map[row][col - 1])
		|| is_inside_col(col, len) && check_spaces(map[row][col + 1]))
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
			return (perror("Error: the given map is open.\n"), false);
		while (map[row] && map[row][col])
		{
			if (map[row][col] == '0' && !is_surrounded(map, row, col))
				return (perror("Error: the given map is open.\n"), false);
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
	if (!is_external_row(map[0]) || !is_external_row(map[rows - 2]))
		return (free_mtx(map, rows), error(OPEN_MAP), false);
	if (!closed_map(map))
		return (free_mtx(map, rows), error(OPEN_MAP), false);
	if (!correct_char_set(map))
		return (free_mtx(map, rows), error(OPEN_MAP), false);
	return (true);
}