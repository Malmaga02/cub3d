/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:35:53 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:14 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcat(char *s, char *s2, char *fin)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		fin[i] = s[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		fin[i + j] = s2[j];
		j++;
	}
	fin[i + j] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*t1;
	char	*t2;
	char	*fin;

	t1 = (char *)s1;
	t2 = (char *)s2;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	fin = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!fin)
		return (NULL);
	ft_strcat(t1, t2, fin);
	return (fin);
}

/*int main()
{
    
    char *t = ft_strjoin("ciao ", "mamma");
    printf("%s", t);
    return (0);
}*/
