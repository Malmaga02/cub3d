/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:32:08 by brulutaj          #+#    #+#             */
/*   Updated: 2024/11/22 16:40:33 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_new_x_valid(t_all *cubed, double new_x)
{
	int	current_map_y;

	current_map_y = (int)cubed->player.pos.y;
	return (get_map_char(cubed, (int)new_x, current_map_y) != '1');
}

bool	is_new_y_valid(t_all *cubed, double new_y)
{
	int	current_map_x;

	current_map_x = (int)cubed->player.pos.x;
	return (get_map_char(cubed, current_map_x, (int)new_y) != '1');
}

void	calc_forward_backward_move(t_all *cubed, double *dx, double *dy)
{
	if (cubed->event.walk_forw)
	{
		*dx += cubed->player.dir.x * cubed->player.velox
			* cubed->player.velox_mult;
		*dy += cubed->player.dir.y * cubed->player.velox
			* cubed->player.velox_mult;
	}
	if (cubed->event.walk_back)
	{
		*dx -= cubed->player.dir.x
			* (cubed->player.velox * cubed->player.velox_mult);
		*dy -= cubed->player.dir.y
			* (cubed->player.velox * cubed->player.velox_mult);
	}
}

void	calc_lateral_move(t_all *cubed, double *dx, double *dy)
{
	if (cubed->event.walk_left)
	{
		*dx -= cubed->player.dir.y * cubed->player.velox
			* cubed->player.velox_mult;
		*dy += cubed->player.dir.x * cubed->player.velox
			* cubed->player.velox_mult;
	}
	if (cubed->event.walk_right)
	{
		*dx += cubed->player.dir.y * cubed->player.velox
			* cubed->player.velox_mult;
		*dy -= cubed->player.dir.x * cubed->player.velox
			* cubed->player.velox_mult;
	}
}

void	get_new_position(t_all *cubed, double *new_x, double *new_y)
{
	double	current_x;
	double	current_y;
	double	dx;
	double	dy;

	dx = 0.0;
	dy = 0.0;
	current_x = cubed->player.pos.x;
	current_y = cubed->player.pos.y;
	calc_forward_backward_move(cubed, &dx, &dy);
	calc_lateral_move(cubed, &dx, &dy);
	*new_x = current_x + dx;
	*new_y = current_y + dy;
}
