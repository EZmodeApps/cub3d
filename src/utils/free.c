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

void	free_tex(t_all *all)
{
	int	i;

	i = 0;
	while (all->tex[i])
	{
		if (all->tex[i]->img)
			free(all->tex[i]->img);
		if (all->tex[i]->path)
			free(all->tex[i]->path);
		if (all->tex[i]->addr)
			free(all->tex[i]->addr);
		if (all->tex[i])
			free(all->tex[i]);
		i++;
	}
	if (all->tex)
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
}
