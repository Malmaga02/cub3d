/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:16:01 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/19 22:12:46 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	create_trgb_text(char *data, int offset)
// {
// 	int t;
// 	int r;
// 	int g;
// 	int b;

// 	if (!data)
// 		return (-1);
// 	if (data && !data[offset])
// 		t = 0;
// 	else
// 		t = data[offset];
// 	r = data[offset + 1];
// 	g = data[offset + 2];
// 	b = data[offset + 3];
// 	return (t << 24 | r << 16 | g << 8 | b);
// }


size_t	create_trgb(char *data, int offset)
{
	// unsigned int res;
	// int			r;
	// int			g;
	// int 		b;
		
	//t = *(unsigned int *)(data + offset);
	// r = data[offset];
	// g = data[offset + 1];
	// b = data[offset + 2];
	// t = data[offset + 3];
	// res = r;
	// res = res | (g << 8);
	// res = res | (b << 16);
	// res = res | (t << 24);
	// return (t);
	unsigned char	t;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	// if (!data)
	// 	return (-1);
	// if (data && !data[offset])
	// 	t = 0;
	r = data[offset];
	g = data[offset + 1];
	b = data[offset + 2];
	t = data[offset + 3];
	return ((t << 24) | (b << 16) | (g << 8) | (r));
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
	printf("%s %d\n", file_path, width);
	texture->width = width;
	texture->height = height;
	return (texture);
}

void	render_weapon(t_all *pAll, int weapon_x, int weapon_y)
{
	int height;
	int width;
	int	offset;
	int	color;

	height = 0;
	while (height < pAll->window.weapon->height)
	{
		width = 0;
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
}

bool	draw_pixel(t_all *pAll, int x, int y, int color)
{
	t_img	*image;

	if (x < 0 || x >= pAll->window.frame->width || y < 0 || y >= pAll->window.frame->height)
		return (false);
	image = pAll->window.frame;
	int idx = (y * image->size_line + x * (image->bpp / 8));
	image->data[idx + 0] = (color) & 0xFF;
	image->data[idx + 1] = (color >> 8) & 0xFF;
	image->data[idx + 2] = (color >> 16) & 0xFF;
	image->data[idx + 3] = (color >> 24);
	return (true);
}

void	draw_rectangle(t_all *pAll, t_point start, t_point end, int color)
{
	int	rows;
	int	cols;

	rows = start.y;
	while (rows < end.y)
	{
		cols = start.x;
		while (cols <= end.x)
		{
			if (!draw_pixel(pAll, cols, rows, color))
				return ;
			cols++;
		}
		rows++;
	}
}

void	draw_line(t_all *pAll, int col)
{
	int	i;
	t_point	start;
	t_point	end;

	i = 0;
	start = (t_point){.x = col, .y = 0};
	end = (t_point){.x = col, .y = pAll->algo.draw_start - 1};
	draw_rectangle(pAll, start, end, pAll->texture.ceiling);
	start.y = pAll->algo.draw_start;
	end.y = pAll->algo.draw_end;
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
	start.y = pAll->algo.draw_end + 1;
	end.y = SCREEN_H - 1;
	draw_rectangle(pAll, start, end, pAll->texture.floor);
}
