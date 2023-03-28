NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/
SRC_BONUS_DIR = ./src_bonus/
OBJ_DIR = ./obj/
INC_DIR = include/
INC_BONUS_DIR = include_bonus/

FILES = color.c exit.c fdf.c parser.c line.c mlx_utils.c graphics.c hook.c
BONUS_FILES = color_bonus.c exit_bonus.c fdf_bonus.c graphics_bonus.c hook_bonus.c \
				line_bonus.c mlx_utils_bonus.c parser_bonus.c
SRCS = $(addprefix $(SRC_DIR), $(FILES))
BONUS_SRCS = $(addprefix $(SRC_BONUS_DIR), $(BONUS_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))
BONUS_OBJS = $(addprefix $(OBJ_DIR), $(BONUS_FILES:.c=.o))

all: $(NAME)

$(NAME): make_mandatory

bonus: make_bonus

make_mandatory: $(OBJS)
	$(MAKE) -C ./mlx
	$(MAKE) -C ./libft
	@test -e libmlx.dylib || mv ./mlx/libmlx.dylib ./libmlx.dylib
	$(CC) $(OBJS) -L./libft -lft -L. -lmlx -framework AppKit -o $(NAME) -I$(INC_DIR)
	touch $@

make_bonus: $(BONUS_OBJS)
	$(MAKE) -C ./mlx
	$(MAKE) -C ./libft
	@test -e libmlx.dylib || mv ./mlx/libmlx.dylib ./libmlx.dylib
	$(CC) $(BONUS_OBJS) -L./libft -lft -L. -lmlx -framework AppKit -o $(NAME) -I$(INC_BONUS_DIR)
	touch $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@test -d $(OBJ_DIR) || mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAG) -c $< -o $@ -I$(INC_DIR)

$(OBJ_DIR)%.o : $(SRC_BONUS_DIR)%.c
	@test -d $(OBJ_DIR) || mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAG) -c $< -o $@ -I$(INC_BONUS_DIR)

test: fclean
	$(MAKE) -C ./mlx
	$(MAKE) -C ./libft
	@test -e libmlx.dylib || mv ./mlx/libmlx.dylib ./libmlx.dylib
	$(CC) -g $(SRCS) -L./libft -lft -L. -lmlx -framework AppKit -o $(NAME)

clean:
	$(MAKE) -C ./mlx clean
	$(MAKE) -C ./libft fclean
	rm -rf $(NAME).dSYM
	rm -rf libmlx.dylib
	rm -rf $(OBJ_DIR)
	rm -f make_mandatory
	rm -f make_bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
