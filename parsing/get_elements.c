/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:23:28 by mgalmari          #+#    #+#             */
/*   Updated: 2024/11/13 16:09:18 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//aggiunto "../textures/"

char	*get_color(char *texture, char *flag)
{
	char	*info;
	int		index;
	int		i;

	i = 0;
	info = NULL;
	index = ft_strlen(flag);
	while (texture && check_spaces(texture[index]))
		index++;
	info = ft_strdup(texture + index);
	if (!info)
		return (error(MALLOC_E), NULL);
	return (free(texture), info);
}

char	*get_path_texture(char	*texture, char *flag)
{
	char	*info;
	int		index;
	int		i;

	i = 0;
	info = NULL;
	index = ft_strlen(flag);
	while (texture && check_spaces(texture[index]))
		index++;
	if (!ft_strnstr(texture, "textures", (size_t)ft_strlen(texture)))
	{
		info = ft_strdup("../textures/");
		index+=2; //per escludere il possibile ./
	}
	info = strjoin_gnl(info, texture + index);
	if (!info)
		return (error(MALLOC_E), NULL);
	return (free(texture), info);
}

char	*get_info_element(char *name_file, char *flag)
{
	char	*texture;
	int		fd;

	fd = open(name_file, O_RDONLY);
	if (fd == -1)
		return (close(fd), error(OPEN_E), NULL);
	texture = gnl(fd);
	while (texture && ft_strncmp(texture, flag, ft_strlen(flag)))
	{
		free(texture);
		texture = gnl(fd);
	}
	close(fd);
	if (!texture || (texture && !texture[0]))
		return (free(texture), error(MISSING_EL), NULL);
	if (!(flag == "F " || flag == "C "))
		return (get_path_texture(texture, flag));
	return (get_color(texture, flag));
}

t_element	get_elements(char *name_file)
{
	t_element	info_elements;

	info_elements = (t_element){0};
	info_elements.texture_north = get_info_element(name_file, "NO ");
	if (!info_elements.texture_north)
		return (free_element(info_elements), (t_element){0});
	info_elements.texture_south = get_info_element(name_file, "SO ");
	if (!info_elements.texture_south)
		return (free_element(info_elements), (t_element){0});
	info_elements.texture_east = get_info_element(name_file, "EA ");
	if (!info_elements.texture_east)
		return (free_element(info_elements), (t_element){0});
	info_elements.texture_west = get_info_element(name_file, "WE ");
	if (!info_elements.texture_west)
		return (free_element(info_elements), (t_element){0});
	info_elements.floor = get_info_element(name_file, "F ");
	if (!info_elements.floor)
		return (free_element(info_elements), (t_element){0});
	info_elements.ceiling = get_info_element(name_file, "C ");
	if (!info_elements.ceiling)
		return (free_element(info_elements), (t_element){0});
	return (info_elements);
}
