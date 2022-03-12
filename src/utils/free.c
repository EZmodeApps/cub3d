/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:01:23 by lholdo            #+#    #+#             */
/*   Updated: 2022/03/12 04:01:23 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_parse(t_all *all)
{
	free(all->parse->c_color);
	free(all->parse->f_color);
	free_mas(all->parse->map);
	free(all->parse);
}

void	free_prev(t_all *all)
{
	free_parse(all);
	free(all->ray);
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

void	free_tex(t_all *all)
{
	int	i;

	i = 0;
	while (all->tex[i])
	{
		free(all->tex[i]);
		i++;
	}
	free(all->tex);
}

void	free_win(t_all *all)
{
	free_prev(all);
	free_tex(all);
	if (all->win->mlx_ptr)
		free(all->win->mlx_ptr);
	if (all->win->win_ptr)
		free(all->win->win_ptr);
	if (all->win->img)
		free(all->win->img);
	if (all->win->addr)
		free(all->win->addr);
	if (all->win)
		free(all->win);
	error("Error: All.Win allocation failed");
}
