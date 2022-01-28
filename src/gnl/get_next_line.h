#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "cub3d.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*ft_mod_strdup(char *str);
char	*ft_mod_strjoin(char *s1, char *s2);
int		ft_mod_strchr(const char *str, char c);
int		get_next_line(int fd, char **line);

#endif