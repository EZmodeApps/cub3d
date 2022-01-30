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
		error("Invalid character found");
}

static void	surroundness(t_parse *all, int i, int j)
{
	if ((i && all->map[i - 1][j] == ' ')
		|| (i < all->height && all->map[i + 1][j] == ' ')
		|| (j && all->map[i][j - 1] == ' ')
		|| (j < ft_strlen(all->map[i])
		&& all->map[i][j + 1] == ' '))
		error("Map is not surrounded by walls");
}

static void	duplications(t_parse *all, int i, int j, int *dupl)
{
	if (all->map[i][j] == 'N' || all->map[i][j] == 'W' ||
			all->map[i][j] == 'E' || all->map[i][j] == 'S')
		*dupl += 1;
	if (*dupl > 1)
		error("Some symbols repeat");
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
				error("Invalid map");
			valid_character(all, i, j);
			duplications(all, i, j, &dupl);
			if (all->map[i][j] == '0')
				surroundness(all, i, j);
		}
	}
}
