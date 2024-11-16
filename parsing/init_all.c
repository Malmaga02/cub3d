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

void	init_algo(t_all *pAll)
{
	pAll->algo.ray_dir_x = 0;
	pAll->algo.ray_dir_y = 0;
	pAll->algo.side_dist_x = 0;
	pAll->algo.side_dist_y = 0;
	pAll->algo.delta_dist_x = 0;
	pAll->algo.delta_dist_y = 0;
	pAll->algo.perp_wall_dist = 0;
	pAll->algo.camera_x = 0;
	pAll->algo.step_x = 0;
	pAll->algo.step_y = 0;
	pAll->algo.map_x = pAll->player.pos.x;
	pAll->algo.map_y = pAll->player.pos.y;
	pAll->algo.collision = false;
	pAll->algo.side_collision = false;
	pAll->algo.width = SCREEN_W;
	pAll->algo.height = SCREEN_H;
	pAll->algo.line_height = 0;
	pAll->algo.draw_end = 0;
	pAll->algo.draw_start = 0;
}

bool	init_all(t_all *all_info, char *name_file)
{
	all_info->info_elements = get_elements(name_file);
	if (!all_info->info_elements.texture_north)
		return (false);
	all_info->map = get_map_info(name_file);
	if (!all_info->map.map)
		return (false);
	all_info->player = get_player_info(&all_info->map);
	return (true);
}
