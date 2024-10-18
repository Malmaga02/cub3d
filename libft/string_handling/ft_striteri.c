/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:55:32 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:15 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*void	mod(unsigned int p, char *c)
{
	*c = *c + p;
}

int main()
{
	char s[4];
	s[0] = 'a';
	s[1] = 'a';
	s[2] = 'a';
	s[3] = '\0';
	printf("%s\n", s);
	ft_striteri(s, &mod);
	printf("%s\n", s);
	return (0);
}*/
