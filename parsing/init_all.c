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

bool	get_texture_and_colors(char *name_file, t_all *pAll) //aggiungere colori
{
	t_element	info_elements;

	info_elements = get_elements(name_file);
	if (!info_elements.north)
		return (false);
	// if (!load_wall_textures(info_elements, pAll))
	// 	return (free_element(&info_elements), false);
	if (!get_rgb_colors(info_elements, pAll))
		return (free_element(&info_elements), false);
	return (free_element(&info_elements), true);
}

bool	get_map_info(char *map_file, t_all *pAll)
{
	char	**map;

	map = get_map(map_file);
	if (!map || !is_map_playable(map))
		return (error(ERROR_MAP), false);
	pAll->map.map = map;
	pAll->map.rows = count_rows(pAll->map.map);
	return (true);
}

void	get_player_info(t_map *map, t_all *all_info)
{
	int			row;
	int			col;

	row = 0;
	col = 0;
	while (map->map && map->map[row])
	{
		col = 0;
		while (map->map[row] && map->map[row][col])
		{
			if (is_player(map->map[row][col]))
			{
				set_info_player(col, row, map->map[row][col], all_info);
				map->map[row][col] = '0';
			}
			col++;
		}
		row++;
	}
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

bool	init_all(t_all *pAll, char *name_file)
{
	if (!get_texture_and_colors(name_file, pAll))
		return (false);
	if (!get_map_info(name_file, pAll))
		return (false);
	get_player_info(&pAll->map, pAll);
	return (true);
}
