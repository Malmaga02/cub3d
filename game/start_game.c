/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:23:28 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/12 18:13:00 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_all *pAll)
{
	draw_minimap(pAll);
	mlx_put_image_to_window(pAll->window.mlx, pAll->window.mlx_win,
		pAll->window.frame, 0, 0);
	return (0);
}

void	start_game(t_all *pAll)
{
	pAll->window.mlx = mlx_init();
	if (!pAll->window.mlx)
		return (free_element(&pAll->info_elements), free_map(&pAll->map));
	pAll->window.mlx_win = mlx_new_window(pAll->window.mlx, 1080, 720, "cub3d");
	pAll->window.frame = mlx_new_image(pAll->window.mlx, 1080, 720);
	mlx_hook(pAll->window.mlx_win, KeyPress, KeyPressMask, on_key_press, pAll);
	mlx_hook(pAll->window.mlx_win, KeyRelease,
		KeyReleaseMask, on_key_release, pAll);
	mlx_hook(pAll->window.mlx_win, 17, 1L << 17, quit_game, pAll);
	mlx_loop_hook(pAll->window.mlx, game_loop, pAll);
	mlx_loop(pAll->window.mlx);
}
