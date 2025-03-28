CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fractol
SRC = main.c ./src/parser.c ./src/utils.c ./src/fractol.c ./src/img.c ./src/mlx_data.c ./src/math.c
OBJ = $(SRC:.c=.o)
LIBFT_NAME = src/libft/libft.a
LINKS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

libft: $(LIBFT_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(LIBFT_NAME) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_NAME) $(LINKS) -o $(NAME)

$(LIBFT_NAME):
	$(MAKE) -C ./src/libft

clean:
	$(MAKE) -C src/libft clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C src/libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
