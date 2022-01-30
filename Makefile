NAME = cub3d

FLAGS = -Wall -Wextra -Werror -g

MINILIBX = ./lib/minilibx_opengl_20191021/
LINK_MINILIBX = -Llib/minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

LIBFT = ./lib/libft/
LINK_LIBFT = -Llib/libft -lft

INC = $(shell find inc -name '*.h')
INC_DIR = -Iinc
INC_LIBFT = -Ilib/libft

SRC = $(shell find src -name '*.c')
OBJ = $(SRC:%.c=%.o)

RM = rm -rf

all: libft mlx $(NAME)

libft:
	@make -C $(LIBFT)

mlx:
	@make -C $(MINILIBX)

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(INC_DIR) $(LINK_MINILIBX) $(LINK_LIBFT) $^ -o $@

%.o: %.c $(INC)
	gcc $(CFLAGS) $(INC_DIR) $(INC_LIBFT) $< -c -o $@

clean:
	$(RM) $(OBJ)
	@make clean -C $(LIBFT)
	@make clean -C $(MINILIBX)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all libft mlx clean fclean re