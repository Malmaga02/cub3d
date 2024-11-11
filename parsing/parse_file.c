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

t_all	*parse_file(char *name_file)
{
	t_all	*all_info;

	all_info = ft_calloc(1, sizeof(t_all));
	if (!all_info)
		return (error(MALLOC_E), NULL);
	all_info->info_elements = get_elements(name_file);
	if (!all_info->info_elements.texture_nord)
		return (NULL);
	all_info->map = get_t_map(name_file);
	if (!all_info->map.map)
		return (NULL);
	return (all_info);
}
