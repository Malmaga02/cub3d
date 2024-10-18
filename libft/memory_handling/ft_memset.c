/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:01:18 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:14 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*t;

	i = 0;
	t = (char *)s;
	while (i < n)
	{
		t[i] = c;
		i++;
	}
	return (s);
}

/*int main()
{	
	char *s;
	int	c = 5;
	size_t n = 5;
	int i = 0;
	s = (char *)malloc(n + 1);
	if (!s)
		return (0);
	ft_memset(s, c, n);
	while (i < n)
	{
		printf("%d", s[i]);
		i++;
	}
	free(s);
	return(0);

}*/
