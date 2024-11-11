#include "cub3d.h"

t_map	get_t_map(char *map_file)
{
	t_map	map;

	map = (t_map){0};
	map.map = get_map(map_file);
	if (!map.map || !is_map_playable(map.map))
		return (error(ERROR_MAP), (t_map){0});
	map.rows = count_rows(map.map);
	map = get_player_info(map); 
	return (map);
}
