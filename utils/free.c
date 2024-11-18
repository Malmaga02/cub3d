/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:04:11 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/15 13:16:04 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_element(t_element *pElement)
{
	if (pElement->north)
		free(pElement->north);
	if (pElement->south)
		free(pElement->south);
	if (pElement->east)
		free(pElement->east);
	if (pElement->west)
		free(pElement->west);
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
	free_map(&pAll->map);
	if (pAll->window.mlx_win)
		mlx_destroy_window(pAll->window.mlx, pAll->window.mlx_win);
	if (pAll->window.mlx)
	{
		mlx_destroy_image(pAll->window.mlx, pAll->window.frame);
		mlx_destroy_display(pAll->window.mlx);
	}
	return (exit(0), 0);
}

