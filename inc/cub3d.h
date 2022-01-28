#ifndef CUB3D_H
# define CUB3D_H

# define BUF_GNL 2048

# include "libft.h"
# include "../src/gnl/get_next_line.h"
# include "../lib/minilibx_opengl_20191021/mlx.h"

# include <stdio.h>
# include <fcntl.h>

typedef struct s_parse
{
	int	fd_NO;
	int	fd_SO;
	int	fd_WE;
	int	fd_EA;

	int f_color;
	int	c_color;

	char **map;
}			t_parse;

void	error(char *str);

// init/init.c
void	init_all(t_parse *all);

// parse/initialize.c
int		parse_map(t_parse *all, char *file);

// parse/get_text_and_colors.c
int		get_text_and_colors(t_parse *all, char *file);

// utils/libft_utils.c
int		skip_spaces(char *buf);
void	*ft_realloc(char **mas, int count);

#endif