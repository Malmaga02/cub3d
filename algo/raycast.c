/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:03:53 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/19 18:45:36 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda(t_all *pAll)
{
	while (!pAll->algo.collision)
	{
		if (pAll->algo.side_dist_x < pAll->algo.side_dist_y)
		{
			pAll->algo.side_dist_x += pAll->algo.delta_dist_x;
			pAll->algo.map_x += pAll->algo.step_x;
			pAll->algo.side_collision = false;
		}
		else
		{
			pAll->algo.side_dist_y += pAll->algo.delta_dist_y;
			pAll->algo.map_y += pAll->algo.step_y;
			pAll->algo.side_collision = true;
		}
		if (get_map_char(pAll, pAll->algo.map_x, pAll->algo.map_y) != '0')
			pAll->algo.collision = true;
	}
}

void	calculate_ray(t_all *pAll)
{
	if (pAll->algo.ray_dir_x < 0)
	{
		pAll->algo.step_x = -1;
		pAll->algo.side_dist_x = (pAll->player.pos.x - pAll->algo.map_x) * pAll->algo.delta_dist_x;
	}
	else
	{
		pAll->algo.step_x = 1;
		pAll->algo.side_dist_x = (pAll->algo.map_x + 1.0 - pAll->player.pos.x) * pAll->algo.delta_dist_x;
	}
	if (pAll->algo.ray_dir_y < 0)
	{
		pAll->algo.step_y = -1;
		pAll->algo.side_dist_y = (pAll->player.pos.y - pAll->algo.map_y) * pAll->algo.delta_dist_y;
	}
	else
	{
		pAll->algo.step_y = 1;
		pAll->algo.side_dist_y = (pAll->algo.map_y + 1.0 - pAll->player.pos.y) * pAll->algo.delta_dist_y;
	}
}

void	check_perp_distance(t_all *pAll)
{
	if (!pAll->algo.side_collision)
		pAll->algo.perp_wall_dist = (pAll->algo.map_x - pAll->player.pos.x + (1 - pAll->algo.step_x) / 2) / pAll->algo.ray_dir_x;
	else
		pAll->algo.perp_wall_dist = (pAll->algo.map_y - pAll->player.pos.y + (1 - pAll->algo.step_y) / 2) / pAll->algo.ray_dir_y;
}

void	calculate_hit_point(t_all *pAll)
{
	pAll->algo.hit_point = (t_point){.x = pAll->player.pos.x + (pAll->algo.perp_wall_dist * pAll->player.dir.x),
	.y = pAll->player.pos.y - pAll->algo.perp_wall_dist * pAll->player.dir.y};
}

void	set_info_line(t_all *pAll, int col)
{
	pAll->algo.line_height = pAll->algo.height / pAll->algo.perp_wall_dist;
	pAll->algo.draw_start = -(pAll->algo.line_height) / 2 + pAll->algo.height / 2;
	if(pAll->algo.draw_start < 0)
		pAll->algo.draw_start = 0;
	pAll->algo.draw_end = pAll->algo.line_height / 2 + pAll->algo.height / 2;
	if(pAll->algo.draw_end >= pAll->algo.height)
		pAll->algo.draw_end = pAll->algo.height - 1;
	draw_line(pAll, col);
}

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
		pAll->algo.ray_dir_x = pAll->player.dir.x + pAll->player.plane.x * pAll->algo.camera_x;
		pAll->algo.ray_dir_y = pAll->player.dir.y + pAll->player.plane.y * pAll->algo.camera_x;
		pAll->algo.delta_dist_x = fabs(1 / pAll->algo.ray_dir_x);
		pAll->algo.delta_dist_y = fabs(1 / pAll->algo.ray_dir_y);
		if (pAll->algo.ray_dir_x == 0)
			pAll->algo.delta_dist_x = INT_MAX;
		if (pAll->algo.ray_dir_y == 0)
			pAll->algo.delta_dist_y = INT_MAX;
		calculate_ray(pAll);
		dda(pAll);
		check_perp_distance(pAll);
		if (col == SCREEN_W / 2)
			printf("%f, %f\n", pAll->player.dir.x, pAll->player.dir.y);
		calculate_hit_point(pAll);
		set_info_line(pAll, col);
	}
}
