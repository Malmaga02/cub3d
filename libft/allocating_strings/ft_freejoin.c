/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freejoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:38:00 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:14 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcat(char *read_line, char *buffer, char *fin)
{
	int	i;
	int	j;

	i = 0;
	while (read_line && read_line[i])
	{
		fin[i] = read_line[i];
		i++;
	}
	j = 0;
	while (buffer && buffer[j])
	{
		fin[i + j] = buffer[j];
		j++;
	}
	fin[i + j] = '\0';
}

char	*ft_freejoin(char *read_line, char *buffer)
{
	char	*fin;
	int		i;
	int		j;

	i = ft_strlen_chr(read_line, '\0');
	j = ft_strlen_chr(buffer, '\0');
	fin = (char *)malloc((i + j) + 1);
	if (!fin)
	{
		free(read_line);
		free(buffer);
		return (NULL);
	}
	ft_strcat(read_line, buffer, fin);
	free(buffer);
	free(read_line);
	return (fin);
}
