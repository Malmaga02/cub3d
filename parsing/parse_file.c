#include "../cubed.h"

t_all	*parse_file(char *name_file)
{
	t_all	*all_info;

	all_info = ft_calloc(1, sizeof(t_all));
	if (!all_info)
		return (error(MALLOC_E), NULL);
	all_info->info_elements = get_elements(name_file);
	if (!all_info->info_elements)
		return (NULL);
	all_info->map = get_t_map(name_file);
	if (!all_info->map)
		return (NULL);
	return (all_info);
}