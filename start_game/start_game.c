#include "../cubed.h"

int	quit_game(t_mlx *pMlx)
{
	//free di tutte le struct una volta arrivati a fine gioco e/o errore
	mlx_destroy_window(pMlx->mlx, pMlx->mlx_win);
	mlx_destroy_display(pMlx->mlx);
	exit(0);
	return 0;
}

int	close_window(int keycode, t_mlx *pMlx)
{
	if (keycode == KEY_ESC)
	{
		ft_printf("GAME CLOSED SUCCESSFULLY");
		quit_game(pMlx);
	}
	return (1);
}

void	start_game(t_mlx *pMlx)
{
	//call a fn per inizializzazione struct
	pMlx->mlx = mlx_init();
	pMlx->mlx_win = mlx_new_window(pMlx->mlx, SCREEN_H, SCREEN_W, "cub3d");
	mlx_hook(pMlx->mlx_win, KeyPress, KeyPressMask, &close_window, &pMlx);
	mlx_hook(pMlx->mlx_win, 17, 1L << 17, quit_game, &pMlx);
	mlx_loop(pMlx->mlx);
}
