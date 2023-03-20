NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./include/

FILES = color.c error.c fdf.c parser.c util.c 
SRCS = $(addprefix $(SRC_DIR), $(FILES))
OBJS = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))
#OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./mlx
	$(MAKE) -C ./libft
	mv ./mlx/libmlx.dylib ./libmlx.dylib
	$(CC) $(OBJS) -L./libft -lft -L. -lmlx -framework AppKit -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@test -d $(OBJ_DIR) || mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAG) -c $< -o $@

test: $(OBJS)
	$(MAKE) -C ./mlx
	mv ./mlx/libmlx.dylib ./libmlx.dylib
	$(CC) -g $(OBJS) -L. -lmlx -framework AppKit -o $(NAME)

clean:
	$(MAKE) -C ./mlx clean
	$(MAKE) -C ./libft fclean
	rm libmlx.dylib
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY : all clean fclean re
