#include "../cubed.h"

char	*get_path_texture(char	*texture, char *flag)
{
	char	*info;
	int		index;
	int		i;

	i = 0;
	index = ft_strlen(flag);
	while (texture && check_spaces(texture[index]))
		index++;
	info = ft_calloc(ft_strlen(texture) - index, sizeof(char));
	if (!info)
		return (error(MALLOC_E), NULL);
	while (texture && texture[index])
	{
		info[i] = texture[index];
		i++;
		index++;
	}
	return (info);
}

char	**lst_to_mtx(t_list *head)
{
	char	**map;
	int		size;
	int		i;

	size = ft_lstsize(head);
	i = 0;
	map = ft_calloc(size + 1, sizeof(char *));
	if (!map)
		return (NULL);
	while (head && i < size)
	{
		map[i] = ft_strdup((char *)head->content);
		if (!map[i])
			return (free_mtx(map, i), NULL);
		i++;
		head = head->next;
	}
	map[i] = NULL;
	return (map);
}

int	not_closed_map(char **map, int row, int col)
{
	if (!map || !map[row])
		return (1);
	if ((map[row - 1] && map[row - 1][col] && !outside_walls(map[row - 1][col]))
		|| (map[row + 1] && map[row + 1][col] && !outside_walls(map[row + 1][col]))
		|| (map[row] && map[row][col - 1] && !outside_walls(map[row][col - 1]))
		|| (map[row] && map[row][col + 1] && !outside_walls(map[row][col + 1])))
		return (1);
	return (0);
}

int	spaces_in_map(char **map) //aggiungere controlli su prima e ulima riga + primi e ultim char 1
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (map && map[row])
	{
		while (map[row] && map[row][col])
		{
			if (check_spaces(map[row][col]) && not_closed_map(map, row, col))
				return (1);
			col++;
		}
		row++;
	}
	return (0);
}
