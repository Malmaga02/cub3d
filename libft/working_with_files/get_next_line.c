/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:12:11 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:15 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_line(int fd, char *read_line)
{
	char	*buffer;
	int		i;

	while (ft_get_newline(read_line))
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (!buffer)
			return (NULL);
		read_line = ft_freejoin(read_line, buffer);
		if (i == 0)
			return (read_line);
	}
	return (read_line);
}

char	*ft_get_line(char *read_line, int *i)
{
	char	*line;
	int		j;

	if (!read_line || read_line[0] == '\0')
		return (NULL);
	j = ft_strlen_chr(read_line, '\n');
	if (j == ft_strlen_chr(read_line, '\0'))
		line = (char *)malloc(j + 1);
	else
		line = (char *)malloc(j + 2);
	if (!line)
		return (NULL);
	while (read_line[*i] != '\n')
	{
		line[*i] = read_line[*i];
		if (read_line[*i] == '\0')
			return (line);
		(*i)++;
	}
	line[(*i)++] = '\n';
	line[*i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*read_line[1024];
	char		*line;
	int			*index;
	int			j;

	j = 0;
	index = &j;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_line[fd] = ft_read_line(fd, read_line[fd]);
	if (!read_line[fd])
		return (NULL);
	line = ft_get_line(read_line[fd], index);
	read_line[fd] = ft_get_substr(read_line[fd], *index,
			ft_strlen_chr(read_line[fd], '\0'));
	return (line);
}

/* int main()
{
	int fd = open("./text.txt", O_RDONLY);
	char *next = get_next_line(fd);
	int i = 1;
	printf("0: %s\n", next);
	while (next != NULL)
	{
		free(next);
		next = get_next_line(fd);
		printf("%d: %s\n", i, next);
		i++;
	}
	free(next);
	return (0);
} */
