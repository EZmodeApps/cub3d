/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:00:06 by lholdo            #+#    #+#             */
/*   Updated: 2022/03/12 04:00:06 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
