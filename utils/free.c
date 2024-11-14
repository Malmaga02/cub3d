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

void	free_element(t_element *pElement)
{
	if (pElement->texture_nord)
		free(pElement->texture_nord);
	if (pElement->texture_sud)
		free(pElement->texture_sud);
	if (pElement->texture_est)
		free(pElement->texture_est);
	if (pElement->texture_ovest)
		free(pElement->texture_ovest);
	if (pElement->ceiling)
		free(pElement->ceiling);
	if (pElement->floor)
		free(pElement->floor);
}

void	free_map(t_map *pMap)
{
	free_mtx(pMap->map);
	pMap->map = NULL;
	pMap->rows = 0;
}

int	quit_game(t_all *pAll)
{
	free_element(&pAll->info_elements);
	free_map(&pAll->map);
	mlx_destroy_image(pAll->window.mlx, pAll->window.frame);
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
