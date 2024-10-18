/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:43:20 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:14 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_putnbr(int nbr, int *fin)
{
	char	c;

	if (nbr == -2147483648)
	{
		*fin += write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		*fin += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_printf_putnbr(nbr / 10, fin);
	c = (nbr % 10) + 48;
	*fin += write(1, &c, 1);
}
