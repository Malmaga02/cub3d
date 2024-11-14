/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <chsassi@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:04:24 by chsassi           #+#    #+#             */
/*   Updated: 2024/08/03 15:55:25 by chsassi          ###   ########.fr       */
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

void	render_minimap_pixel(t_all *pAll, int x, int y, char element)
{
	t_point	start;
	t_point	end;

	start = (t_point){.x = x * MINIMAP_TILE, .y = y * MINIMAP_TILE};
	end = (t_point)
	{.x = x * MINIMAP_TILE + MINIMAP_TILE,
		.y = y * MINIMAP_TILE + MINIMAP_TILE};
	if (element == '1')
		draw_rectangle(pAll, start, end, BLUE);
	if (element == '0')
		draw_rectangle(pAll, start, end, WHITE);
	if (element == 'N'
		|| element == 'S'
		|| element == 'E'
		|| element == 'W')
		draw_rectangle(pAll, start, end, RED);
}

void	draw_minimap(t_all *pAll)
{
	int		rows;
	int		cols;

	if (pAll->event.show_minimap == false)
		return ;
	rows = -1;
	while (++rows < pAll->map.rows)
	{
		cols = -1;
		while (pAll->map.map[rows][++cols])
			render_minimap_pixel(pAll, cols, rows,
				get_map_char(pAll, cols, rows));
	}
	render_minimap_pixel(pAll, pAll->player.pos.x, pAll->player.pos.y, 'N');
}
