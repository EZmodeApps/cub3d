#include "../../inc/cub3d.h"

int	mouse_move(int x, int y, t_all *all)
{
	(void)y;

	if (x > all->mouse_x || x > 1035)
		look_right_mouse(all);
	else if (x < all->mouse_x || x < -235)
		look_left_mouse(all);
	printf("x - %d\n", x);
	all->mouse_x = x;
	return (1);
}

void	look_right_mouse(t_all *all)
{
	double	olddirx;
	double	oldplanex;

	olddirx = all->ray->dir_x;
	oldplanex = all->ray->plane_x;
	all->ray->dir_x = all->ray->dir_x * cos(0.0085)
					  - all->ray->dir_y * sin(0.0085);
	all->ray->dir_y = olddirx * sin(0.0085)
					  + all->ray->dir_y * cos(0.0085);
	all->ray->plane_x = all->ray->plane_x * cos(0.0085)
						- all->ray->plane_y * sin(0.0085);
	all->ray->plane_y = oldplanex * sin(0.0085)
						+ all->ray->plane_y * cos(0.0085);
}

void	look_left_mouse(t_all *all)
{
	double	olddirx;
	double	oldplanex;

	olddirx = all->ray->dir_x;
	oldplanex = all->ray->plane_x;
	all->ray->dir_x = all->ray->dir_x * cos(-0.0085)
					  - all->ray->dir_y * sin(-0.0085);
	all->ray->dir_y = olddirx * sin(-0.0085)
					  + all->ray->dir_y * cos(-0.0085);
	all->ray->plane_x = all->ray->plane_x * cos(-0.0085)
						- all->ray->plane_y * sin(-0.0085);
	all->ray->plane_y = oldplanex * sin(-0.0085)
						+ all->ray->plane_y * cos(-0.0085);
}

