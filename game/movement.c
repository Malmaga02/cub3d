/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:32:08 by brulutaj          #+#    #+#             */
/*   Updated: 2024/11/15 20:52:07 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_new_x_valid(t_all *cubed, double new_x)
{
	int	map_x;
	int	current_map_y;

	current_map_y = (int)floor(cubed->player.pos.y);
	map_x = (int)floor(new_x);
	return (cubed->map.map[(int)cubed->player.pos.y][map_x] != '1');
}

bool	is_new_y_valid(t_all *cubed, double new_y)
{
    int map_y;
	int current_map_x;

	current_map_x = (int)floor(cubed->player.pos.x);
	map_y = (int)floor(new_y);
    return (cubed->map.map[map_y][(int)cubed->player.pos.x] != '1');
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
	if (is_new_x_valid(cubed, new_x))
		cubed->player.pos.x = new_x;
	if (is_new_x_valid(cubed, new_y))
		cubed->player.pos.y = new_y;
	rotate_player(cubed);
	return (0);
}
