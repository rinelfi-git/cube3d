NAME = cub3D
CC = gcc
CARG = -Werror -Wextra -Wall
INCs = -I./include -I./lib/mlx -I./lib/ft
SRCs = ./src/main.c \
		./src/error/fatal_error.c \
		./src/init/config.c \
		./src/init/cube3d.c \
		./src/init/key.c \
		./src/init/mlx.c \
		./src/init/player.c \
		./src/init/ray.c \
		./src/pixel/draw.c \
		./src/pixel/put_pixel.c
OBJs = $(SRCs:.c=.o)
LIBs = -L./lib/mlx -lmlx -L/usr/lib -lXext -lX11 -lm -lz \
		-L./lib/ft -lft
LIB_MLX = ./lib/mlx/libmlx.a
LIB_FT = ./lib/ft/libft.a

all: $(NAME)

$(NAME): $(OBJs) $(LIB_MLX) $(LIB_FT)
	$(CC) $(OBJs) $(LIBs) -o $(NAME)

clean:
	rm -rf $(OBJs)
	rm -rf ./lib/mlx/*.o
	make -C ./lib/ft clean

fclean: clean
	rm -rf $(NAME)
	rm -rf ./lib/mlx/*.a
	make -C ./lib/ft fclean

re: fclean all

%.o: %.c
	$(CC) $(CARG) -O3 $(INCs) -c $< -o $@

$(LIB_MLX) :
	make -C ./lib/mlx

$(LIB_FT) :
	make -C ./lib/ft
