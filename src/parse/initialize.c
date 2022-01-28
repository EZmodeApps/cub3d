#include "cub3d.h"

static char	**get_map(char *file)
{
	int		fd;
	char	**map;
	char	*buf;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Fd issue");
	i = 0;
	map = NULL;
	buf = NULL;
	while (get_next_line(fd, &buf))
	{
		if (buf[0] == '\0')
			continue ;
		map = (char **)ft_realloc(map, i);
		if (!map)
			error("Malloc error 0");
		map[i] = (char *)malloc(sizeof(char) * (ft_strlen(buf) + 1));
		if (!map[i])
			error("Malloc error 1");
		ft_strlcpy(map[i], buf, ft_strlen(buf) + 1);
		free(buf);
		i++;
	}
	close(fd);
	map = (char **)ft_realloc(map, i);
	if (!map)
		error("Malloc error 2");
	map[i] = (char *)malloc(sizeof(char) * (ft_strlen(buf) + 1));
	if (!map[i])
		error("Malloc error 3");
	ft_strlcpy(map[i], buf, ft_strlen(buf) + 1);
	map = (char **)ft_realloc(map, ++i);
	if (!map)
		error("Malloc issue 4");
	map[i] = NULL;
	free(buf);
	return (map);
}

char	**parse_map(char *file)
{
	char	**map;

	map = get_map(file);
	if (!map)
		return (NULL);
	return (map);
}
