/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:00:54 by lholdo            #+#    #+#             */
/*   Updated: 2022/03/12 04:00:54 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	start_n(t_all *all, int i, int j)
{
	all->parse->play_x = j + 0.5;
	all->parse->play_y = i + 0.5;
	all->ray->dir_x = 0.0;
	all->ray->dir_y = -1.0;
	all->ray->plane_x = 0.66;
	all->ray->plane_y = 0.0;
	all->parse->map[i][j] = '0';
}

static void	start_s(t_all *all, int i, int j)
{
	all->parse->play_x = j + 0.5;
	all->parse->play_y = i + 0.5;
	all->ray->dir_x = 0.0;
	all->ray->dir_y = 1.0;
	all->ray->plane_x = -0.66;
	all->ray->plane_y = 0;
	all->parse->map[i][j] = '0';
}

static void	start_w(t_all *all, int i, int j)
{
	all->parse->play_x = j + 0.5;
	all->parse->play_y = i + 0.5;
	all->ray->dir_x = -1.0;
	all->ray->dir_y = 0.0;
	all->ray->plane_x = 0.0;
	all->ray->plane_y = -0.66;
	all->parse->map[i][j] = '0';
}

static void	start_e(t_all *all, int i, int j)
{
	all->parse->play_x = j + 0.5;
	all->parse->play_y = i + 0.5;
	all->ray->dir_x = 1.0;
	all->ray->dir_y = 0.0;
	all->ray->plane_x = 0.0;
	all->ray->plane_y = 0.66;
	all->parse->map[i][j] = '0';
}

void	player(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (all->parse->map[++i])
	{
		j = -1;
		while (all->parse->map[i][++j] != '\0')
		{
			if (all->parse->map[i][j] == 'N')
				start_n(all, i, j);
			else if (all->parse->map[i][j] == 'W')
				start_w(all, i, j);
			else if (all->parse->map[i][j] == 'S')
				start_s(all, i, j);
			else if (all->parse->map[i][j] == 'E')
				start_e(all, i, j);
			else
				continue ;
			return ;
		}
	}
	if (all->parse->play_x == -1 || all->parse->play_y == -1)
		error("Error: No player found");
}
