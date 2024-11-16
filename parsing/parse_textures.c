/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:11:26 by chsassi           #+#    #+#             */
/*   Updated: 2024/11/12 12:11:31 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**parse_textures(char *s)
{
	char	**color_mtx;
	int		i;

	color_mtx = ft_split(s, ',');
	i = -1;
	while (++i < 3)
	{
		if (ft_atoi(color_mtx[i]) < 0 || ft_atoi(color_mtx[i]) > 255)
			return (free_mtx(color_mtx), NULL);
	}
	return (color_mtx);
}

/* NEEDS REVISION */

// da controllare secondo parameteo su load_texture() e passargli il path dal file config della mappa, non dal path assoluto di dove si trova la texture
// controllare come far si che vengano colorati i muri dalla texture - come si estraggono i colori?
// leak su mlx_new_image() e mlx_init() chiamati solo in start_game()

void	load_wall_textures(t_all *pAll)
{
	pAll->info_elements.texture_nord = load_texture(pAll->window.mlx, ".");
	if (!pAll->info_elements.texture_nord)
		exit(ft_printf("Error: Failed to load north wall texture\n"));
	pAll->info_elements.texture_sud = load_texture(pAll->window.mlx, ".");
	if (!pAll->info_elements.texture_sud)
		exit(ft_printf("Error: Failed to load south wall texture\n"));
	pAll->info_elements.texture_est = load_texture(pAll->window.mlx, ".");
	if (!pAll->info_elements.texture_est)
		exit(ft_printf("Error: Failed to load east wall texture\n"));
	pAll->info_elements.texture_ovest = load_texture(pAll->window.mlx, ".");
	if (!pAll->info_elements.texture_ovest)
		exit(ft_printf("Error: Failed to load west wall texture\n"));
}

