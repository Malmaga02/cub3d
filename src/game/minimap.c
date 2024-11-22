/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:04:24 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/22 16:40:33 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	get_map_char(t_all *pAll, int x, int y)
{
	if (y < 0 || y >= pAll->map.rows)
		return ('\0');
	if (x < 0 || x >= ft_strlen(pAll->map.map[y]))
		return ('\0');
	return (pAll->map.map[y][x]);
}

void	render_minimap(t_all *pAll, int x, int y, char element)
{
	t_point	start;
	t_point	end;

	start = (t_point){.x = x, .y = y};
	end = (t_point){.x = x + MINIMAP_TILE, .y = y + MINIMAP_TILE};
	if (element == '1')
		draw_rectangle(pAll, start, end, GREY);
	if (element == '0')
		draw_rectangle(pAll, start, end, WHITE);
	if (element == 'N'
		|| element == 'S'
		|| element == 'E'
		|| element == 'W')
		draw_rectangle(pAll, start, end, RED);
}

void	render_minimap_ray(t_all *pAll)
{
	int		ray;
	t_point	pixel;

	ray = -1;
	pixel = (t_point){.x = (pAll->player.pos.x * MINIMAP_TILE),
		.y = (pAll->player.pos.y * MINIMAP_TILE)};
	while (++ray < 10)
	{
		pixel.x += pAll->player.dir.x;
		pixel.y += pAll->player.dir.y;
		draw_pixel(pAll, pixel.x + MINIMAP_STROKE + MINIMAP_TILE / 2,
			pixel.y + MINIMAP_STROKE + MINIMAP_TILE / 2, BLACK);
	}
}

void	draw_minimap(t_all *pAll)
{
	int				rows;
	int				cols;

	if (pAll->event.show_minimap == false)
		return ;
	rows = -1;
	while (++rows < pAll->map.rows)
	{
		cols = -1;
		while (pAll->map.map[rows][++cols])
			render_minimap(pAll, cols * MINIMAP_TILE + MINIMAP_STROKE,
				rows * MINIMAP_TILE + MINIMAP_STROKE,
				get_map_char(pAll, cols, rows));
	}
	render_minimap(pAll, pAll->player.pos.x * MINIMAP_TILE + MINIMAP_STROKE,
		pAll->player.pos.y * MINIMAP_TILE + MINIMAP_STROKE, 'N');
	render_minimap_ray(pAll);
}
