/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:43:44 by mgalmari          #+#    #+#             */
/*   Updated: 2024/12/03 15:05:12 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_putstr(char *s, int *fin)
{
	if (!s)
	{
		*fin += write(1, "(null)", 6);
		return ;
	}
	*fin += write(1, s, ft_strlen(s));
}
