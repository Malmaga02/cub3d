#include "cubed.h"
// all_info avra le info delle texture, della mappa e dell'init delle window mlx
// altro?
// tutti i possibili errori di mappa ecc li stampo in parse_and_handle
// ritorno NULL, dopo aver liberato tutto per bene
// start_game prepara e gestisce hook e loop per la finestra

int main(int argc, char **argv)
{
	t_mlx mlx;
	t_all *all_info;
	(void)argv;
	(void)argc;

	all_info = (t_all *){0};
	if (argc != 2 || (argv && !argv[1]))
		return (perror("The game can handle exactly one \"file.cub\" as an argument.\n"), 0);
	all_info = parse_file(argv[1]);
	start_game(&mlx);
	return (0);
}