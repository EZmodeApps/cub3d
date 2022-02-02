#include "cub3d.h"

static int	conv_color(t_parse *p, char *buf, int *color)
{
	char	**split;
	char	*tmp;
	int		i;
	int		j;

	i = skip_spaces(buf);
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(buf) - i));
	if (!tmp)
		return (-1);
	j = 0;
	while (buf[i] != '\0')
	{
		tmp[j] = buf[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	split = ft_split(tmp, ',');
	if (!split)
		return (-1);
	i = -1;
	while (++i < 3)
	{
		color[i] = ft_atoi(split[i]);
		if (color[i] > 255 || color[i] < 0)
			error("Wrong rgb val");
	}
	free(tmp);
	free_mas(split);
	return (1);
}

static int	get_texture_fd(t_parse *p, char *buf, int *fd)
{
	char	*tmp;
	int		j;
	int		i;

	i = skip_spaces(buf);
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(buf) - i));
	if (!tmp)
		return (-1);
	j = 0;
	while (buf[i] != '\0')
	{
		tmp[j] = buf[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	*fd = open(tmp, O_RDONLY);
	// if (fd < 0)
		// return (-1);
	return (1);
}

static int	check(t_parse *p, char *buf)
{
	if (!ft_strncmp(buf, "NO", 2) && buf[2] == ' ')
		return (get_texture_fd(p, buf, &p->fd_NO));
	else if (!ft_strncmp(buf, "SO", 2) && buf[2] == ' ')
		return (get_texture_fd(p, buf, &p->fd_SO));
	else if (!ft_strncmp(buf, "WE", 2) && buf[2] == ' ')
		return (get_texture_fd(p, buf, &p->fd_WE));
	else if (!ft_strncmp(buf, "EA", 2) && buf[2] == ' ')
		return (get_texture_fd(p, buf, &p->fd_EA));
	else if (!ft_strncmp(buf, "F", 1) && buf[1] == ' ')
		return (conv_color(p, buf, p->f_color));
	else if (!ft_strncmp(buf, "C", 1) && buf[1] == ' ')
		return (conv_color(p, buf, p->c_color));
	else
		return (0);
}

static int	types_are_read(t_parse *p)
{
	if (p->fd_EA == 0 || p->fd_NO == 0 || p->fd_SO == 0
		|| p->fd_WE == 0 || *p->c_color == -1
		|| *p->f_color == -1)
		return (0);
	return (1);
}

int	get_text_and_colors(t_parse *p, char *file)
{
	int		fd;
	char	*buf;
	int		ret;

	init_all(p);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Fd issue");
	while (get_next_line(fd, &buf) && !types_are_read(p))
	{
		ret = check(p, buf);
		if (ret < 0)
			error("ERROR");
		else if (!ret)
			continue ;
	}
	return (fd);
}
