#include "../../inc/cub3d.h"

static char	**alloc_last(t_parse *all, char *buf, int i)
{
	all->map = (char **)ft_realloc(all->map, i);
	if (!all->map)
		error("Malloc error");
	all->map[i] = (char *)malloc(sizeof(char) * (ft_strlen(buf) + 1));
	if (!all->map[i])
		error("Malloc error");
	ft_strlcpy(all->map[i], buf, ft_strlen(buf) + 1);
	all->map = (char **)ft_realloc(all->map, ++i);
	if (!all->map)
		error("Malloc error");
	all->map[i] = NULL;
	free(buf);
	return (all->map);
}

static char	**get_map(t_parse *all, char *file, int fd)
{
	char	*buf;
	int		i;

	all->map = NULL;
	buf = NULL;
	i = 0;
	while (get_next_line(fd, &buf))
	{
		if (buf[0] == '\0')
			continue ;
		all->map = (char **)ft_realloc(all->map, i);
		if (!all->map)
			error("Malloc error");
		all->map[i] = (char *)malloc(sizeof(char) * (ft_strlen(buf) + 1));
		if (!all->map[i])
			error("Malloc error");
		ft_strlcpy(all->map[i], buf, ft_strlen(buf) + 1);
		free(buf);
		i++;
	}
	all->height = i;
	close(fd);
	return (alloc_last(all, buf, i));
}

int	parse_map(t_parse *all, char *file)
{
	int		fd;
	char	*buf;

	fd = get_text_and_colors(all, file);
	if (fd < 0)
		error("get text and colors");
	get_map(all, file, fd);
	if (!all->map)
		error("get_map");
	check_map(all);
	return (0);
}
