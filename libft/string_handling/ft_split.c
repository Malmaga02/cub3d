/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:55:20 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:15 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countw(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word++;
		i++;
	}
	return (word);
}

static char	**ft_freeato(char **fin, int x)
{
	while (x >= 0)
	{
		free(fin[x]);
		x--;
	}
	free(fin);
	return (NULL);
}

static char	*ft_strnew(const char *s, int i, char c)
{
	unsigned int	st;
	int				len;

	st = (unsigned int)i;
	while (s[i] && s[i] != c)
		i++;
	len = i - st;
	return (ft_substr(s, st, len));
}

static char	**ft_copia(char **fin, const char *s, char c)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (i < ft_strlen(s))
	{
		while (s && s[i] == c)
			i++;
		while (s && s[i] && s[i] != c)
		{
			if (i == 0 || s[i - 1] == c)
			{
				fin[x] = ft_strnew(s, i, c);
				if (!fin[x])
					return (ft_freeato(fin, x));
				x++;
			}
			i++;
		}
	}
	fin[x] = NULL;
	return (fin);
}

char	**ft_split(char const *s, char c)
{
	char	**fin;

	if (!s)
		return (NULL);
	fin = (char **)malloc(sizeof(char *) * (ft_countw(s, c) + 1));
	if (!fin)
		return (NULL);
	return (ft_copia(fin, s, c));
}

/* 
int main()
{
	int i = 0;
	char **fin = ft_split("Ciao", ' ');
	
	while (fin[i])
	{
		printf("[%d] %s\n", i, fin[i]);
		i++;
	}
	if (!fin)
		printf("non c'e");
	ft_freeato(fin, i);
	return (0);
} */
