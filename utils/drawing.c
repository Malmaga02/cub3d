#include "cub3d.h"

void	draw_pixel(t_all *pAll, int x, int y, int color)
{
	t_img	*image;

	image = pAll->window.frame;
	int idx = (y * image->size_line + x * (image->bpp / 8));

	image->data[idx + 0] = (color) & 0xFF;
	image->data[idx + 1] = (color >> 8) & 0xFF;
	image->data[idx + 2] = (color >> 16) & 0xFF;
	image->data[idx + 3] = (color >> 24);
}

void	draw_rectangle(t_all *pAll, t_point start, t_point end, int color)
{
	int	rows;
	int	cols;

	rows = start.y;
	while (rows < end.y)
	{
		cols = start.x;
		while (cols < end.x)
		{
			draw_pixel(pAll, cols, rows, color);
			cols++;
		}
		rows++;
	}
}
