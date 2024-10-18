/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:11:42 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:14 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*t;
	char	*fin;
	size_t	i;
	size_t	s_len;

	i = 0;
	t = (char *)s;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	fin = (char *)malloc(len + 1);
	if (!fin)
		return (NULL);
	while (len-- > 0 && t[start])
	{
		fin[i] = t[start];
		i++;
		start++;
	}
	fin[i] = '\0';
	return (fin);
}

/* int main()
{
    char	str[] = "lorem ipsum dolor sit amet";
	printf("%s", ft_substr(str, 400, 20));
    return (0);
} */
