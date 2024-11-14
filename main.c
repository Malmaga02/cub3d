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

int	main(int argc, char **argv)
{
	t_all	all_info;

	all_info = (t_all){0};
	ft_bzero(&all_info, sizeof(t_all));
	if (argc != 2 || (argv && !argv[1]))
		return (error(ARG_ERROR), 0);
	if (!init_all(&all_info, argv[1]))
		return (1);
	start_game(&all_info);
	return (0);
}
