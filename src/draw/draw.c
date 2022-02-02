#include "../../inc/cub3d.h"

static void	init_win(t_all *all)
{
	all->win = (t_win *)malloc(sizeof(t_win));
	if (!all->win)
		error("all.win malloc");
	if (!(all->win->mlx_ptr = mlx_init()))
		error("mlx_ptr init");
	if (!(all->win->win_ptr = mlx_new_window(all->win->mlx_ptr,
				HEIGHT, WIDTH, "Cub3d")))
		error("win_ptr init");
	if (!(all->win->img = mlx_new_image(all->win->mlx_ptr, HEIGHT, WIDTH)))
		error("img init");
	all->win->addr = mlx_get_data_addr(all->win->img,
		&(all->win->bits_per_pixel), &(all->win->line_len),
			&(all->win->endian));
}

void	put_pixel(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_len + x * (win->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	convert_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static void	floor_and_ceiling(t_all *all, int fl_color, int ci_color)
{
	int	x;
	int	y;

	x = -1;
	while (++x < HEIGHT)
	{
		y = -1;
		while (++y < WIDTH)
		{
			if (y < WIDTH / 2)
				put_pixel(all->win, x, y, ci_color);
			else
				put_pixel(all->win, x, y, fl_color);
		}
	}
}

int	draw(t_all *all)
{
	init_win(all);
	floor_and_ceiling(all,
		convert_rgb(all->parse->f_color[0], all->parse->f_color[1], all->parse->f_color[2]),
		convert_rgb(all->parse->c_color[0], all->parse->c_color[1], all->parse->c_color[2]));
	mlx_put_image_to_window(all->win->mlx_ptr, all->win->win_ptr,
				all->win->img, 0, 0);
	return (0);
}