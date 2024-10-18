/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:50:38 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:14 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*fin;
	char	*s1;

	i = 0;
	s1 = (char *)s;
	fin = (char *)malloc(ft_strlen(s) + 1);
	if (!fin)
		return (NULL);
	while (s1[i])
	{
		fin[i] = s1[i];
		i++;
	}
	fin[i] = '\0';
	return (fin);
}

/* int main()
{
	char *s = NULL;
	printf("%p, %p, %s, %s", ft_strdup(s), strdup(s), ft_strdup(s), strdup(s));
	return(0);
} */
