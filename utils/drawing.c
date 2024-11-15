/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:16:01 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/15 13:16:03 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(char *data, int offset)
{
	int t;
	int r;
	int g;
	int b;

	t = data[offset];
	r = data[offset + 1];
	g = data[offset + 2];
	b = data[offset + 3];
	return (b << 24 | g << 16 | r << 8 | t);
}


t_img	*load_texture(void *mlx, char *file_path)
{
	t_img	*texture;
	int		width;
	int		height;

	texture = NULL;
	texture = mlx_xpm_file_to_image(mlx, file_path, &width, &height);
	if (!texture)
		return (ft_printf("Error loading texture"), free(texture), NULL);
	return (texture);
}

void	render_weapon(t_all *pAll)
{
	int weapon_x = (pAll->window.frame->width / 2) - (pAll->window.weapon->width / 2);
	int weapon_y = pAll->window.frame->height - pAll->window.weapon->height;
	int height;
	int width;
	int	offset;
	int	color;

	height = 0;
	// height = pAll->window.frame->height - pAll->window.weapon->height;
	while (height < pAll->window.weapon->height)
	{
		width = 0;
		// width = (pAll->window.frame->width / 2) - (pAll->window.weapon->width / 2);
		while (width < pAll->window.weapon->width)
		{
			offset = height * pAll->window.weapon->size_line + width * (pAll->window.weapon->bpp / 8);
			color = create_trgb(pAll->window.weapon->data, offset);
			if (pAll->window.weapon->data[offset + 3] != -1)
				draw_pixel(pAll, width + weapon_x, height + weapon_y, color);
			width++;
		}
		height++;
	}
	// mlx_put_image_to_window(pAll->window.mlx, pAll->window.mlx_win, pAll->window.weapon, weapon_x, weapon_y);
}

void	draw_pixel(t_all *pAll, int x, int y, int color)
{
	t_img	*image;

	image = pAll->window.frame;
	int idx = (y * image->size_line + x * (image->bpp / 8));
	image->data[idx + 0] = (color) & 0xFF;
	image->data[idx + 1] = (color >> 8) & 0xFF;
	image->data[idx + 2] = (color >> 16) & 0xFF;
	image->data[idx + 3] = (color >> 24);
}

void	draw_rectangle(t_all *pAll, t_point start, t_point end, int color)
{
	int	rows;
	int	cols;

	rows = start.y;
	while (rows < end.y)
	{
		cols = start.x;
		while (cols < end.x)
		{
			draw_pixel(pAll, cols, rows, color);
			cols++;
		}
		rows++;
	}
}
