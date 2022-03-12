/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 03:59:58 by lholdo            #+#    #+#             */
/*   Updated: 2022/03/12 03:59:58 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_square(t_all *all, int i, int j, int color)
{
	int	x;
	int	y;

	x = HEIGHT * 0.005 * j;
	y = HEIGHT * 0.005 * i;
	while (x < HEIGHT * 0.005 * (j + 1))
	{
		y = HEIGHT * 0.005 * i;
		while (y < HEIGHT * 0.005 * (i + 1))
		{
			put_pixel(all->win, x, y, color);
			y++;
		}
		x++;
	}
}

void	draw_player(t_all *all, int color)
{
	draw_square(all, all->parse->play_y, all->parse->play_x, color);
}

void	draw_mini_map(t_all *all, int color)
{
	int	i;
	int	j;

	i = 0;
	while (all->parse->map[i])
	{
		j = 0;
		while (all->parse->map[i][j] != '\0')
		{
			if (all->parse->map[i][j] == '1')
				draw_square(all, i, j, color);
			else if (all->parse->map[i][j] == ' ')
			{
				j++;
				continue ;
			}
			else
				draw_square(all, i, j, 0x808080);
			j++;
		}
		i++;
	}
}
