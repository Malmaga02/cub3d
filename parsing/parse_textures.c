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

char	**parse_textures(char *s) //gestione dei colori, da gestire
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
	// nella creazione del path alla texture aggiunto un ../textures/ nella casistica in cui non ci fosse textures nel path preso da file (non so se corretto)

// controllare come far si che vengano colorati i muri dalla texture - come si estraggono i colori?
// leak su mlx_new_image() e mlx_init() chiamati solo in start_game()

void	load_wall_textures(t_all *pAll)
{
	pAll->draw.north = load_texture(pAll->window.mlx, pAll->info_elements.north);
	if (!pAll->draw.north)
		exit(ft_putstr_fd("Error: Failed to load north wall texture\n", 2));
	pAll->draw.south = load_texture(pAll->window.mlx, pAll->info_elements.south);
	if (!pAll->draw.south)
		exit(ft_putstr_fd("Error: Failed to load south wall texture\n", 2));
	pAll->draw.east = load_texture(pAll->window.mlx, pAll->info_elements.east);
	if (!pAll->draw.east)
		exit(ft_putstr_fd("Error: Failed to load east wall texture\n", 2));
	pAll->draw.west = load_texture(pAll->window.mlx, pAll->info_elements.west);
	if (!pAll->draw.west)
		exit(ft_putstr_fd("Error: Failed to load west wall texture\n", 2));
}

