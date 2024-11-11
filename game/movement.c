/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:20:33 by chsassi           #+#    #+#             */
/*   Updated: 2024/02/10 15:56:10 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// preso da so_long, una volta che abbiamo settato le varie coordinate possiamo pensare
// a come implementare questo file con le nostre struct

/* int	is_walkable(int keycode, t_container *pContainer)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		if (pContainer->map.map[pContainer->map.player_pos.y - 1]
			[pContainer->map.player_pos.x] == WALL)
			return (0);
	}
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		if (pContainer->map.map[pContainer->map.player_pos.y]
			[pContainer->map.player_pos.x - 1] == WALL)
			return (0);
	}
	if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		if (pContainer->map.map[pContainer->map.player_pos.y + 1]
			[pContainer->map.player_pos.x] == WALL)
			return (0);
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		if (pContainer->map.map[pContainer->map.player_pos.y]
			[pContainer->map.player_pos.x + 1] == WALL)
			return (0);
	}
	return (1);
}

void	parse_move_up(int keycode, t_container *pContainer)
{
	if ((keycode == KEY_W || keycode == KEY_UP)
		&& is_walkable(keycode, pContainer))
	{
		pContainer->map.map[pContainer->map.player_pos.y]
		[pContainer->map.player_pos.x] = FLOOR;
		pContainer->map.player_pos = (t_axis){pContainer->map.player_pos.x,
			pContainer->map.player_pos.y - 1};
		pContainer->map.player_direction = 1;
	}
}

void	parse_move_right(int keycode, t_container *pContainer)
{
	if ((keycode == KEY_D || keycode == KEY_RIGHT)
		&& is_walkable(keycode, pContainer))
	{
		pContainer->map.map[pContainer->map.player_pos.y]
		[pContainer->map.player_pos.x] = FLOOR;
		pContainer->map.player_pos = (t_axis){pContainer->map.player_pos.x + 1,
			pContainer->map.player_pos.y};
		pContainer->map.player_direction = 0;
	}
}

void	parse_move_down(int keycode, t_container *pContainer)
{
	if ((keycode == KEY_S || keycode == KEY_DOWN)
		&& is_walkable(keycode, pContainer))
	{
		pContainer->map.map[pContainer->map.player_pos.y]
		[pContainer->map.player_pos.x] = FLOOR;
		pContainer->map.player_pos = (t_axis){pContainer->map.player_pos.x,
			pContainer->map.player_pos.y + 1};
		pContainer->map.player_direction = 2;
	}
}

void	parse_move_left(int keycode, t_container *pContainer)
{
	if ((keycode == KEY_A || keycode == KEY_LEFT)
		&& is_walkable(keycode, pContainer))
	{
		pContainer->map.map[pContainer->map.player_pos.y]
		[pContainer->map.player_pos.x] = FLOOR;
		pContainer->map.player_pos = (t_axis){pContainer->map.player_pos.x - 1,
			pContainer->map.player_pos.y};
		pContainer->map.player_direction = 3;
	}
} */