#include "get_next_line.h"
#include "cub3d.h"

static int	ft_dupline(char **line, char *buffer)
{	
	char	*tmp;

	tmp = ft_mod_strjoin(*line, buffer);
	if (tmp == NULL)
		return (-1);
	free(*line);
	*line = ft_mod_strdup(tmp);
	free(tmp);
	if (line == NULL)
		return (-1);
	return (0);
}

static int	ft_ret(char **line, char *buffer, int count)
{
	int	i;
	int	n;

	if (count == -1)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	if (ft_mod_strchr(buffer, '\n') == -1)
	{
		ft_dupline(line, buffer);
		buffer[0] = '\0';
		return (0);
	}
	else
	{
		ft_dupline(line, buffer);
		i = -1;
		n = ft_mod_strchr(buffer, '\n');
		while (buffer[n + ++i + 1])
			buffer[i] = buffer[n + i + 1];
		buffer[i] = '\0';
		return (1);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			count;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	*line = NULL;
	if (ft_strlen(buffer) == 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		buffer[count] = '\0';
	}	
	else
		count = BUFFER_SIZE;
	while (count == BUFFER_SIZE && ft_mod_strchr(buffer, '\n') == -1)
	{
		ft_dupline(line, buffer);
		count = read(fd, buffer, BUFFER_SIZE);
		buffer[count] = '\0';
	}
	return (ft_ret(line, buffer, count));
}
