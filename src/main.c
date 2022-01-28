#include "cub3d.h"

void	error(char *str)
{
	printf("%s\n", str);
	exit(-1);
}

int ft_exit(t_parse *all)
{
	free(all);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_parse	all;
	void	*mlx_win;
	void	*mlx;

	if (argc < 2 || argc > 3 || (argc == 3 && ft_strncmp(argv[2], "--save", 6)))
		error("Invalid arguments");
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
	{
		//error("Screenshot");
		parse_map(&all,argv[1]);
		for (int i = 0; i <= 13; i++)
			printf("%s\n", all.map[i]);
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, 1920, 1080, "cub3D");
		mlx_hook(mlx_win, 17, 5, ft_exit, &all); //red cross exit,
		mlx_loop(mlx);
	}
//	parse_map(&all, argv[1]);
	return (0);
}