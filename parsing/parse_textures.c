/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:11:26 by brulutaj          #+#    #+#             */
/*   Updated: 2024/11/12 12:11:31 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char    **parse_textures(char *s)
{
    int     i;
    char    **color_mtx;

    i = -1;
    color_mtx = ft_split(s, ',');
    while (++i < 3)
    {
        if (ft_atoi(color_mtx[i]) < 0 || ft_atoi(color_mtx[i]) > 255)
            return (free_mtx(color_mtx), NULL);
    }
    return (color_mtx);
}

// void load_textures(t_all *pAll)
// {
//     pAll->info_elements.texture_nord = load_texture(pAll->window.frame, );
//     pAll->info_elements.texture_sud = load_texture(pAll->window.frame, );
//     pAll->info_elements.texture_est = load_texture(pAll->window.frame, );
//     pAll->info_elements.texture_ovest = load_texture(pAll->window.frame, );
// }
