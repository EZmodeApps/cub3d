#include "cub3d.h"

void	error(char *str)
{
	printf("%s\n", str);
	exit(-1);
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc < 2 || argc > 3 || (argc == 3 && ft_strncmp(argv[2], "--save", 6)))
		error("Invalid arguments");
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
		error("Screenshot");
	map = parse_map(argv[1]);
	return (0);
}
