/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_and_colors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:11:26 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/20 11:09:43 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*rgb_values(char *s)
{
	char	**color_mtx;
	int		i;
	int		*rgb_values;

	i = 0;
	color_mtx = ft_split(s, ',');
	rgb_values = ft_calloc(3, sizeof(int));
	if (!rgb_values)
		return (free_mtx(color_mtx), NULL);
	while (i < 3)
	{
		rgb_values[i] = ft_atoi(color_mtx[i]);
		if (rgb_values[i] < 0 || rgb_values[i] > 255)
			return (free(rgb_values), free_mtx(color_mtx), NULL);
		i++;
	}
	return (free_mtx(color_mtx), rgb_values);
}

int	get_rgb(int *rgb_values)
{
	return (0 << 24 | rgb_values[0] << 16 | rgb_values[1] << 8 | rgb_values[2]);
}

bool	get_rgb_colors(t_element info_element, t_all *pAll)
{
	int	*rgb_ceiling;
	int	*rgb_floor;

	rgb_ceiling = rgb_values(info_element.ceiling);
	if (!rgb_ceiling)
		return (false);
	rgb_floor = rgb_values(info_element.floor);
	if (!rgb_floor)
		return (free(rgb_ceiling), false);
	pAll->texture.ceiling = get_rgb(rgb_ceiling);
	pAll->texture.floor = get_rgb(rgb_floor);
	return (free(rgb_ceiling), free(rgb_floor), true);
}

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
