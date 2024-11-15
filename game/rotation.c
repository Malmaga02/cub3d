/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:20:33 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/15 19:42:43 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rot_action(t_all *cubed, int old_dirx, int old_planex, double rot)
{
	old_dirx = cubed->player.dir.x;
	cubed->player.dir.x = cubed->player.dir.x * cos(rot)
		- cubed->player.dir.y * sin(rot);
	cubed->player.dir.y = old_dirx * sin(rot)
		+ cubed->player.dir.y * cos(rot);
	old_planex = cubed->player.plane.x;
	cubed->player.plane.x = cubed->player.plane.x * cos(rot)
		- cubed->player.plane.y * sin(rot);
	cubed->player.plane.y = old_planex * sin(rot)
		+ cubed->player.plane.y * cos(rot);
	return (0);
}

int	rotate_player(t_all *cubed)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = cubed->player.dir.x;
	old_planex = cubed->player.plane.x;
	if (cubed->event.rotate_right == true)
		rot_action(cubed, old_dirx, old_planex, -ROT);
	if (cubed->event.rotate_left == true)
		rot_action(cubed, old_dirx, old_planex, ROT);
	return (0);
}
