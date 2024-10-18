/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:58:36 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:14 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*t;
	char	*t1;

	i = 0;
	if (!dest && !src)
		return (NULL);
	t = (char *)dest;
	t1 = (char *)src;
	while (i < n)
	{
		t[i] = t1[i];
		i++;
	}
	return (dest);
}

/*int main()
{
    size_t i = 0;
    size_t n = 5;
    char *dest;
    char *src;

    dest = (char *)malloc(n + 1);
    src = (char *)malloc(n + 1);
    strcpy(dest, "ciao");
    strcpy(src, "");
    printf("%s", (char *)ft_memcpy(dest, src, n));
    free(src);
    free(dest);
    return(0);

}*/
