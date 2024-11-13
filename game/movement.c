/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:20:33 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/12 18:13:00 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rotate_player(t_all *mlx, int i)
{
	if (i == 0)
	{
		mlx->player->angle -= ROTATION_SPEED;
		if (mlx->player->angle < 0)
			mlx->player->angle += 2 * M_PI;
	}
	else
	{
		mlx->player->angle += ROTATION_SPEED;
		if (mlx->player->angle > 2 * M_PI)
			mlx->player->angle -= 2 * M_PI;
	}
	return (0);
}

