/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:03:53 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/15 17:03:54 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda(t_all *pAll, t_algo algo, int map_x, int map_y)
{
	while (!algo.collision)
	{
		if (algo.side_dist_x < algo.side_dist_y)
		{
			algo.side_dist_x += algo.delta_dist_x;
			map_x += algo.step_x;
			algo.side_collision = false;
		}
		else
		{
			algo.side_dist_y += algo.delta_dist_y;
			map_y += algo.step_y;
			algo.side_collision = true;
		}
		if (pAll->map.map[map_x][map_y] == '1')
			algo.collision = true;
	}
}

//tutta la funzione della guida messa insieme
	// TODO:
	// controllare che le variabili della struct t_algo siano stati impostati bene
	// fare il refactor di perform_raycasting() in piu funzioni, come dda()
	// capire i singoli step :)

void perform_raycasting(t_all *pAll)
{
	int w = pAll->window.frame->width;
	int h = pAll->window.frame->height;

	for (int x = 0; x < w; x++)
	{
		t_algo algo;
		algo.collision = false;

		double cameraX = 2 * x / (double)w - 1;
		algo.ray_dir_x = pAll->player.dir.x + pAll->player.plane.x * cameraX;
		algo.ray_dir_y = pAll->player.dir.y + pAll->player.plane.y * cameraX;

		int map_x = (int)pAll->player.pos.x;
		int map_y = (int)pAll->player.pos.y;

		algo.delta_dist_x = fabs(1 / algo.ray_dir_x);
		algo.delta_dist_y = fabs(1 / algo.ray_dir_y);

		if (algo.ray_dir_x < 0)
		{
			algo.step_x = -1;
			algo.side_dist_x = (pAll->player.pos.x - map_x) * algo.delta_dist_x;
		}
		else
		{
			algo.step_x = 1;
			algo.side_dist_x = (map_x + 1.0 - pAll->player.pos.x) * algo.delta_dist_x;
		}

		if (algo.ray_dir_y < 0)
		{
			algo.step_y = -1;
			algo.side_dist_y = (pAll->player.pos.y - map_y) * algo.delta_dist_y;
		}
		else
		{
			algo.step_y = 1;
			algo.side_dist_y = (map_y + 1.0 - pAll->player.pos.y) * algo.delta_dist_y;
		}
		dda(pAll, algo, map_x, map_y);
		if (!algo.side_collision)
			algo.perp_wall_dist = (map_x - pAll->player.pos.x + (1 - algo.step_x) / 2) / algo.ray_dir_x;
		else
			algo.perp_wall_dist = (map_y - pAll->player.pos.y + (1 - algo.step_y) / 2) / algo.ray_dir_y;

		int lineHeight = (int)(h / algo.perp_wall_dist);

		int drawStart = -lineHeight / 2 + h / 2;
		if (drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if (drawEnd >= h) drawEnd = h - 1;

		draw_vertical_line(pAll, x, drawStart, drawEnd, color_based_on_side(algo.side_collision));
	}
}
