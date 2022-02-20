#include "cub3d.h"

static int	conv_color(char *buf, int *color, int *check)
{
	char	**split;
	char	*tmp;
	int		i;

	tmp = get_trim_color(buf);
	if (!tmp)
		return (-1);
	split = ft_split(tmp, ',');
	if (!split)
		return (-1);
	i = 0;
	while (i < 3)
	{
		color[i] = ft_atoi(split[i]);
		if (color[i] > 255 || color[i] < 0)
			error("Error: Wrong rgb value");
		i++;
	}
	free(tmp);
	free_mas(split);
	*check = 0;
	return (1);
}

static int	get_texture(t_all *all, char *buf, int count, int *check)
{
	int	j;
	int	i;

	i = skip_spaces(buf);
	all->tex[count]->path = (char *)malloc(sizeof(char) * (ft_strlen(buf) - i));
	if (!all->tex[count]->path)
		return (-1);
	j = 0;
	while (buf[i] != '\0')
	{
		all->tex[count]->path[j] = buf[i];
		j++;
		i++;
	}
	all->tex[count]->path[j] = '\0';
	*check = 1;
	return (1);
}

static int	check(t_all *all, char *buf)
{
	if (!ft_strncmp(buf, "EA", 2) && buf[2] == ' ')
		return (get_texture(all, buf, 0, &all->parse->fd_ea));
	else if (!ft_strncmp(buf, "WE", 2) && buf[2] == ' ')
		return (get_texture(all, buf, 1, &all->parse->fd_we));
	else if (!ft_strncmp(buf, "NO", 2) && buf[2] == ' ')
		return (get_texture(all, buf, 2, &all->parse->fd_no));
	else if (!ft_strncmp(buf, "SO", 2) && buf[2] == ' ')
		return (get_texture(all, buf, 3, &all->parse->fd_so));
	else if (!ft_strncmp(buf, "F", 1) && buf[1] == ' ')
		return (conv_color(buf, all->parse->f_color, &all->parse->check_f));
	else if (!ft_strncmp(buf, "C", 1) && buf[1] == ' ')
		return (conv_color(buf, all->parse->c_color, &all->parse->check_c));
	else
		return (0);
}

static int	types_are_read(t_parse *p)
{
	if (p->fd_ea == 0 || p->fd_no == 0 || p->fd_so == 0
		|| p->fd_we == 0 || p->check_c == -1
		|| p->check_f == -1)
		return (0);
	return (1);
}

int	get_text_and_colors(t_all *all, char *file)
{
	int		fd;
	int		ret;
	char	*buf;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Error: Fd issue");
	init_parse(all->parse);
	while (get_next_line(fd, &buf) && !types_are_read(all->parse))
	{
		ret = check(all, buf);
		if (ret < 0)
			error("Error: check validation failed");
		free(buf);
	}
	free(buf);
	return (fd);
}
