/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:00:37 by lholdo            #+#    #+#             */
/*   Updated: 2022/03/12 04:00:37 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_win(t_all *all)
{
	all->win = (t_win *)malloc(sizeof(t_win));
	if (!all->win)
		return (0);
	all->win->mlx_ptr = mlx_init();
	if (!all->win->mlx_ptr)
		return (0);
	all->win->win_ptr = mlx_new_window(all->win->mlx_ptr,
			WIDTH, HEIGHT, "Cub3d");
	if (!all->win->win_ptr)
		return (0);
	all->win->img = mlx_new_image(all->win->mlx_ptr, WIDTH, HEIGHT);
	if (!all->win->img)
		return (0);
	all->win->addr = mlx_get_data_addr(all->win->img,
			&(all->win->bits_per_pixel), &(all->win->line_len),
			&(all->win->endian));
	if (!all->win->addr)
		return (0);
	return (1);
}

void	init_parse(t_parse *p)
{
	p->fd_ea = 0;
	p->fd_no = 0;
	p->fd_so = 0;
	p->fd_we = 0;
	p->play_x = -1;
	p->play_y = -1;
	p->check_c = -1;
	p->check_f = -1;
}

void	alloc_tex(t_all *all)
{
	int	i;

	i = 0;
	all->tex = (t_tex **)malloc(sizeof(t_tex *) * 4);
	if (!all->tex)
	{
		free_prev(all);
		error("Error: All.Tex allocation failed");
	}
	while (i < 4)
	{
		all->tex[i] = (t_tex *)malloc(sizeof(t_tex));
		if (!all->tex[i])
			free_not_full_tex(all, i);
		all->tex[i]->img = NULL;
		i++;
	}
	all->tex[i] = NULL;
}

void	alloc_parse(t_all *all)
{
	all->parse = (t_parse *) malloc(sizeof(t_parse));
	if (!all->parse)
		error("Error: All.Parse allocation failed");
	all->parse->c_color = (int *)malloc(sizeof(int) * 3);
	if (!all->parse->c_color)
	{
		free(all->parse);
		error("Error: c_color allocation failed");
	}
	all->parse->f_color = (int *)malloc(sizeof(int) * 3);
	if (!all->parse->f_color)
	{
		free(all->parse);
		free(all->parse->c_color);
		error("Error: f_color allocation failed");
	}
	all->parse->play_x = -1;
	all->parse->play_y = -1;
}

void	alloc_all(t_all *all)
{
	alloc_parse(all);
	all->ray = (t_ray *)malloc(sizeof (t_ray));
	if (!all->ray)
	{
		free_parse(all);
		error("Error: All.Ray allocation failed");
	}
	all->draw = (t_draw *) malloc(sizeof (t_draw));
	if (!all->draw)
	{
		free_parse(all);
		free(all->ray);
		error("Error: All.Draw allocation failed");
	}
	alloc_tex(all);
}
