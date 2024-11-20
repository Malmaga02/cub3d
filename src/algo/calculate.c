/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:08:38 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/20 16:08:43 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_ray(t_all *pAll)
{
	if (pAll->algo.ray_dir_x < 0)
	{
		pAll->algo.step_x = -1;
		pAll->algo.side_dist_x = (pAll->player.pos.x - pAll->algo.map_x)
			* pAll->algo.delta_dist_x;
	}
	else
	{
		pAll->algo.step_x = 1;
		pAll->algo.side_dist_x = (pAll->algo.map_x + 1.0 - pAll->player.pos.x)
			* pAll->algo.delta_dist_x;
	}
	if (pAll->algo.ray_dir_y < 0)
	{
		pAll->algo.step_y = -1;
		pAll->algo.side_dist_y = (pAll->player.pos.y - pAll->algo.map_y)
			* pAll->algo.delta_dist_y;
	}
	else
	{
		pAll->algo.step_y = 1;
		pAll->algo.side_dist_y = (pAll->algo.map_y + 1.0 - pAll->player.pos.y)
			* pAll->algo.delta_dist_y;
	}
}

void	calculate_perp_distance(t_all *pAll)
{
	if (!pAll->algo.side_collision)
		pAll->algo.perp_wall_dist = (pAll->algo.map_x - pAll->player.pos.x
				+ (1 - pAll->algo.step_x) / 2) / pAll->algo.ray_dir_x;
	else
		pAll->algo.perp_wall_dist = (pAll->algo.map_y - pAll->player.pos.y
				+ (1 - pAll->algo.step_y) / 2) / pAll->algo.ray_dir_y;
}

void	calculate_hit_point(t_all *pAll)
{
	pAll->algo.hit_point = (t_point){.x = pAll->player.pos.x
		+ (pAll->algo.perp_wall_dist * pAll->algo.ray_dir_x),
		.y = pAll->player.pos.y
		+ pAll->algo.perp_wall_dist * pAll->algo.ray_dir_y};
}

void	calculate_delta_dist(t_all *pAll)
{
	if (pAll->algo.ray_dir_x == 0)
		pAll->algo.delta_dist_x = INT_MAX;
	if (pAll->algo.ray_dir_y == 0)
		pAll->algo.delta_dist_y = INT_MAX;
}
