/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:23:28 by mgalmari          #+#    #+#             */
/*   Updated: 2024/11/22 16:40:33 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_char_set(int c)
{
	if (!(extern_char(c) || is_player(c) || c == '0'))
		return (false);
	return (true);
}

bool	extern_char(int c)
{
	if (check_spaces(c) || c == '1')
		return (true);
	return (false);
}

bool	is_inside_col(int col, int len)
{
	if (col > 0 && col < len - 1)
		return (true);
	return (false);
}

bool	is_player(int c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

bool	exists(char **map, int row, int col)
{
	if (row < 0 || col < 0 || (map && !map[row]))
		return (false);
	if (!is_inside_col(col, ft_strlen(map[row])))
		return (false);
	if (map && !map[row][col])
		return (false);
	return (true);
}
