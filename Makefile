NAME = pipex
CC = clang
CFLAGS = -Wall -Wextra -Werror -O3 -flto

SRC = \
	cmd.c \
	find.c \
	str_utils.c \
	child.c \
	free.c \
	pipex.c \

OBJ = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJ) libft/export/libft.a
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c libft/export/libft.a
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@if [ -d "libft" ]; then \
		make -C libft clean; \
	fi

fclean: clean
	rm -f $(NAME)
	rm -rf libft

re: fclean all

test: all

libft/export/libft.a:
	@if [ ! -d "libft" ]; then \
		git clone https://github.com/cliftontoaster-reid/libft libft; \
	fi
	@make -C libft export

.PHONY = all clean fclean re test 