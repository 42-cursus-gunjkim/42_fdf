NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./include/

FILES = color.c exit.c fdf.c parser.c line.c mlx_utils.c graphics.c hook.c
SRCS = $(addprefix $(SRC_DIR), $(FILES))
OBJS = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

$(NAME): $(OBJS)
	$(MAKE) -C ./mlx
	$(MAKE) -C ./libft
	mv ./mlx/libmlx.dylib ./libmlx.dylib
	$(CC) $(OBJS) -L./libft -lft -L. -lmlx -framework AppKit -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@test -d $(OBJ_DIR) || mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAG) -c $< -o $@

test: fclean
	$(MAKE) -C ./mlx
	$(MAKE) -C ./libft
	mv ./mlx/libmlx.dylib ./libmlx.dylib
	$(CC) -g $(SRCS) -L./libft -lft -L. -lmlx -framework AppKit -o $(NAME)

clean:
	$(MAKE) -C ./mlx clean
	$(MAKE) -C ./libft fclean
	rm -rf $(NAME).dSYM
	rm -rf libmlx.dylib
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY : all clean fclean re
