NAME = cub3d

CC = cc
INCLUDES = ./libft.plus
CFLAGS = -Wextra -Werror -Wall -g -I$(INCLUDES)  -I. -Imlx
MLX_INCLUDE = -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz
AR = ar rc $(NAME)
RM = rm -f

RESET = $(shell tput sgr0)
BOLD_TEXT = $(shell tput bold)
ITALIC_TEXT = $(shell tput sitm)
COLOUR_BLUE = \033[0;34m
COLOUR_GREEN = \033[0;32m

LIBFT_MAKE = ./libft.plus
MLX_MAKE = ./mlx

SRC = ./algo/calculations.c \
	./algo/raycast.c \
	./game/event.c \
	./game/minimap.c \
	./game/movement.c \
	./game/rotation.c \
	./game/start_game.c \
	./main.c \
	./parsing/get_elements.c \
	./parsing/get_map.c \
	./parsing/get_player.c \
	./parsing/init_all.c \
	./parsing/playability.c \
	./parsing/utils.c \
	./print/print_error.c \
	./utils/drawing.c \
	./utils/free.c \
	./utils/player_struct.c


all: $(NAME)

$(NAME): $(SRC) 
	@make all -s -C $(LIBFT_MAKE)
	$(CC) $(CFLAGS) $(SRC) -L$(LIBFT_MAKE) -lft $(MLX_INCLUDE) -o $(NAME)
	@echo "$(COLOUR_BLUE) $(BOLD_TEXT) Run ./cub3d to start the game. $(RESET)";

clean:
	@make clean -s -C $(LIBFT_MAKE)

fclean: clean
	@make fclean -s -C $(LIBFT_MAKE)
	@$(RM) $(NAME)

re: fclean all

# .SILENT:
.PHONY: all clean fclean re