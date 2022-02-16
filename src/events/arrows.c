#include "cub3d.h"

void	look_right(t_all *all)
{
	double	olddirx;
	double	oldplanex;

	olddirx = all->ray->dir_x;
	oldplanex = all->ray->plane_x;
	all->ray->dir_x = all->ray->dir_x * cos(ROTSPEED)
		- all->ray->dir_y * sin(ROTSPEED);
	all->ray->dir_y = olddirx * sin(ROTSPEED)
		+ all->ray->dir_y * cos(ROTSPEED);
	all->ray->plane_x = all->ray->plane_x * cos(ROTSPEED)
		- all->ray->plane_y * sin(ROTSPEED);
	all->ray->plane_y = oldplanex * sin(ROTSPEED)
		+ all->ray->plane_y * cos(ROTSPEED);
}

void	look_left(t_all *all)
{
	double	olddirx;
	double	oldplanex;

	olddirx = all->ray->dir_x;
	oldplanex = all->ray->plane_x;
	all->ray->dir_x = all->ray->dir_x * cos(-ROTSPEED)
		- all->ray->dir_y * sin(-ROTSPEED);
	all->ray->dir_y = olddirx * sin(-ROTSPEED)
		+ all->ray->dir_y * cos(-ROTSPEED);
	all->ray->plane_x = all->ray->plane_x * cos(-ROTSPEED)
		- all->ray->plane_y * sin(-ROTSPEED);
	all->ray->plane_y = oldplanex * sin(-ROTSPEED)
		+ all->ray->plane_y * cos(-ROTSPEED);
}
