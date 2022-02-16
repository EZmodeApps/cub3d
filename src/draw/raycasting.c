#include "cub3d.h"

void	init_drawing(t_all *all, int x)
{
	//calculate ray position and direction
	all->ray->camera = 2 * x / (double)(WIDTH) - 1;
	all->ray->raydir_x = all->ray->dir_x + all->ray->plane_x * all->ray->camera;
	all->ray->raydir_y = all->ray->dir_y + all->ray->plane_y * all->ray->camera;
	//which box of the map we're in
	all->ray->map_x = (int)(all->parse->play_x);
	all->ray->map_y = (int)(all->parse->play_y);
	//length of ray from one x or y-side to next x or y-side
	all->ray->deltadist_x = fabs(1 / all->ray->raydir_x);
	all->ray->deltadist_y = fabs(1 / all->ray->raydir_y);
	all->ray->hit = 0;
}

void	calculate_step(t_all *all)
{
	//calculate step and initial sideDist
	if (all->ray->raydir_x < 0)
	{
		all->ray->step_x = -1;
		all->ray->sidedist_x = (all->parse->play_x - all->ray->map_x)
			* all->ray->deltadist_x;
	}
	else
	{
		all->ray->step_x = 1;
		all->ray->sidedist_x = (all->ray->map_x + 1.0 - all->parse->play_x)
			* all->ray->deltadist_x;
	}
	if (all->ray->raydir_y < 0)
	{
		all->ray->step_y = -1;
		all->ray->sidedist_y = (all->parse->play_y - all->ray->map_y)
			* all->ray->deltadist_y;
	}
	else
	{
		all->ray->step_y = 1;
		all->ray->sidedist_y = (all->ray->map_y + 1.0 - all->parse->play_y)
			* all->ray->deltadist_y;
	}
}

void	calculate_distance(t_all *all)
{
	//Calculate distance projected on camera direction
	if (all->ray->side == 0 || all->ray->side == 1)
		all->ray->walldist = (all->ray->map_x - all->parse->play_x
				+ (1 - all->ray->step_x) / 2) / all->ray->raydir_x;
	else
		all->ray->walldist = (all->ray->map_y - all->parse->play_y
				+ (1 - all->ray->step_y) / 2) / all->ray->raydir_y;
}

void	dda(t_all *all)
{
	//perform DDA
	while (all->ray->hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (all->ray->sidedist_x < all->ray->sidedist_y)
		{
			all->ray->sidedist_x += all->ray->deltadist_x;
			all->ray->map_x += all->ray->step_x;
			if (all->ray->step_x == -1)
				all->ray->side = 0;
			else if (all->ray->step_x == 1)
				all->ray->side = 1;
		}
		else
		{
			all->ray->sidedist_y += all->ray->deltadist_y;
			all->ray->map_y += all->ray->step_y;
			if (all->ray->step_y == -1)
				all->ray->side = 2;
			else if (all->ray->step_y == 1)
				all->ray->side = 3;
		}
		//Check if ray has hit a wall
		if (all->parse->map[all->ray->map_y][all->ray->map_x] == '1')
			all->ray->hit = 1;
	}
	calculate_distance(all);
}

void	calculate_stripe(t_all *all)
{
	//calculate lowest and highest pixel to fill in current stripe
	all->draw->lineh = (int)(HEIGHT / all->ray->walldist);
	all->ray->start = -all->draw->lineh / 2 + HEIGHT / 2;
	if (all->ray->start < 0)
		all->ray->start = 0;
	all->ray->end = all->draw->lineh / 2 + HEIGHT / 2;
	if (all->ray->end >= HEIGHT)
		all->ray->end = HEIGHT - 1;
}
