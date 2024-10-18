NAME = libft.a
CC = cc
HEADERS = ./headers
CFLAGS = -Wall -Wextra -Werror -I$(HEADERS)
COMPILE = $(CC) $(CFLAGS) -c
AR = ar rc $(NAME)
RM = rm -f

RESET = $(shell tput sgr0)
BOLD_TEXT = $(shell tput bold)
ITALIC_TEXT = $(shell tput sitm)
COLOUR_BLUE = \033[0;34m
COLOUR_GREEN = \033[0;32m

ALLOC_STR = ./allocating_strings
CHAR_CHECK = ./char_check
CONVERSIONS = ./conversions
LIST_HANDLE = ./list_handling
MEM_HANDLE = ./memory_handling
PRINT_FUNCTS = ./printing_functions
STR_HANDLE = ./string_handling
WORK_FILES = ./working_with_files

SRC = ./allocating_strings/ft_calloc.c \
		./allocating_strings/ft_freejoin.c \
		./allocating_strings/ft_get_substr.c \
		./allocating_strings/ft_strdup.c \
		./allocating_strings/ft_strjoin.c \
		./allocating_strings/ft_strlcat.c \
		./allocating_strings/ft_strlcpy.c \
		./allocating_strings/ft_strtrim.c \
		./allocating_strings/ft_substr.c \
		./char_check/ft_isalnum.c \
 		./char_check/ft_isalpha.c \
		./char_check/ft_isascii.c \
		./char_check/ft_isdigit.c \
		./char_check/ft_isprint.c \
		./char_check/ft_tolower.c \
		./char_check/ft_toupper.c \
		./conversions/ft_atoi.c \
		./conversions/ft_atol.c \
		./conversions/ft_itoa.c \
		./ft_printf/ft_printf.c \
		./ft_printf/ft_format.c \
		./ft_printf/ft_putchar.c \
		./ft_printf/ft_puthex.c \
		./ft_printf/ft_putmemory.c \
		./ft_printf/ft_putnbr_b.c \
		./ft_printf/ft_putnbr.c \
		./ft_printf/ft_putstr.c \
		./working_with_files/get_next_line.c \
		./list_handling/linked_list/ft_lstadd_back.c \
		./list_handling/linked_list/ft_lstadd_front.c \
		./list_handling/linked_list/ft_lstclear.c \
		./list_handling/linked_list/ft_lstdelone.c \
		./list_handling/linked_list/ft_lstiter.c \
		./list_handling/linked_list/ft_lstlast.c \
		./list_handling/linked_list/ft_lstmap.c \
		./list_handling/linked_list/ft_lstnew.c \
		./list_handling/linked_list/ft_lstsize.c \
		./list_handling/d_linked_list/dll_add_back.c \
		./list_handling/d_linked_list/dll_add_front.c \
		./list_handling/d_linked_list/dll_clear.c \
		./list_handling/d_linked_list/dll_handling.c \
		./list_handling/d_linked_list/dll_iterate.c \
		./list_handling/d_linked_list/dll_last.c \
		./list_handling/d_linked_list/dll_new.c \
		./list_handling/d_linked_list/dll_set_index.c \
		./list_handling/d_linked_list/dll_size.c \
		./memory_handling/ft_memchr.c \
		./memory_handling/ft_memcmp.c \
		./memory_handling/ft_memcpy.c \
		./memory_handling/ft_memmove.c \
		./memory_handling/ft_memset.c \
		./mtx_handling/free_mtx.c \
		./mtx_handling/count_rows.c \
		./mtx_handling/ft_mtxdup.c \
		./printing_functions/ft_putchar_fd.c \
		./printing_functions/ft_putendl_fd.c \
		./printing_functions/ft_putnbr_fd.c \
		./printing_functions/ft_putstr_fd.c \
		./string_handling/ft_bzero.c \
		./string_handling/ft_get_newline.c \
		./string_handling/ft_lencmp.c \
		./string_handling/ft_split.c \
		./string_handling/ft_strchr.c \
		./string_handling/ft_striteri.c \
		./string_handling/ft_strlen_chr.c \
		./string_handling/ft_strlen.c \
		./string_handling/ft_strmapi.c \
		./string_handling/ft_strncmp.c \
		./string_handling/ft_strnstr.c \
		./string_handling/ft_strrchr.c 


OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(OBJ)
	@echo "	$(COLOUR_BLUE) $(BOLD_TEXT) Guess what?! You did it! $(RESET)"

clean:
	@$(RM) $(OBJ)
	@echo "	$(COLOUR_BLUE) $(BOLD_TEXT) You're losing some stuff. Be careful! $(RESET)"
	@echo "			$(COLOUR_GREEN) $(ITALIC_TEXT) $(BOLD_TEXT) Or don't, whatever... (Even though you should, you slacker!) $(RESET)"

fclean: clean
	@$(RM) */**/*.o
	@$(RM) $(NAME)
	@echo "	$(COLOUR_BLUE) $(BOLD_TEXT) You destroyed EVERYTHING! $(RESET)"
	@echo "			$(COLOUR_GREEN) $(ITALIC_TEXT) $(BOLD_TEXT) Told ya... $(RESET)"

re: fclean all

# .SILENT:
.SILENT:
