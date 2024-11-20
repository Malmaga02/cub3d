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
			index = find_start(texture[index], flag);
			len -= index;
			info = ft_substr(texture[row], index, len);
			if (!info)
				return (free_mtx(texture), error(MALLOC_E), NULL);
			return (free_mtx(texture), info);
		}
		row++;
	}
	return (NULL);
}

char	*get_info_element(char *name_file, char *flag)
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
	close(fd);
	free(content);
	if (!texture)
		return (ft_lstclear(&texture, free), error(MISSING_EL), NULL);
	return (get_path_texture(lst_to_mtx(texture), flag));
}

t_element	get_elements(char *name_file)
{
	t_element	info_elements;

	info_elements = (t_element){0};
	info_elements.north = get_info_element(name_file, "NO ");
	if (!info_elements.north)
		return (free_element(&info_elements), (t_element){0});
	info_elements.south = get_info_element(name_file, "SO ");
	if (!info_elements.south)
		return (free_element(&info_elements), (t_element){0});
	info_elements.east = get_info_element(name_file, "EA ");
	if (!info_elements.east)
		return (free_element(&info_elements), (t_element){0});
	info_elements.west = get_info_element(name_file, "WE ");
	if (!info_elements.west)
		return (free_element(&info_elements), (t_element){0});
	info_elements.floor = get_info_element(name_file, "F ");
	if (!info_elements.floor)
		return (free_element(&info_elements), (t_element){0});
	info_elements.ceiling = get_info_element(name_file, "C ");
	if (!info_elements.ceiling)
		return (free_element(&info_elements), (t_element){0});
	return (info_elements);
}
