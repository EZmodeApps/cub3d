#include "../inc/cub3d.h"

void	error(char *str)
{
	printf("%s\n", str);
	exit(-1);
}

int ft_exit(t_parse *all)
{
	exit(0);
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc < 2 || argc > 3 || (argc == 3 && ft_strncmp(argv[2], "--save", 6)))
		error("Invalid arguments");
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
		error("Screenshot");
	all.parse = (t_parse *)malloc(sizeof(t_parse));
	if (!all.parse)
		error("all.parse malloc error");
	parse_map(all.parse, argv[1]);
	draw(&all);
	mlx_hook(all.win->win_ptr, 17, 5, ft_exit, &all);
	mlx_loop(all.win->mlx_ptr);
	return (0);
}
