/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:23:28 by mgalmari          #+#    #+#             */
/*   Updated: 2024/11/13 16:09:18 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_player	get_player_info(t_map *map)
{
	int			row;
	int			col;
	t_player	player;

	row = 0;
	col = 0;
	player = (t_player){0};
	while (map->map && map->map[row])
	{
		col = 0;
		while (map->map[row] && map->map[row][col])
		{
			if (is_player(map->map[row][col]))
			{
				player = set_info_player(col, row, map->map[row][col], player);
				map->map[row][col] = '0';
			}
			col++;
		}
		row++;
	}
	return (player);
}

t_map	get_map_info(char *map_file)
{
	t_map	map;

	map = (t_map){0};
	map.map = get_map(map_file);
	if (!map.map || !is_map_playable(map.map))
		return (error(ERROR_MAP), (t_map){0});
	map.rows = count_rows(map.map);
	return (map);
}

t_all	*init_all(t_all *all_info, char *name_file)
{
	all_info->info_elements = get_elements(name_file);
	if (!all_info->info_elements.texture_nord)
		return (NULL);
	all_info->map = get_map_info(name_file);
	if (!all_info->map.map)
		return (NULL);
	all_info->player = get_player_info(&all_info->map);
	return (all_info);
}
