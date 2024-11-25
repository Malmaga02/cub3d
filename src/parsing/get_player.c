/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:09:09 by mgalmari          #+#    #+#             */
/*   Updated: 2024/11/25 14:26:58 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_player	set_pos_angle(int x, int y, int pov, t_player player)
{
	player.pos.x = (double)x + 0.5;
	player.pos.y = (double)y + 0.5;
	if (pov == 'N')
		player.angle = 3 * (PI / 2);
	else if (pov == 'E')
		player.angle = 0;
	else if (pov == 'S')
		player.angle = PI / 2;
	else if (pov == 'W')
		player.angle = PI;
	return (player);
}

void	set_info_player(int x, int y, int pov, t_all *all_info)
{
	all_info->player = set_pos_angle(x, y, pov, all_info->player);
	all_info->player.velox = 0.09;
	all_info->player.velox_mult = 1;
	if (pov == 'N')
	{
		all_info->player.plane.x = -0.66;
		all_info->player.dir.y = -1;
	}
	else if (pov == 'E')
	{
		all_info->player.plane.y = -0.66;
		all_info->player.dir.x = 1;
	}
	else if (pov == 'S')
	{
		all_info->player.plane.x = 0.66;
		all_info->player.dir.y = 1;
	}
	else if (pov == 'W')
	{
		all_info->player.plane.y = 0.66;
		all_info->player.dir.x = -1;
	}
}
