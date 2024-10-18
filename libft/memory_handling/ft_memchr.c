/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:28:40 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:14 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t;
	size_t			i;
	unsigned char	c1;		

	i = 0;
	c1 = (unsigned char)c;
	t = (unsigned char *)s;
	while (i < n)
	{
		if (t[i] == c1)
			return (t + i);
		i++;
	}
	return (NULL);
}

/*int main()
{
	char *s;
	int c = 134;
	size_t n = 5;

	s = (char *)malloc(n + 1);
	if (!s)
		return (0);
	strcpy(s, "ciaooo");
	printf("%s", (char *)ft_memchr(s, c, n));
	return (0);
}*/
