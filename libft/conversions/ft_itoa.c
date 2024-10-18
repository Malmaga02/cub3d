/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:40:00 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:14 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_casilim(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	return (NULL);
}

static void	ft_putnbrx(char *s, int n, int len)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		s[i] = '-';
		n = -n;
	}
	s[len] = '\0';
	len -= 1;
	while (n > 0)
	{
		s[len] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		j;

	len = 0;
	j = n;
	if (n == -2147483648 || n == 0)
		return (ft_casilim(n));
	if (n < 0)
	{
		len += 1;
		j = -n;
	}
	while (j > 0)
	{
		j = j / 10;
		len++;
	}
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	ft_putnbrx(s, n, len);
	return (s);
}

/* int main()
{
	int n = -2147483648;
	char *str = ft_itoa(n);
	printf("result is %s", str);
	free(str);
	return (0);
} */
