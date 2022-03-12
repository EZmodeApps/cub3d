/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:00:51 by lholdo            #+#    #+#             */
/*   Updated: 2022/03/12 13:29:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_split(char **color)
{
	int	i;

	i = 0;
	while (color[i])
		i++;
	if (i == 3)
		return (1);
	else
		return (0);
}

static char	**alloc_last(t_parse *p, char *buf, int i)
{
	p->map = (char **)ft_realloc(p->map, i);
	if (!p->map)
		error("Malloc error");
	p->map[i] = ft_strdup(buf);
	free(buf);
	if (!p->map[i])
		error("Malloc error");
	p->map = (char **)ft_realloc(p->map, ++i);
	if (!p->map)
		error("Malloc error");
	p->map[i] = NULL;
	return (p->map);
}

static char	**get_map(t_parse *p, int fd)
{
	char	*buf;
	int		i;

	p->map = NULL;
	buf = NULL;
	i = 0;
	while (get_next_line(fd, &buf))
	{
		if (buf[0] == '\0')
			continue ;
		p->map = (char **)ft_realloc(p->map, i);
		if (!p->map)
			error("Malloc error");
		p->map[i] = ft_strdup(buf);
		free(buf);
		if (!p->map[i])
			error("Malloc error");
		i++;
	}
	p->height = i;
	close(fd);
	return (alloc_last(p, buf, i));
}

static void	open_tex_n_sp(t_all *all)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		all->tex[i]->img = mlx_xpm_file_to_image(all->win->mlx_ptr,
				all->tex[i]->path, &all->tex[i]->width, &all->tex[i]->height);
		if (!all->tex[i]->img)
			error("Error: Load textures");
		all->tex[i]->addr = mlx_get_data_addr(all->tex[i]->img,
				&(all->tex[i]->bits_per_pixel), &(all->tex[i]->line_length),
				&(all->tex[i]->endian));
	}
}

int	parse_map(t_all *all, char *file)
{
	int	fd;

	fd = get_text_and_colors(all, file);
	all->parse->map = get_map(all->parse, fd);
	if (!all->parse->map)
		error("Error: Issue in Get_map function");
	check_map(all->parse);
	if (!(check_walls(all->parse)))
		error("Error: Map is not surrounded by walls");
	player(all);
	open_tex_n_sp(all);
	return (0);
}
