/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:12:52 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/12 18:13:00 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	on_key_press(int key, t_all *pAll)
{
	if (key == XK_Escape)
	{
		ft_printf("GAME CLOSED SUCCESSFULLY");
		quit_game(pAll);
	}
	if (key == XK_w)
		pAll->event.walk_forw = true;
	if (key == XK_a)
		pAll->event.walk_left = true;
	if (key == XK_s)
		pAll->event.walk_back = true;
	if (key == XK_d)
		pAll->event.walk_right = true;
	if (key == XK_Left)
		pAll->event.rotate_left = true;
	if (key == XK_Right)
		pAll->event.rotate_right = true;
	if (key == XK_l)
		pAll->event.show_legend = true;
	if (key == XK_Shift_L)
		pAll->player.velox_mult = 2;
	return (0);
}

int	on_key_release(int key, t_all *pAll)
{
	if (key == XK_w)
		pAll->event.walk_forw = false;
	if (key == XK_a)
		pAll->event.walk_left = false;
	if (key == XK_s)
		pAll->event.walk_back = false;
	if (key == XK_d)
		pAll->event.walk_right = false;
	if (key == XK_Left)
		pAll->event.rotate_left = false;
	if (key == XK_Right)
		pAll->event.rotate_right = false;
	if (key == XK_m)
		pAll->event.show_minimap = !pAll->event.show_minimap;
	if (key == XK_l)
		pAll->event.show_legend = !pAll->event.show_legend;
	if (key == XK_Shift_L)
		pAll->player.velox_mult = 1;
	return (0);
}
