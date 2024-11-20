/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:30:16 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/11 17:30:18 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_all	all_info;

	all_info = (t_all){0};
	ft_bzero(&all_info, sizeof(t_all));
	if (ac != 2 || (av && !av[1]))
		return (error(ARG_ERROR), 0);
	if (!init_all(&all_info, av[1]))
		return (1);
	start_game(&all_info, av[1]);
	return (0);
}
