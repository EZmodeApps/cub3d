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

static void	player(t_parse *p) // will be upgraded
{
	int	i;
	int	j;

	i = -1;
	while (p->map[++i])
	{
		j = -1;
		while (p->map[i][++j])
		{
			if (p->map[i][j] == 'N' || p->map[i][j] == 'W'
				|| p->map[i][j] == 'S' || p->map[i][j] == 'E')
			{
				p->play_x = j;
				p->play_y = i;
				return ;
			}
		}
	}
}

int	parse_map(t_parse *p, char *file)
{
	int		fd;
	char	*buf;

	fd = get_text_and_colors(p, file);
	if (fd < 0)
		error("get text and colors");
	get_map(p, file, fd);
	if (!p->map)
		error("get_map");
	check_map(p);
	player(p);
	return (0);
}
