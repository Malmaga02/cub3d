/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_substr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:47:06 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:14 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_substr(char *read_line, int index, int len)
{
	char	*fin;
	int		i;

	i = 0;
	if (!read_line)
		return (NULL);
	if (read_line[index] == '\0')
	{
		free(read_line);
		return (NULL);
	}
	fin = (char *)malloc(len + 1);
	if (!fin)
	{
		free(read_line);
		return (NULL);
	}
	while (read_line && read_line[index + i] && i < len)
	{
		fin[i] = read_line[index + i];
		i++;
	}
	fin[i] = '\0';
	free(read_line);
	return (fin);
}
