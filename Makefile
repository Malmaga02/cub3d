NAME = cub3d

CC = cc
INCLUDES = ./libft
CFLAGS = -Wextra -Werror -Wall -g -I$(INCLUDES)
MLX_INCLUDE = -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz
AR = ar rc $(NAME)
RM = rm -f

RESET = $(shell tput sgr0)
BOLD_TEXT = $(shell tput bold)
ITALIC_TEXT = $(shell tput sitm)
COLOUR_BLUE = \033[0;34m
COLOUR_GREEN = \033[0;32m

LIBFT_MAKE = ./libft
MLX_MAKE = ./mlx

SRC = ./main.c \
	./parsing/get_elements.c \
	./parsing/get_map.c \
	./parsing/get_player_info.c \
	./parsing/get_t_map.c \
	./parsing/is_map_playable.c \
	./parsing/parse_file.c \
	./parsing/parse_utils.c \
	./print/print_error.c \
	./print/print.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	@make all -s -C $(LIBFT_MAKE)
	$(CC) $(CFLAGS) -I. $(OBJ) -L$(LIBFT_MAKE) -lft -o $(NAME)
	@echo "$(COLOUR_BLUE) $(BOLD_TEXT) Run ./cub3d to start the game. $(RESET)";

clean:
	@make clean -s -C $(LIBFT_MAKE)
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -s -C $(LIBFT_MAKE)
	@$(RM) $(NAME)

re: fclean all



# .SILENT:
.PHONY: all clean fclean re