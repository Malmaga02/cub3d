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

// rappresentazione colori per R, G, B con range 0-255 per ogni coloree!!
// da stringa a matrice con numeri decimali, conversione in esadecimali, cmp con colori esistenti 
// NECESSARIO GESTIRE ERRORI E FREE !!!!!!

t_color	get_actual_colors(char *color_sequence)
{
	if (!ft_strncmp(color_sequence, "ff0000", 6))
		return (free(color_sequence), RED);
	else if (!ft_strncmp(color_sequence, "00ff00", 6))
		return (free(color_sequence), GREEN);
	else if (!ft_strncmp(color_sequence, "0000ff", 6))
		return (free(color_sequence), BLUE);
	else if (!ft_strncmp(color_sequence, "ffffff", 6))
		return (free(color_sequence), WHITE);
	else if (!ft_strncmp(color_sequence, "000000", 6))
		return (free(color_sequence), BLACK);
	else if (!ft_strncmp(color_sequence, "a9a9a9", 6))
		return (free(color_sequence), GREY);
	return (free(color_sequence), 0);
}

int	*rgb_values(char *s)
{
	char	**color_mtx;
	int		i;
	int		rgb_values[3];

	i = 0;
	color_mtx = ft_split(s, ',');
	while (i < 3)
	{
		rgb_values[i] = ft_atoi(color_mtx[i]);
		if (rgb_values[i] < 0 || rgb_values[i] > 255)
			return (free_mtx(color_mtx), NULL);
		i++;
	}
	return (free_mtx(color_mtx), rgb_values);
}

void	int_to_hex_str(char **sequence, int rgb_values, int index)
{
	int	quotient;
	int	most_significant;
	int	least_significant;

	if (index + 1 >= 6)
		return ;
	quotient = rgb_values / 16;
	least_significant = rgb_values % 16;
	most_significant = quotient % 16;
	*sequence[index] = BASE_HEX[most_significant];
	*sequence[index + 1] = BASE_HEX[least_significant];
}

char	*rgb_hex_representation(int *rgb_values)
{
	int		index;
	char	*color_sequence;

	index = 0;
	color_sequence = ft_calloc(7, sizeof(char));
	if (!color_sequence || rgb_values == NULL)
		return (free(color_sequence), NULL);
	while (index < 6)
	{
		int_to_hex_str(&color_sequence, rgb_values[index / 2], index);
		index+=2;
	}
	return (color_sequence);
}

// controllare se le info dei colori sono corretti, trovare i colori corretti e metterli in t_draw

bool	get_rgb_colors(t_element info_element, t_all *pAll)
{
	char	*rgb_ceiling;
	char	*rgb_floor;

	rgb_ceiling = rgb_hex_representation(rgb_values(info_element.ceiling));
	if (!rgb_ceiling)
		return (false);
	rgb_floor = rgb_hex_representation(rgb_values(info_element.floor));
	if (!rgb_floor)
		return (free(rgb_ceiling), false);
	pAll->texture.colors->ceiling = get_actual_colors(rgb_ceiling);
	if (pAll->texture.colors->ceiling == 0) // == 0 o ! ?
		return (false);
	pAll->texture.colors->floor = get_actual_colors(rgb_floor);
	if (!pAll->texture.colors->floor)
		return (false);
	return (true);
}

/* NEEDS REVISION */

// da controllare secondo parameteo su load_texture() e passargli il path dal file config della mappa, non dal path assoluto di dove si trova la texture
	// nella creazione del path alla texture aggiunto un ../textures/ nella casistica in cui non ci fosse textures nel path preso da file (non so se corretto)

// controllare come far si che vengano colorati i muri dalla texture - come si estraggono i colori?
// leak su mlx_new_image() e mlx_init() chiamati solo in start_game()

bool	load_wall_textures(t_element info_element, t_all *pAll)
{
	pAll->draw.north = load_texture(pAll->window.mlx, info_elements.north);
	if (!pAll->draw.north)
		return (ft_putstr_fd("Error: Failed to load north wall texture\n", 2), false); //c'è da freeare
	pAll->draw.south = load_texture(pAll->window.mlx, info_elements.south);
	if (!pAll->draw.south)
		return (ft_putstr_fd("Error: Failed to load south wall texture\n", 2), false);
	pAll->draw.east = load_texture(pAll->window.mlx, info_elements.east);
	if (!pAll->draw.east)
		return (ft_putstr_fd("Error: Failed to load east wall texture\n", 2), false);
	pAll->draw.west = load_texture(pAll->window.mlx, info_elements.west);
	if (!pAll->draw.west)
		return (ft_putstr_fd("Error: Failed to load west wall texture\n", 2), false);
}
// da norminettare e freeare in caso di fallimento load_wall_texture