#include "cub3d.h"

static char	**get_map(char *file, int fd)
{
	char	**map;
	char	*buf;
	int		i;

	i = 0;
	map = NULL;
	buf = NULL;
	while (get_next_line(fd, &buf))
	{
		if (buf[0] == '\0')
			continue ;
		map = (char **)ft_realloc(map, i);
		if (!map)
			error("Malloc error");
		map[i] = (char *)malloc(sizeof(char) * (ft_strlen(buf) + 1));
		if (!map[i])
			error("Malloc error");
		ft_strlcpy(map[i], buf, ft_strlen(buf) + 1);
		free(buf);
		i++;
	}
	close(fd);
	map = (char **)ft_realloc(map, i);
	if (!map)
		error("Malloc error");
	map[i] = (char *)malloc(sizeof(char) * (ft_strlen(buf) + 1));
	if (!map[i])
		error("Malloc error");
	ft_strlcpy(map[i], buf, ft_strlen(buf) + 1);
	map = (char **)ft_realloc(map, ++i);
	if (!map)
		error("Malloc error");
	map[i] = NULL;
	free(buf);
	return (map);
}

int	parse_map(t_parse *all, char *file)
{
	int		fd;
	char	*buf;

	fd = get_text_and_colors(all, file);
	if (fd < 0)
		error("get text and colors");
	all->map = get_map(file, fd);
	if (!all->map)
		error("get_map");
	// check_map(all); // Проверить карту на валидность
	return (0);
}
