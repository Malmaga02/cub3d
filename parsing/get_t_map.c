#include "../cubed.h"

t_map	get_t_map(char *map_file)
{
	t_map	map;

	map = (t_map){0};
	map->map = get_map(map_file);
	if (!map->map || !is_map_playable(map->map))
		return (error(ERROR_MAP), NULL);
	map->rows = count_rows(map->map);
	map = get_player_info(map); 
	return (map);
}
// spaces_in_map da fare,
// necessita di algoritmo che mi controlla gli spazi, ovvero se ho degli spazi 
//a indice x di una matrice, devo controllare che la mappa sia comunque chiusa