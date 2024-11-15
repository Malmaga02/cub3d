/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:32:08 by brulutaj          #+#    #+#             */
/*   Updated: 2024/11/15 19:45:11 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_player_position(t_all *cubed, double new_x, double new_y)
{
	cubed->player.pos.x = new_x;
	cubed->player.pos.y = new_y;
}

bool	is_new_position_valid(t_all *cubed, double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)new_x;
	map_y = (int)new_y;
	return (cubed->map.map[map_y][map_x] != '1');
}

void	get_new_position(t_all *cubed, double *new_x, double *new_y)
{
	double	current_x;
	double	current_y;

	current_x = cubed->player.pos.x;
	current_y = cubed->player.pos.y;
	if (cubed->event.walk_forw)
	{
		*new_x = current_x + cubed->player.dir.x * PLAYER_SPEED;
		*new_y = current_y + cubed->player.dir.y * PLAYER_SPEED;
	}
	else if (cubed->event.walk_back)
	{
		*new_x = current_x - cubed->player.dir.x * PLAYER_SPEED;
		*new_y = current_y - cubed->player.dir.y * PLAYER_SPEED;
	}
	else if (cubed->event.walk_left)
	{
		*new_x = current_x - cubed->player.dir.y * PLAYER_SPEED;
		*new_y = current_y + cubed->player.dir.x * PLAYER_SPEED;
	}
	else if (cubed->event.walk_right)
	{
		*new_x = current_x + cubed->player.dir.y * PLAYER_SPEED;
		*new_y = current_y - cubed->player.dir.x * PLAYER_SPEED;
	}
}

int	move_player(t_all *cubed)
{
	double	new_x;
	double	new_y;
	int		map_x;
	int		map_y;

	new_x = 0.0;
	new_y = 0.0;
	map_x = 0;
	map_y = 0;
	get_new_position(cubed, &new_x, &new_y);
	if (is_new_position_valid(cubed, new_x, new_y))
		update_player_position(cubed, new_x, new_y);
	rotate_player(cubed);
	return (0);
}
