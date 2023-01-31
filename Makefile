NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/

FILES = fdf.c map.c color.c error.c

SRCS = $(addprefix $(SRC_DIR), $(FILES))
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C ./mlx
	$(MAKE) -C ./libft bonus
	mv ./mlx/libmlx.dylib ./libmlx.dylib
	$(CC) $(OBJS) -L./libft -lft -L. -lmlx -framework AppKit -o $(NAME)

test: $(OBJS)
	$(MAKE) -C ./mlx
	mv ./mlx/libmlx.dylib ./libmlx.dylib
	$(CC) -g $(OBJS) -L. -lmlx -framework AppKit -o $(NAME)


clean:
	$(MAKE) -C ./mlx clean
	$(MAKE) -C ./libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME) libmlx.dylib
	
re: fclean all

.phony : all clean fclean re
