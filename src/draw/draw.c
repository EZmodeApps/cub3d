#include "cub3d.h"

static void	tex_init(t_all *all)
{
	if (all->ray->side == 0 || all->ray->side == 1)
		all->draw->wallx = all->parse->play_y
			+ all->ray->walldist * all->ray->raydir_y;
	else
		all->draw->wallx = all->parse->play_x
			+ all->ray->walldist * all->ray->raydir_x;
	all->draw->wallx -= floor((all->draw->wallx));
	all->draw->texx = (int)(all->draw->wallx * (double)(TEXWIDTH));
	if ((all->ray->side == 0 || all->ray->side == 1) && all->ray->dir_x >= 0)
		all->draw->texx = TEXWIDTH - all->draw->texx - 1;
	if ((all->ray->side == 2 || all->ray->side == 3) && all->ray->dir_y <= 0)
		all->draw->texx = TEXWIDTH - all->draw->texx - 1;
	all->draw->step = 1.0 * TEXHEIGHT / all->draw->lineh;
	all->draw->texpos = (all->ray->start - HEIGHT / 2
			+ all->draw->lineh / 2) * all->draw->step;
}

static void	draw_texture(t_all *all, int x)
{
	unsigned int	color;
	int				y;
//в рэй добавить текстуру коллектбле
	tex_init(all);
	y = all->ray->start - 1;
	while (++y <= all->ray->end)
	{
		all->draw->texy = (int) all->draw->texpos & (TEXHEIGHT - 1);
		all->draw->texpos += all->draw->step;
		if (all->ray->side == 0)
			color = ((unsigned int *)(all->tex[0]->addr))
			[TEXHEIGHT * all->draw->texy + all->draw->texx];
		else if (all->ray->side == 1)
			color = ((unsigned int *)(all->tex[1]->addr))
			[TEXHEIGHT * all->draw->texy + all->draw->texx];
		else if (all->ray->side == 2)
			color = ((unsigned int *)(all->tex[2]->addr))
			[TEXHEIGHT * all->draw->texy + all->draw->texx];
		else if (all->ray->side == 3)
			color = ((unsigned int *)(all->tex[3]->addr))
			[TEXHEIGHT * all->draw->texy + all->draw->texx];
//		else if (all-> == )
//			color = ((unsigned int *)(all->tex[4]->addr))
//			[TEXHEIGHT * all->draw->texy + all->draw->tex_col];
		put_pixel(all->win, x, y, color);
	}
}

static void	floor_and_ceiling(t_all *all, int fl_color, int ci_color)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				put_pixel(all->win, x, y, ci_color);
			else
				put_pixel(all->win, x, y, fl_color);
		}
	}
}

static void	raycasting(t_all *all)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		init_drawing(all, x);
		calculate_step(all);
		dda(all);
		calculate_stripe(all);
		draw_texture(all, x);
	}
}

int	draw(t_all *all)
{
	floor_and_ceiling(all, convert_rgb(all->parse->f_color[0],
			all->parse->f_color[1], all->parse->f_color[2]),
		convert_rgb(all->parse->c_color[0],
			all->parse->c_color[1], all->parse->c_color[2]));
	raycasting(all);
	// bonus
	draw_mini_map(all, 0);
	draw_player(all, 65280);
	// bonus
	mlx_put_image_to_window(all->win->mlx_ptr, all->win->win_ptr,
		all->win->img, 0, 0);
	return (1);
}
