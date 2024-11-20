/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:08:38 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/20 16:08:39 by chsassi          ###   ########.fr       */
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

void	set_info_line(t_all *pAll, int col)
{
	pAll->algo.line_height = pAll->algo.height / pAll->algo.perp_wall_dist;
	pAll->algo.draw_start = -(pAll->algo.line_height) / 2
		+ pAll->algo.height / 2;
	if (pAll->algo.draw_start < 0)
		pAll->algo.draw_start = 0;
	pAll->algo.draw_end = pAll->algo.line_height / 2
		+ pAll->algo.height / 2;
	if (pAll->algo.draw_end >= pAll->algo.height)
		pAll->algo.draw_end = pAll->algo.height - 1;
	draw_line(pAll, col);
}
