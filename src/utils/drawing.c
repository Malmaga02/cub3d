/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:16:01 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/20 10:58:32 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	create_trgb(char *data, int offset)
{
	unsigned char	t;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (!data)
		return (-1);
	if (data && !data[offset])
		r = 0;
	else
		r = data[offset];
	g = data[offset + 1];
	b = data[offset + 2];
	t = data[offset + 3];
	return ((t << 24) | (b << 16) | (g << 8) | (r));
}

bool	draw_pixel(t_all *pAll, int x, int y, int color)
{
	t_img	*image;
	int		idx;

	idx = 0;
	if (x < 0 || x >= pAll->window.frame->width
		|| y < 0 || y >= pAll->window.frame->height)
		return (false);
	image = pAll->window.frame;
	idx = (y * image->size_line + x * (image->bpp / 8));
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
	int		i;
	t_point	start;
	t_point	end;

	i = 0;
	start = (t_point){.x = col, .y = 0};
	end = (t_point){.x = col, .y = pAll->algo.draw_start - 1};
	draw_rectangle(pAll, start, end, pAll->texture.ceiling);
	start.y = pAll->algo.draw_start;
	end.y = pAll->algo.draw_end;
	check_orientation(pAll, start, end);
	start.y = pAll->algo.draw_end + 1;
	end.y = SCREEN_H - 1;
	draw_rectangle(pAll, start, end, pAll->texture.floor);
}
