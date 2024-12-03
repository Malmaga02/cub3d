/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:05:40 by chsassi           #+#    #+#             */
/*   Updated: 2024/12/03 15:05:12 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_mtx(char **mtx)
{
	int	i;

	if (!mtx)
		return ;
	i = 0;
	while (mtx && mtx[i])
	{
		free(mtx[i]);
		mtx[i] = NULL;
		i++;
	}
	free(mtx);
}

char	**mtx_alloc(int rows, int cols)
{
	int		i;
	char	**mtx;

	i = 0;
	mtx = ft_calloc(rows, sizeof(char *));
	if (!mtx)
		ft_putstr_fd("Error during row allocation.\n", 2);
	while (i < rows)
	{
		mtx[i] = ft_calloc(cols, sizeof(char));
		if (!mtx[i])
			ft_putstr_fd("Error during col allocation.\n", 2);
		i++;
	}
	return (mtx);
}

char	**copy_mtx(char **mtx)
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
			return (free_mtx(mtx_cpy), NULL);
		i++;
	}
	return (mtx_cpy);
}
