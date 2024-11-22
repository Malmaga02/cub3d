/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:40:28 by mgalmari          #+#    #+#             */
/*   Updated: 2024/11/22 16:40:33 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_fc_value(char *str)
{
	int	i;

	i = 0;
	str = ft_strtrim(str, " ");
	if (!str || ft_strlen(str) == 0)
		return (false);
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (free(str), false);
		i++;
	}
	return (free(str), true);
}

int	*rgb_values(char *s)
{
	char	**color_mtx;
	int		i;
	int		*rgb_values;

	i = 0;
	color_mtx = ft_split(s, ',');
	if (!color_mtx || count_rows(color_mtx) != 3)
		return (free_mtx(color_mtx), NULL);
	rgb_values = ft_calloc(3, sizeof(int));
	if (!rgb_values)
		return (free_mtx(color_mtx), NULL);
	while (i < 3)
	{
		rgb_values[i] = ft_atoi(color_mtx[i]);
		if (rgb_values[i] < 0
			|| rgb_values[i] > 255
			|| check_fc_value(color_mtx[i]) == false)
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
