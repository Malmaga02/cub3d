/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:23:28 by mgalmari          #+#    #+#             */
/*   Updated: 2024/11/11 17:23:31 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map get_player_info(t_map map)
{
	int row;
	int col;

	row = 0;
	col = 0;
	while (map.map && map.map[row])
	{
		col = 0;
		while (map.map[row] && map.map[row][col])
		{
			if (is_player(map.map[row][col]))
			{
				map.pov_player = map.map[row][col];
				map.pos_playerX = col;
				map.pos_playerY = row;
				map.map[row][col] = '0';
			}
			col++;
		}
		row++;
	}
	return (map);
}
