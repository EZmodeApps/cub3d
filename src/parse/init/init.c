#include "cub3d.h"

void	init_all(t_parse *p)
{
	int i;

	p->fd_EA = 0;
	p->fd_NO = 0;
	p->fd_SO = 0;
	p->fd_WE = 0;
	p->play_x = -1;
	p->play_y = -1;
	if (!(p->c_color = malloc(sizeof(int) * 3)))
		error("color malloc");
	if (!(p->f_color = malloc(sizeof(int) * 3)))
		error("color 2 malloc");
	i = 0;
	while (i < 3)
	{
		p->c_color[i] = -1;
		p->f_color[i] = -1;
		i++;
	}
}
