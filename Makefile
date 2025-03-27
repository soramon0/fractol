CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fractol
SRC = main.c $(shell find ./src -depth -maxdepth 1 -type f -name "*.c")
OBJ = $(SRC:.c=.o)
LIBFT_NAME = src/libft/libft.a
LIB_MLX = include/mlx/libmlx.a
LINKS = -lm -lz -lXext -lX11

all: $(NAME)

libft: $(LIBFT_NAME)

mlx: $(LIB_MLX)

$(NAME): $(LIB_MLX) $(LIBFT_NAME) $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIB_MLX) $(LIBFT_NAME) $(LINKS)

$(LIBFT_NAME):
	$(MAKE) -C ./src/libft

$(LIB_MLX):
	$(MAKE) -C ./include/mlx

clean:
	$(MAKE) -C src/libft clean
	$(MAKE) -C include/mlx clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C src/libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
