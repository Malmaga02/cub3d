/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:03:53 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/22 16:40:33 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_all *pAll)
{
	int	col;

	col = -1;
	init_algo(pAll);
	while (++col < SCREEN_W)
	{
		pAll->algo.map_x = pAll->player.pos.x;
		pAll->algo.map_y = pAll->player.pos.y;
		pAll->algo.collision = false;
		pAll->algo.camera_x = 2 * col / (double)SCREEN_W - 1;
		pAll->algo.ray_dir_x = pAll->player.dir.x
			+ pAll->player.plane.x * pAll->algo.camera_x;
		pAll->algo.ray_dir_y = pAll->player.dir.y
			+ pAll->player.plane.y * pAll->algo.camera_x;
		pAll->algo.delta_dist_x = fabs(1 / pAll->algo.ray_dir_x);
		pAll->algo.delta_dist_y = fabs(1 / pAll->algo.ray_dir_y);
		calculate_delta_dist(pAll);
		calculate_ray(pAll);
		dda(pAll);
		calculate_perp_distance(pAll);
		calculate_hit_point(pAll);
		set_info_line(pAll, col);
	}
}
