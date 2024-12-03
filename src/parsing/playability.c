/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playability.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:23:28 by mgalmari          #+#    #+#             */
/*   Updated: 2024/11/22 16:40:33 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_player_inside_map(char **map, int row, int col)
{
	if (is_player(map[row][col]) && is_surrounded(map, row, col))
		return (true);
	return (false);
}

bool	correct_char_set(char **map)
{
	int		row;
	int		col;
	bool	player;

	row = 0;
	col = 0;
	player = false;
	while (map && map[row])
	{
		col = 0;
		while (map[row] && map[row][col])
		{
			if (is_player_inside_map(map, row, col) && player == false)
				player = true;
			else if (is_player(map[row][col]) && player == true)
				return (error(MULTIPLE_PLAYER), false);
			if (!is_char_set(map[row][col]))
				return (error(INCORRECT_CHAR), false);
			col++;
		}
		row++;
	}
	if (player == 0)
		return (error(NO_PLAYER), false);
	return (true);
}

bool	is_surrounded(char **map, int row, int col)
{
	int	total_rows;
	int	len;

	total_rows = count_rows(map);
	len = ft_strlen(map[row]);
	if (!exists(map, row - 1, col) || !exists(map, row + 1, col)
		|| !exists(map, row, col - 1) || !exists(map, row, col + 1))
		return (false);
	if ((exists(map, row - 1, col) && check_spaces(map[row - 1][col]))
		|| (exists(map, row + 1, col) && check_spaces(map[row + 1][col]))
		|| (exists(map, row, col - 1) && check_spaces(map[row][col - 1]))
		|| (exists(map, row, col + 1) && check_spaces(map[row][col + 1])))
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
		if (!extern_char(map[row][col]) || !extern_char(map[row][len - 2]))
			return (error(OPEN_MAP), false);
		while (map[row] && map[row][col])
		{
			if (map[row][col] == '0' && !is_surrounded(map, row, col))
				return (error(OPEN_MAP), false);
			col++;
		}
		row++;
	}
	return (true);
}

bool	is_map_playable(char **map)
{
	int	rows;

	rows = count_rows(map);
	if (!is_external_row(map[0]) || !is_external_row(map[rows - 1]))
		return (free_mtx(map), error(NOT_PLAYABLE), false);
	if (!closed_map(map))
		return (free_mtx(map), error(NOT_PLAYABLE), false);
	if (!correct_char_set(map))
		return (free_mtx(map), error(NOT_PLAYABLE), false);
	return (true);
}
