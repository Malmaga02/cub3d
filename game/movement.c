/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:20:33 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/14 16:10:28 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rotate_player(t_all *cubed)
{
	double	old_dirx;
	double	old_planex;

	if (cubed->event.rotate_right)
	{
		old_dirx = cubed->player.dir.x;
		cubed->player.dir.x = cubed->player.dir.x * cos(-ROT) - cubed->player.dir.y * sin(-ROT);
		cubed->player.dir.y = old_dirx * sin(-ROT) + cubed->player.dir.y * cos(-ROT);
    	old_planex = cubed->player.plane.x;
    	cubed->player.plane.x = cubed->player.plane.x * cos(-ROT) - cubed->player.plane.y * sin(-ROT);
    	cubed->player.plane.y = old_planex * sin(-ROT) + cubed->player.plane.y * cos(-ROT);
    }
    if (cubed->event.rotate_left)
    {
    	old_dirx = cubed->player.dir.x;
    	cubed->player.dir.x = cubed->player.dir.x * cos(ROT) - cubed->player.dir.y * sin(ROT);
    	cubed->player.dir.y = cubed->player.dir.x * sin(ROT) + cubed->player.dir.y * cos(ROT);
    	old_planex = cubed->player.plane.x;
    	cubed->player.plane.x = cubed->player.plane.x * cos(ROT) - cubed->player.plane.y * sin(ROT);
    	cubed->player.plane.y = old_planex * sin(ROT) + cubed->player.plane.y * cos(ROT);
    }
}

