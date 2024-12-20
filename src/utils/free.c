/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:04:11 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/22 16:40:33 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_element(t_element *pElement)
{
	if (!pElement)
		return ;
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

void	free_image(t_all *pAll)
{
	if (pAll->texture.north)
		mlx_destroy_image(pAll->window.mlx, pAll->texture.north);
	if (pAll->texture.south)
		mlx_destroy_image(pAll->window.mlx, pAll->texture.south);
	if (pAll->texture.east)
		mlx_destroy_image(pAll->window.mlx, pAll->texture.east);
	if (pAll->texture.west)
		mlx_destroy_image(pAll->window.mlx, pAll->texture.west);
	if (pAll->window.weapon)
		mlx_destroy_image(pAll->window.mlx, pAll->window.weapon);
	if (pAll->window.frame)
		mlx_destroy_image(pAll->window.mlx, pAll->window.frame);
}

void	free_map(t_map *pMap)
{
	if (!pMap)
		return ;
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
		free_image(pAll);
		mlx_destroy_display(pAll->window.mlx);
	}
	free(pAll->window.mlx);
	return (exit(0), 0);
}
