/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:14:23 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:14 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*fin;
	size_t	en;
	size_t	st;

	if (!s1 && !set)
		return (NULL);
	st = 0;
	en = ft_strlen(s1);
	while (s1[st] && ft_strchr(set, s1[st]))
		st++;
	while (en > st && ft_strchr(set, s1[en - 1]))
		en--;
	fin = (char *)malloc((en - st) + 1);
	if (!fin)
		return (NULL);
	ft_strlcpy(fin, s1 + st, en - st + 1);
	return (fin);
}

/* int main()
{
    printf("%s", ft_strtrim("   xxxtripouille", " x"));
    return (0);
} */
