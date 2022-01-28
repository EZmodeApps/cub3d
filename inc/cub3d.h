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
	
}			t_parse;

void	error(char *str);

// parse/initialize.c
char	**parse_map(char *file);

// utils/libft_utils.c
void	*ft_realloc(char **mas, int count);

#endif