/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:23:49 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:15 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*t;
	char			*fin;
	unsigned char	c1;

	c1 = (unsigned char)c;
	t = (char *)s;
	i = ft_strlen(t);
	while (i >= 0)
	{
		if (t[i] == c1)
		{
			fin = &t[i];
			return (fin);
		}
		i--;
	}
	return (NULL);
}
/* int main()
{
	char *src = "abbbbbbbb";
 	char *d1 = strrchr(src, 'a');
 	char *d2 = ft_strrchr(src, 'a');
	printf("%s and %s", d1, d2);
	return (0);
} */
