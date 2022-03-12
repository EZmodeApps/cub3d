/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:00:39 by lholdo            #+#    #+#             */
/*   Updated: 2022/03/12 04:00:39 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	valid_character(t_parse *all, int i, int j)
{
	if (all->map[i][j] != '0'
		&& all->map[i][j] != '1'
		&& all->map[i][j] != ' '
		&& all->map[i][j] != 'N'
		&& all->map[i][j] != 'S'
		&& all->map[i][j] != 'W'
		&& all->map[i][j] != 'E')
		error("Error: Invalid character found");
}

static int	count_t_b_walls(t_parse *all, int flag)
{
	int	top;
	int	bot;

	top = 0;
	bot = 0;
	if (flag == 0)
		while (all->map[0][top] == '1')
			top++;
	else
		while (all->map[all->height][bot] == '1')
			bot++;
	if (flag == 0)
		return (top);
	else
		return (bot);
}

int	check_walls(t_parse *all)
{
	int	i;
	int	top;
	int	bottom;
	int	mid;

	i = 1;
	mid = 0;
	top = count_t_b_walls(all, 0);
	bottom = count_t_b_walls(all, 1);
	while (i < all->height - 1)
	{
		if (all->map[i][0] == '1' &&
			all->map[i][(ft_strlen(all->map[i]) - 1)] == '1')
			mid++;
		i++;
	}
	if (top == ft_strlen(all->map[0])
		&& bottom == ft_strlen(all->map[all->height])
		&& mid == (all->height - 2))
		return (1);
	else
		return (0);
}

static void	duplications(t_parse *all, int i, int j, int *dupl)
{
	if (all->map[i][j] == 'N' || all->map[i][j] == 'W' ||
			all->map[i][j] == 'E' || all->map[i][j] == 'S')
		*dupl += 1;
	if (*dupl > 1)
		error("Error: Some symbols repeat");
}

void	check_map(t_parse *all)
{
	int	i;
	int	j;
	int	dupl;

	dupl = 0;
	i = -1;
	while (all->map[++i])
	{
		j = -1;
		while (all->map[i][++j])
		{
			if (all->map[i][j] == '\0' && all->map[i + 1])
				error("Error: Invalid map");
			valid_character(all, i, j);
			duplications(all, i, j, &dupl);
		}
	}
}
