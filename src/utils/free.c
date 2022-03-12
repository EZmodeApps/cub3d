/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <lholdo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:01:23 by lholdo            #+#    #+#             */
/*   Updated: 2022/03/12 14:45:43 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_parse(t_all *all)
{
	if (all->parse->c_color)
		free(all->parse->c_color);
	if (all->parse->f_color)
		free(all->parse->f_color);
	if (all->parse->map)
		free_mas(all->parse->map);
	if (all->parse)
		free(all->parse);
}

void	free_prev(t_all *all)
{
	free_parse(all);
	if (all->ray)
		free(all->ray);
	if (all->draw)
		free(all->draw);
}

void	free_not_full_tex(t_all *all, int i)
{
	int	back;

	back = -1;
	while (++back < i)
		free(all->tex[back]);
	free(all->tex);
	free_prev(all);
	error("Error: All.Tex[i] allocation failed");
}

void	free_win(t_all *all)
{
	free_prev(all);
	if (all->win->img)
		mlx_destroy_image(all->win->mlx_ptr, all->win->img);
	if (all->win)
		mlx_destroy_window(all->win->mlx_ptr, all->win->win_ptr);
}
