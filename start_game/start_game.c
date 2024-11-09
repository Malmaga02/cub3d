#include "../cubed.h"

int quit_game(t_mlx *all)
{
	mlx_destroy_window(all->mlx, all->mlx_win);
	mlx_destroy_display(all->mlx);
	exit(0);
	return 0;
}

int close_window(int keycode, t_mlx *pContainer)
{
	if (keycode == KEY_ESC)
	{
		ft_printf("GAME CLOSED SUCCESSFULLY");
		quit_game(pContainer);
	}
	return (1);
}

void	start_game(t_mlx *all)
{
	all->mlx = mlx_init();
	all->mlx_win = mlx_new_window(all->mlx, 1080, 720, "cub3d");
	mlx_hook(all->mlx_win, KeyPress, KeyPressMask, &close_window, &all);
	mlx_hook(all->mlx_win, 17, 1L << 17, quit_game, &all);
	mlx_loop(all->mlx);
}
