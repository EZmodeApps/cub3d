#ifndef CUB3D_H
# define CUB3D_H

# define BUF_GNL 2048

# define HEIGHT 1920
# define WIDTH 1080

# include "../lib/libft/libft.h"
# include "../src/utils/gnl/get_next_line.h"
# include "../lib/minilibx_opengl_20191021/mlx.h"

# include <stdio.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_parse
{
	int		fd_NO;
	int		fd_SO;
	int		fd_WE;
	int		fd_EA;
	int		*f_color;
	int		*c_color;
	int		play_x;
	int		play_y;
	int		height;
	char	**map;
}			t_parse;

typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}			t_win;

typedef struct	s_ray // значения этой структуры временны и созданы
{					// 	по туториалу.
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;

	double	cameraX;
	double	raydirX;
	double	raydirY;

	int		mapX;
	int		mapY;
	double	sidedistX;
	double	sidedistY;
	double	deltadistX;
	double	deltadistY;

	int		stepX;
	int		stepY;

	int		hit;
	int		side;

	double	perpWallDist;
}			t_ray;

typedef struct	s_all
{
	t_parse	*parse;
	t_win	*win;
	t_ray	*ray;
}			t_all;

void	error(char *str);

// init/init.c
void	init_all(t_parse *p);

// parse/check_map.c
void	check_map(t_parse *p);
// parse/initialize.c
int		parse_map(t_parse *p, char *file);
// parse/get_text_and_colors.c
int		get_text_and_colors(t_parse *p, char *file);

// draw/draw.c
void	put_pixel(t_win *win, int x, int y, int color);
int		convert_rgb(int r, int g, int b);
int		draw(t_all *all);

// utils/libft_utils.c
void	free_mas(char **mas);
int		skip_spaces(char *buf);
void	*ft_realloc(char **mas, int count);


#endif