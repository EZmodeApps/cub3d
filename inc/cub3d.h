#ifndef CUB3D_H
# define CUB3D_H

# define HEIGHT 600
# define WIDTH 800

# include "../lib/libft/libft.h"
# include "../src/utils/gnl/get_next_line.h"
# include "../lib/minilibx_opengl_20191021/mlx.h"

# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define SPEED 0.15
# define ROTSPEED 0.040
# define SCALE 10
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define UDIV 1
# define VDIV 1
# define VMOVE 10

typedef struct s_parse
{
	int		fd_no;
	int		fd_so;
	int		fd_we;
	int		fd_ea;
	int		*f_color;
	int		*c_color;
	int		check_c;
	int		check_f;
	double	play_x;
	double	play_y;
	int		height;
	char	**map;
}			t_parse;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}			t_win;

typedef struct s_draw
{
	int			lineh;
	double		wallx;
	int			texx;
	int			texy;
	double		texpos;
	double		step;
}				t_draw;

typedef struct s_tex
{
	void		*img;
	char		*path;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_tex;

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	walldist;
	int		start;
	int		end;
}			t_ray;

typedef struct s_all
{
	t_parse	*parse;
	t_win	*win;
	t_ray	*ray;
	t_draw	*draw;
	t_tex	**tex;
	int		mouse_x;
	int 	mouse_y;
}			t_all;

void	error(char *str);

// alloc_and_init/alloc_and_init.c
int		init_win(t_all *all);
void	init_parse(t_parse *p);
void	alloc_tex(t_all *all);
void	alloc_all(t_all *all);
// parse/check_map.c
void	check_map(t_parse *p);
// parse/initialize.c
int		parse_map(t_all *all, char *file);
// parse/get_text_and_colors.c
int		get_text_and_colors(t_all *all, char *file);
// parse/player.c
void	player(t_all *all);

// draw/my_mlx_functions.c
void	put_pixel(t_win *win, int x, int y, int color);
int		convert_rgb(int r, int g, int b);
// draw/draw.c
int		draw(t_all *all);
// draw/raycasting.c
void	init_drawing(t_all *all, int x);
void	calculate_step(t_all *all);
void	calculate_distance(t_all *all);
void	dda(t_all *all);
void	calculate_stripe(t_all *all);

// draw/minimap.c
void	draw_player(t_all *all, int color);
void	draw_mini_map(t_all *all, int color);

// events/buttons.c
int		buttons(int keycode, t_all *all);
// events/arrows.c
void	look_right(t_all *all);
void	look_left(t_all *all);

// utils/free.c
void	free_parse(t_all *all);
void	free_prev(t_all *all);
void	free_not_full_tex(t_all *all, int i);
void	free_tex(t_all *all);
void	free_win(t_all *all);
// utils/libft_utils.c
char	*get_trim_color(char *buf);
void	free_mas(char **mas);
int		skip_spaces(char *buf);
void	*ft_realloc(char **mas, int count);
int		check_walls(t_parse *all);
//bonus
int		mouse_move(int x, int y, t_all *all);
void	look_right_mouse(t_all *all);
void	look_left_mouse(t_all *all);

#endif
