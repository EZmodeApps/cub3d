#include "cub3d.h"

static int	conv_color(t_parse *all, char *buf, int *color)
{
	int		i;
	int		j;
	char	*tmp;

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
	*color = 1; // color = new Color(r/255.0F,g/255.0F,b/255.0F,a/255.0F);
	return (*color);
}

static int	get_texture_fd(t_parse *all, char *buf, int *fd)
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

static int	check(t_parse *all, char *buf)
{
	if (!ft_strncmp(buf, "NO", 2) && buf[2] == ' ')
		return (get_texture_fd(all, buf, &all->fd_NO));
	else if (!ft_strncmp(buf, "SO", 2) && buf[2] == ' ')
		return (get_texture_fd(all, buf, &all->fd_SO));
	else if (!ft_strncmp(buf, "WE", 2) && buf[2] == ' ')
		return (get_texture_fd(all, buf, &all->fd_WE));
	else if (!ft_strncmp(buf, "EA", 2) && buf[2] == ' ')
		return (get_texture_fd(all, buf, &all->fd_EA));
	else if (!ft_strncmp(buf, "F", 1) && buf[1] == ' ')
		return (conv_color(all, buf, &all->f_color));
	else if (!ft_strncmp(buf, "C", 1) && buf[1] == ' ')
		return (conv_color(all, buf, &all->c_color));
	else
		return (0);
}

static int	types_are_read(t_parse *all)
{
	if (all->fd_EA == 0 || all->fd_NO == 0 || all->fd_SO == 0
		|| all->fd_WE == 0 || all->c_color == -1
		|| all->f_color == -1)
		return (0);
	return (1);
}

int	get_text_and_colors(t_parse *all, char *file)
{
	int		fd;
	char	*buf;
	int		ret;

	init_all(all);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Fd issue");
	while (get_next_line(fd, &buf) && !types_are_read(all))
	{
		ret = check(all, buf);
		if (ret < 0)
			error("ERROR");
		else if (!ret)
			continue ;
	}
	return (fd);
}
