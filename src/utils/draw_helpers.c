/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:33:32 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/20 15:33:35 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_orientation(t_all *pAll, t_point start, t_point end)
{
	if (pAll->algo.side_collision == 0)
	{
		if (pAll->algo.ray_dir_x >= 0)
			render_wall_texture(pAll, start, end, pAll->texture.west);
		else
			render_wall_texture(pAll, start, end, pAll->texture.east);
	}
	else
	{
		if (pAll->algo.ray_dir_y >= 0)
			render_wall_texture(pAll, start, end, pAll->texture.south);
		else
			render_wall_texture(pAll, start, end, pAll->texture.north);
	}
}

void	determine_x_coord(t_all *pAll, t_img *texture)
{
	if (pAll->algo.side_collision == 0)
	{
		if (pAll->algo.ray_dir_x >= 0)
			pAll->texture.tex_x = (int)
				(pAll->algo.hit_point.y * texture->width) % texture->width;
		else
			pAll->texture.tex_x = (int)
				(1 - pAll->algo.hit_point.y * texture->width) % texture->width;
	}
	else
	{
		if (pAll->algo.ray_dir_y >= 0)
			pAll->texture.tex_x = (int)
				(pAll->algo.hit_point.x * texture->width) % texture->width;
		else
			pAll->texture.tex_x = (int)
				(1 - pAll->algo.hit_point.x * texture->width) % texture->width;
	}
}

t_img	*load_texture(void *mlx, char *file_path)
{
	t_img	*texture;
	int		width;
	int		height;

	texture = mlx_xpm_file_to_image(mlx, file_path, &width, &height);
	if (!texture)
	{
		ft_printf("Error loading texture: %s\n", file_path);
		return (NULL);
	}
	texture->width = width;
	texture->height = height;
	return (texture);
}

void	render_weapon(t_all *pAll, int weapon_x, int weapon_y)
{
	int	height;
	int	width;
	int	offset;
	int	color;

	height = 0;
	while (height < pAll->window.weapon->height)
	{
		width = 0;
		while (width < pAll->window.weapon->width)
		{
			offset = (height * pAll->window.weapon->size_line)
				+ width * (pAll->window.weapon->bpp / 8);
			color = create_trgb(pAll->window.weapon->data, offset);
			if (pAll->window.weapon->data[offset + 3] != -1)
				draw_pixel(pAll, width + weapon_x, height + weapon_y, color);
			width++;
		}
		height++;
	}
}

void	draw_legend(t_all *pAll)
{
	char	*move;
	char	*lshift;
	char	*minimap;
	char	*esc;

	move = "WASD: Move";
	lshift = "Left Shift: Run";
	minimap = "M: Toggle Minimap";
	esc = "ESC: Quit Game";
	if (pAll->event.show_legend == false)
		return ;
	mlx_string_put(pAll->window.mlx, pAll->window.mlx_win, 970, 15,
		WHITE, move);
	mlx_string_put(pAll->window.mlx, pAll->window.mlx_win, 970, 30,
		WHITE, lshift);
	mlx_string_put(pAll->window.mlx, pAll->window.mlx_win, 970, 45,
		WHITE, minimap);
	mlx_string_put(pAll->window.mlx, pAll->window.mlx_win, 970, 60,
		WHITE, esc);
}
