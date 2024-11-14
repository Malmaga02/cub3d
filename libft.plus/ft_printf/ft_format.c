/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:17:49 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:58:14 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_format(char c, va_list arg, int *fin)
{
	if (c == '%')
		*fin += write(1, "%", 1);
	else if (c == 'c')
		ft_printf_putchar(va_arg(arg, int), fin);
	else if (c == 's')
		ft_printf_putstr(va_arg(arg, char *), fin);
	else if (c == 'p')
		ft_printf_putmemory(va_arg(arg, unsigned long long), fin, 0);
	else if (c == 'd' || c == 'i')
		ft_printf_putnbr(va_arg(arg, int), fin);
	else if (c == 'x' || c == 'X')
		ft_printf_puthex(c, va_arg(arg, unsigned long), fin);
	else if (c == 'u')
		ft_printf_putnbr_b(va_arg(arg, unsigned int), fin);
}
