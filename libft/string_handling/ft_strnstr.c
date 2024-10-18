/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:40:12 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:15 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	little_len = ft_strlen(little);
	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && len > 0)
	{
		if (ft_strncmp(&big[i], little, little_len) == 0 && len >= little_len)
			return ((char *)&big[i]);
		i++;
		len--;
	}
	return (NULL);
}
/* 
int main()
{
	char s1[] = "see FF your FF return FF now FF";
 	char s2[] = "FF";
 	size_t max = strlen(s1);
	printf("%s\n", ft_strnstr(s1, s2, 15));
	return (0);
}  */
