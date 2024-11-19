/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:23:28 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/18 16:39:55 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_player(t_all *cubed)
{
	double	new_x;
	double	new_y;

	new_x = 0.0;
	new_y = 0.0;
	get_new_position(cubed, &new_x, &new_y);
	if (new_x == 0.0)
		new_x = cubed->player.pos.x;
	if (new_y == 0.0)
		new_y = cubed->player.pos.y;
	if (is_new_x_valid(cubed, new_x))
		cubed->player.pos.x = new_x;
	if (is_new_y_valid(cubed, new_y))
		cubed->player.pos.y = new_y;
	rotate_player(cubed);
	return (0);
}

int	game_loop(t_all *pAll)
{
	raycast(pAll);
	move_player(pAll);
	// draw_rectangle(pAll, (t_point){0, 0}, (t_point){pAll->window.frame->width, pAll->window.frame->height}, BLACK);
	// mlx_put_image_to_window(pAll->window.mlx, pAll->window.mlx_win,
	// 	pAll->window.frame, 0, 0)
	render_weapon(pAll,
		(pAll->window.frame->width / 2) - (pAll->window.weapon->width / 2),
		pAll->window.frame->height - pAll->window.weapon->height);
	mlx_put_image_to_window(pAll->window.mlx, pAll->window.mlx_win,
		pAll->window.frame, 0, 0);
	draw_minimap(pAll);

	return (0);
}

int	start_game(t_all *pAll, char *name_file)
{
	pAll->window.mlx = mlx_init();
	if (!pAll->window.mlx)
		return (ft_printf("Error during creation of MLX instance"), quit_game(pAll));
	pAll->window.mlx_win = mlx_new_window(pAll->window.mlx, 1080, 720, "cub3d");
	if (!pAll->window.mlx_win)
		return (ft_printf("Error during creation of MLX window"), quit_game(pAll));
	pAll->window.frame = mlx_new_image(pAll->window.mlx, 1080, 720);
	if (!pAll->window.frame)
		return (ft_printf("Error during creation of MLX image"), quit_game(pAll));
	if (!get_texture_and_colors(name_file, pAll))
		return (ft_printf("Error during creation of textures"), quit_game(pAll));
	pAll->window.weapon = load_texture(pAll->window.mlx, "./textures/player.xpm");
	if (!pAll->window.weapon)
		return (quit_game(pAll));
	mlx_hook(pAll->window.mlx_win, KeyPress, KeyPressMask, on_key_press, pAll);
	mlx_hook(pAll->window.mlx_win, KeyRelease,
		KeyReleaseMask, on_key_release, pAll);
	mlx_hook(pAll->window.mlx_win, 17, 1L << 17, quit_game, pAll);
	mlx_loop_hook(pAll->window.mlx, game_loop, pAll);
	mlx_loop(pAll->window.mlx);
	return (0);
}
