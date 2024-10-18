#include "cubed.h"

t_map	*create_map(char *map_file)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (error(MALLOC_E), NULL);
	map->map = parse_map(map_file);
	if (check_not_allowed_char(map->map) || spaces_in_map(map->map))
		return (free_mtx(map->map), free(map), error(ERROR_MAP), NULL)
	map->rows = count_rows(map->map);
}
// cosa mi manca?