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

void	complete_gnl(int fd)
{
	char	*content;

	content = gnl(fd);
	while (content)
	{
		free(content);
		content = gnl(fd);
	}
	free(content);
}

int	find_start(char *texture, char *flag)
{
	int	index;

	index = ft_strlen(flag);
	while (texture && check_spaces(texture[index]))
		index++;
	return (index);
}

char	*get_path_texture(char	**texture, char *flag)
{
	char	*info;
	int		row;
	int		index;
	int		len;

	row = 0;
	len = 0;
	index = 0;
	info = NULL;
	while (texture && texture[row])
	{
		len = ft_strlen(texture[row]) - 1;
		if (!ft_strncmp(texture[row], flag, ft_strlen(flag)))
		{
			index = find_start(texture[row], flag);
			len -= index;
			info = ft_substr(texture[row], index, len);
			if (!info)
				return (free_mtx(texture), error(MALLOC_E), NULL);
			return (info);
		}
		row++;
	}
	return (free_mtx(texture), NULL);
}

char	**get_mtx_elements(char *name_file)
{
	t_list	*texture;
	t_list	*node;
	char	*content;
	int		fd;

	texture = NULL;
	node = NULL;
	fd = open(name_file, O_RDONLY);
	if (fd == -1)
		return (close(fd), error(OPEN_E), NULL);
	content = gnl(fd);
	while (content && !is_external_row(content))
	{
		node = ft_lstnew((void *)ft_strdup(content));
		if (!node)
			return (ft_lstclear(&texture, free),
				close(fd), free(content), NULL);
		ft_lstadd_back(&texture, node);
		free(content);
		content = gnl(fd);
	}
	complete_gnl(fd);
	if (!texture)
		return (free(content), ft_lstclear(&texture, free), error(MISSING_EL), NULL);
	return (free(content), lst_to_mtx(texture));
}

t_element	get_elements(char *name_file, t_element info_elements)
{
	char		**textures;

	textures = get_mtx_elements(name_file);
	if (!textures)
		return (info_elements);
	info_elements.north = get_path_texture(textures, "NO ");
	if (!info_elements.north)
		return (free_element(&info_elements), (t_element){0});
	info_elements.south = get_path_texture(textures, "SO ");
	if (!info_elements.south)
		return (free_element(&info_elements), (t_element){0});
	info_elements.east = get_path_texture(textures, "EA ");
	if (!info_elements.east)
		return (free_element(&info_elements), (t_element){0});
	info_elements.west = get_path_texture(textures, "WE ");
	if (!info_elements.west)
		return (free_element(&info_elements), (t_element){0});
	info_elements.floor = get_path_texture(textures, "F ");
	if (!info_elements.floor)
		return (free_element(&info_elements), (t_element){0});
	info_elements.ceiling = get_path_texture(textures, "C ");
	if (!info_elements.ceiling)
		return (free_element(&info_elements), (t_element){0});
	return (free_mtx(textures), info_elements);
}
