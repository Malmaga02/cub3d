#include "cub3d.h"

int main(int argc, char **argv)
{
	t_mlx mlx;
	// t_all *all_info;
	(void)argv;
	(void)argc;

	// all_info = (t_all *){0};
	// if (argc != 2 || (argv && !argv[1]))
	// 	return (perror("The game can handle exactly one \"file.cub\" as an argument.\n"), 0);
	// all_info = parse_file(argv[1]);
	start_game(&mlx);
	return (0);
}
