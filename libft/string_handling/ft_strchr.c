/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:23:19 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:15 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	char			*t;
	char			*fin;
	unsigned char	c1;

	i = 0;
	t = (char *)s;
	c1 = (unsigned char)c;
	while (t[i] != '\0')
	{
		if (t[i] == c1)
		{
			fin = &t[i];
			return (fin);
		}
		i++;
	}
	if (c1 == 0)
	{
		fin = &t[i];
		return (fin);
	}
	return (NULL);
}

/*int main()
{
	char *s = "ciao";
	int c = 0;
	printf("%p, %p", ft_strchr(s, c), strchr(s, c));
	return (0);
}*/
