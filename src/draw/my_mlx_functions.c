#include "cub3d.h"

void	put_pixel(t_win *win, int x, int y, int color)
{
	int	i;

	i = (x * win->bits_per_pixel / 8) + (y * win->line_len);
	win->addr[i] = (char)color;
	win->addr[++i] = (char)(color >> 8);
	win->addr[++i] = (char)(color >> 16);
}

int	convert_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
