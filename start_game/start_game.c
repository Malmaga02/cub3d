/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:23:28 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/11 17:23:31 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int counter = 0;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int idx = (y * data->line_length + x * (data->bits_per_pixel / 8));

	data->addr[idx + 0] = (color) & 0xFF;
	data->addr[idx + 1] = (color >> 8) & 0xFF;
	data->addr[idx + 2] = (color >> 16) & 0xFF;
	data->addr[idx + 3] = (color >> 24);
	/* data->addr[idx + 0] = (color >> 24);
	data->addr[idx + 1] = (color >> 16) & 0xFF;
	data->addr[idx + 2] = (color >> 8) & 0xFF;
	data->addr[idx + 3] = (color) & 0xFF; */
}

int quit_game(t_mlx *pMlx)
{
	// free di tutte le struct una volta arrivati a fine gioco e/o errore
	mlx_destroy_window(pMlx->mlx, pMlx->mlx_win);
	mlx_destroy_display(pMlx->mlx);
	exit(0);
	return 0;
}

int close_window(int keycode, t_mlx *pMlx)
{
	if (keycode == KEY_ESC)
	{
		ft_printf("GAME CLOSED SUCCESSFULLY");
		quit_game(pMlx);
	}
	return (1);
}

int render(void *arg)
{
	t_mlx *ptr = (t_mlx *)arg;
	const t_point p1 = {50, 50};
	const t_point p2 = {100, 100};
	mlx_clear_window(ptr->mlx, ptr->mlx_win);
	for (int i = 0; i < 1080; i++)
	{
		for (int j = 0; j < 720; j++)
		{
			if((i > p1.x + counter && i < p2.x + counter) && (j > p1.y + counter && j < p2.y + counter))
				my_mlx_pixel_put(&ptr->frame, i, j, 0xFFFFFF);
			else
				my_mlx_pixel_put(&ptr->frame, i, j, 0x0);
		}
	}
	mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->frame.img, 0, 0);
	counter++;
	usleep(1000);
	return 0;
}

void start_game(t_mlx *pMlx)
{
	// call a fn per inizializzazione struct
	pMlx->mlx = mlx_init();
	pMlx->mlx_win = mlx_new_window(pMlx->mlx, 1080, 720, "cub3d");
	pMlx->frame.img = mlx_new_image(pMlx->mlx, 1080, 720);
	pMlx->frame.addr = mlx_get_data_addr(pMlx->frame.img, &pMlx->frame.bits_per_pixel, &pMlx->frame.line_length,
								   &pMlx->frame.endian);
	mlx_hook(pMlx->mlx_win, KeyPress, KeyPressMask, close_window, pMlx);
	mlx_hook(pMlx->mlx_win, 17, 1L << 17, quit_game, pMlx);
	mlx_loop_hook(pMlx->mlx, render, pMlx);
	mlx_loop(pMlx->mlx);
}