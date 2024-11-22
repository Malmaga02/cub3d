/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_and_colors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:11:26 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/22 16:40:33 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	load_wall_textures(t_element info_elements, t_all *pAll)
{
	pAll->texture.north = load_texture(pAll->window.mlx, info_elements.north);
	if (!pAll->texture.north)
		return (ft_putstr_fd("Failed to load north wall texture\n", 2), false);
	pAll->texture.south = load_texture(pAll->window.mlx, info_elements.south);
	if (!pAll->texture.south)
		return (ft_putstr_fd("Failed to load south wall texture\n", 2), false);
	pAll->texture.east = load_texture(pAll->window.mlx, info_elements.east);
	if (!pAll->texture.east)
		return (ft_putstr_fd("Failed to load east wall texture\n", 2), false);
	pAll->texture.west = load_texture(pAll->window.mlx, info_elements.west);
	if (!pAll->texture.west)
		return (ft_putstr_fd("Failed to load west wall texture\n", 2), false);
	return (true);
}

void	render_wall_texture(t_all *pAll, t_point start,
	t_point end, t_img *texture)
{
	int		rows;
	double	step;
	int		color;
	int		idx;

	determine_x_coord(pAll, texture);
	step = (double)texture->height / pAll->algo.line_height;
	pAll->texture.tex_pos = (start.y - SCREEN_H / 2
			+ pAll->algo.line_height / 2) * step;
	rows = start.y;
	while (rows < end.y)
	{
		pAll->texture.tex_y = (int)pAll->texture.tex_pos % texture->height;
		pAll->texture.tex_pos += step;
		idx = (abs(pAll->texture.tex_y) * texture->size_line)
			+ (abs(pAll->texture.tex_x) * (texture->bpp / 8));
		color = create_trgb(texture->data, idx);
		if (color != -1)
			draw_pixel(pAll, start.x, rows, color);
		rows++;
	}
}
