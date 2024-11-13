/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:09:09 by mgalmari          #+#    #+#             */
/*   Updated: 2024/11/13 16:09:18 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_player	set_info_player(int x, int y, int pov, t_player player)
{
	player.pos.x = (double)x;
	player.pos.y = (double)y;
	if (pov == 'N')
	{
		player.plane.y = 0.66;
		player.dir_player.y = 1;
		player.angle = 3 * (PI / 2);
	}
	else if (pov == 'E')
	{
		player.plane.x = 0.66;
		player.dir_player.x = 1;
		player.angle = 0;
	}
	else if (pov == 'S')
	{
		player.plane.y = -0.66;
		player.dir_player.y = -1;
		player.angle = PI / 2;
	}
	else if (pov == 'W')
	{
		player.plane.x = -0.66;
		player.dir_player.x = -1;
		player.angle = PI;
	}
	return (player);
}
