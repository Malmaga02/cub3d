/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:59:21 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:15 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
{
	int		i;
	char	*t;

	i = 0;
	t = (char *)s;
	while (t[i] != '\0')
		i++;
	return (i);
}