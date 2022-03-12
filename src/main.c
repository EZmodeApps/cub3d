/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:01:58 by lholdo            #+#    #+#             */
/*   Updated: 2022/03/12 13:34:00 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	error(char *str)
{
	ft_putstr_fd(str, 2);
	write(2, "\n", 1);
	exit(-1);
}

int	ft_exit(t_all *all)
{
	exit(0);
}

int	check_extension(char *str)
{
	while (*str != '.')
		str++;
	if (!ft_strncmp(str, ".cub", 4))
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc != 2 || !check_extension(argv[1]))
		error("Error: Invalid arguments");
	alloc_all(&all);
	if (!init_win(&all))
	{
		free_win(&all);
		error("Error: Window allocation failed");
	}
	parse_map(&all, argv[1]);
	mlx_loop_hook(all.win->mlx_ptr, draw, &all);
	mlx_hook(all.win->win_ptr, 2, 1L << 0, buttons, &all);
	mlx_hook(all.win->win_ptr, 6, 0L, mouse_move, &all);
	mlx_hook(all.win->win_ptr, 17, 5, ft_exit, &all);
	mlx_loop(all.win->mlx_ptr);
	return (0);
}
