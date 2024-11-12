/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:04:11 by chsassi           #+#    #+#             */
/*   Updated: 2024/02/10 15:56:10 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// da implementare con le nostre struct, stessa logica

/* void	free_map(t_container *pContainer)
{
	free_mtx(pContainer->map.map);
	exit (0);
}

void	free_position(t_container *pContainer)
{
	free_mtx(pContainer->map.map);
	free(pContainer->map.collectible_pos);
	free(pContainer->map.enemy_pos);
	exit (0);
}

void	free_images(t_container *pContainer)
{
	int	i;

	i = 0;
	while (i < 4)
		mlx_destroy_image(pContainer->mlx, pContainer->player[i++]);
	mlx_destroy_image(pContainer->mlx, pContainer->floor);
	mlx_destroy_image(pContainer->mlx, pContainer->wall);
	mlx_destroy_image(pContainer->mlx, pContainer->exit);
	mlx_destroy_image(pContainer->mlx, pContainer->collectible);
	mlx_destroy_image(pContainer->mlx, pContainer->enemy);
	mlx_destroy_image(pContainer->mlx, pContainer->pixel_reset);
} */

int	quit_game(t_all *pAll)
{
	// free di tutte le struct una volta arrivati a fine gioco e/o errore
	mlx_destroy_window(pAll->window.mlx, pAll->window.mlx_win);
	mlx_destroy_display(pAll->window.mlx);
	exit(0);
	return 0;
}

int	close_window(int keycode, t_all *pAll)
{
	if (keycode == XK_Escape)
	{
		ft_printf("GAME CLOSED SUCCESSFULLY");
		quit_game(pAll);
	}
	return (1);
}
