CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ./ft_atoi.c ./ft_bzero.c ./ft_calloc.c ./ft_isdigit.c ./ft_istrchr.c ./ft_memcpy.c ./ft_memset.c ./ft_print_nbr.c ./ft_print_str.c ./ft_split.c ./ft_strdup.c ./ft_strjoin.c ./ft_strlcpy.c ./ft_strlen.c ./ft_strndup.c ./ft_strsearch.c ./ft_substr.c ./get_next_line.c ./ft_printf.c ./ft_strncmp.c ./ft_atod.c
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
