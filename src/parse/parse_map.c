#include "../../inc/cub3d.h"

static char	**alloc_last(t_parse *p, char *buf, int i)
{
	p->map = (char **)ft_realloc(p->map, i);
	if (!p->map)
		error("Malloc error");
	p->map[i] = (char *)malloc(sizeof(char) * (ft_strlen(buf) + 1));
	if (!p->map[i])
		error("Malloc error");
	ft_strlcpy(p->map[i], buf, ft_strlen(buf) + 1);
	p->map = (char **)ft_realloc(p->map, ++i);
	if (!p->map)
		error("Malloc error");
	p->map[i] = NULL;
	free(buf);
	return (p->map);
}

static char	**get_map(t_parse *p, char *file, int fd)
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
		p->map[i] = (char *)malloc(sizeof(char) * (ft_strlen(buf) + 1));
		if (!p->map[i])
			error("Malloc error");
		ft_strlcpy(p->map[i], buf, ft_strlen(buf) + 1);
		free(buf);
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
	while (++i < 5)
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

void	alloc_col(t_parse *all)
{
	int i;

	i = 0;
	all->col_coord = malloc(sizeof(int**));
	if (!all->col_coord)
	{
		free(all);
		error("Malloc error");
	}
//	while (i < all->col_number)
	while (i < 3)
	{
		all->col_coord[i] = malloc(sizeof(int) * 2);
		if (!all->col_coord[i])
		{
			free(all);
			error("Malloc error");
		}
		i++;
	}
}

void save_col_coord(t_parse *all)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (all->map[x])
	{
		while (all->map[x][y])
		{
			if (all->map[x][y] == '2')
			{
				all->col_coord[i][0] = x;
				all->col_coord[i][1] = y;
				printf("x - %d\n", all->col_coord[i][0]);
				printf("y - %d\n", all->col_coord[i][1]);
				i++;
			}
			printf("%c", all->map[x][y]);
			y++;
		}
		x++;
	}
}

void count_col(t_parse *all)
{
	int i;
	int j;
	int num;

	i = 0;
	j = 0;
	num = 0;
	while (all->map[i][j])
	{
		while (all->map[i][j])
		{
			if (all->map[i][j] == '2')
				num++;
			j++;
		}
		i++;
	}
	all->col_number = num;
	printf("num - %d\n", all->col_number);
}

int	parse_map(t_all *all, char *file)
{
	int	fd;

	fd = get_text_and_colors(all, file);
	if (fd < 0)
		error("Error: Fd issue on get_text_and_colors");
	get_map(all->parse, file, fd);
	if (!all->parse->map)
		error("Error: Issue in Get_map function");
	//alloc_col(all->parse);
	check_map(all->parse);
//	count_col(all->parse);
	//save_col_coord(all->parse);
	player(all);
	open_tex_n_sp(all);
	return (0);
}
