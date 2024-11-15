/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:42:49 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:14 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write(char *base, unsigned int nbr, int *fin)
{
	unsigned long	i;

	if (nbr >= 16)
		ft_write(base, nbr / 16, fin);
	i = nbr % 16;
	*fin += write(1, &base[i], 1);
}

void	ft_printf_puthex(char c, unsigned int nbr, int *fin)
{
	if (c == 'x')
		ft_write("0123456789abcdef", nbr, fin);
	if (c == 'X')
		ft_write("0123456789ABCDEF", nbr, fin);
}
