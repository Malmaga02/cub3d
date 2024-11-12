/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:23:28 by mgalmari          #+#    #+#             */
/*   Updated: 2024/11/11 17:23:31 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_all	*parse_file(t_all *all_info, char *name_file)
{
	all_info->info_elements = get_elements(name_file);
	if (!all_info->info_elements.texture_nord)
		return (NULL);
	all_info->map = get_t_map(name_file);
	if (!all_info->map.map)
		return (NULL);
	all_info->player.pos = (t_point)
	{.x = all_info->map.pos_playerX, .y = all_info->map.pos_playerY};
	return (all_info);
}
