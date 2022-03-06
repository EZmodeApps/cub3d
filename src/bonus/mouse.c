/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:54:31 by caniseed          #+#    #+#             */
/*   Updated: 2022/02/20 17:54:31 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	mouse_move(int x, int y, t_all *all)
{
	(void)y;

	if (x > (WIDTH / 2))
		look_right_bonus(all);
	else
		look_left_bonus(all);
	return (1);
}

void	look_right_bonus(t_all *all)
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

void	look_left_bonus(t_all *all)
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

