/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:14:16 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:15 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_mtxdup(char **mtx)
{
	int		i;
	char	**mtx_cpy;

	i = 0;
	if (!mtx)
		return (NULL);
	mtx_cpy = ft_calloc((count_rows(mtx) + 1), sizeof(char *));
	if (!mtx_cpy)
		return (NULL);
	while (mtx[i])
	{
		mtx_cpy[i] = ft_strdup(mtx[i]);
		if (!mtx_cpy[i])
			return (free_mtx(mtx_cpy, i), NULL);
		i++;
	}
	return (mtx_cpy);
}
