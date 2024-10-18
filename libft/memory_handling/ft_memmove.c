/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:12:17 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:14 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*t;
	char	*t1;

	if (!dest && !src)
		return (NULL);
	t = (char *)src;
	t1 = (char *)dest;
	if (t < t1 && t < t1 + n)
	{
		while (n > 0)
		{
			t1[n - 1] = t[n - 1];
			n--;
		}
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}
/* int main()
{
	
	printf("my is %s, your is %s", memmove(NULL, NULL, 3));
	return(0);
} */
