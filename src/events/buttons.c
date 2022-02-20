#include "cub3d.h"

static void	move_forward(t_all *all)
{
	if (all->parse->map[(int)all->parse->play_y]
		[(int)(all->parse->play_x + all->ray->dir_x
			* SPEED + 0.001)] == '0' || all->parse->map[(int)all->parse->play_y]
		[(int)(all->parse->play_x + all->ray->dir_x
			* SPEED + 0.001)] == ' ')
		all->parse->play_x += all->ray->dir_x
			* SPEED + 0.001;
	if (all->parse->map[(int)(all->parse->play_y
			+ all->ray->dir_y * SPEED + 0.001)]
		[(int)all->parse->play_x] == '0' ||
		all->parse->map[(int)(all->parse->play_y
			+ all->ray->dir_y * SPEED + 0.001)]
		[(int)all->parse->play_x] == ' ')
		all->parse->play_y += all->ray->dir_y
			* SPEED + 0.001;
}

static void	move_back(t_all *all)
{
	if (all->parse->map[(int)all->parse->play_y]
		[(int)(all->parse->play_x - all->ray->dir_x
			* SPEED + 0.001)] == '0' ||
		all->parse->map[(int)all->parse->play_y]
		[(int)(all->parse->play_x - all->ray->dir_x
			* SPEED + 0.001)] == ' ')
		all->parse->play_x -= all->ray->dir_x
			* SPEED + 0.001;
	if (all->parse->map[(int)(all->parse->play_y
			- all->ray->dir_y * SPEED + 0.001)]
		[(int)all->parse->play_x] == '0' ||
		all->parse->map[(int)(all->parse->play_y
			- all->ray->dir_y * SPEED + 0.001)]
		[(int)all->parse->play_x] == ' ')
		all->parse->play_y -= all->ray->dir_y
			* SPEED + 0.001;
}

static void	move_left(t_all *all)
{
	if (all->parse->map[(int)all->parse->play_y]
		[(int)(all->parse->play_x - all->ray->plane_x
			* SPEED + 0.001)] == '0' ||
		all->parse->map[(int)all->parse->play_y]
		[(int)(all->parse->play_x - all->ray->plane_x
			* SPEED + 0.001)] == ' ')
		all->parse->play_x -= all->ray->plane_x
			* SPEED + 0.001;
	if (all->parse->map[(int)(all->parse->play_y
			- all->ray->plane_y * SPEED + 0.001)]
		[(int)all->parse->play_x] == '0' ||
		all->parse->map[(int)(all->parse->play_y
			- all->ray->plane_y * SPEED + 0.001)]
		[(int)all->parse->play_x] == ' ')
		all->parse->play_y -= all->ray->plane_y
			* SPEED + 0.001;
}

static void	move_right(t_all *all)
{
	if (all->parse->map[(int)all->parse->play_y]
		[(int)(all->parse->play_x + all->ray->plane_x
			* SPEED + 0.001)] == '0' ||
		all->parse->map[(int)all->parse->play_y]
		[(int)(all->parse->play_x + all->ray->plane_x
			* SPEED + 0.001)] == ' ')
		all->parse->play_x += all->ray->plane_x
			* SPEED + 0.001;
	if (all->parse->map[(int)(all->parse->play_y
			+ all->ray->plane_y * SPEED + 0.001)]
		[(int)all->parse->play_x] == '0' ||
		all->parse->map[(int)(all->parse->play_y
			+ all->ray->plane_y * SPEED + 0.001)]
		[(int)all->parse->play_x] == ' ')
		all->parse->play_y += all->ray->plane_y
			* SPEED + 0.001;
}

int	buttons(int keycode, t_all *all)
{
	if (keycode == W)
		move_forward(all);
	if (keycode == S)
		move_back(all);
	if (keycode == A)
		move_left(all);
	if (keycode == D)
		move_right(all);
	if (keycode == LEFT)
		look_left(all);
	if (keycode == RIGHT)
		look_right(all);
	if (keycode == ESC)
		exit(0);
	return (1);
}
