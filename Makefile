# -*- Makefile -*-
CC = clang

CFLAGS = -Wall -Werror -Wextra -g

SOURCES = so_long.c hooks.c pixel_management.c read_map.c \
gnl/get_next_line.c gnl/get_next_line_utils.c draw_map.c check_map.c \
check_map_utils.c animations.c so_long_utils.c \

REG_OBJFILES = $(SOURCES:.c=.o)

NAME = so_long

LIBFT = ./libft/libft.a

MLX = ./mlx/libmlx.a

# -*- colors -*-
GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[1;33m
NO_COLOR=\033[0m

all: $(NAME) 
	@echo "${GREEN}Done making all files:)${NO_COLOR}"

$(LIBFT):
	$(MAKE) -C ./libft

$(MLX):
	@$(MAKE) -C ./mlx

$(NAME): $(REG_OBJFILES) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(REG_OBJFILES) $(LIBFT) $(MLX) -Lmlx -Lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Imlx -c $< -o $@
	  
clean: 
	@make clean -C ./mlx
	@make clean -C ./libft
	@rm -f $(REG_OBJFILES)

fclean: clean
	 @rm -f $(MLX)
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	@echo "${GREEN}Everything clean!${NO_COLOR}"

re: fclean all

.PHONY: all clean fclean re