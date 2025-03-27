CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = $(shell find . -type f -name "*.c")
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	clean
