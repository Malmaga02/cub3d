#ifndef CUBED_H
# define CUBED_H

# include <sys/time.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "libft/headers/libft.h"

typedef enum	s_error
{
	MALLOC_E,
	OPEN_E,
	MISSING_EL,
	MISSING_MAP,
	ERROR_MAP
}	t_error;

typedef struct	s_element
{
	char	*texture_nord;
	char	*texture_sud;
	char	*texture_est;
	char	*texture_ovest;
	char	*ceiling;
	char	*floor;
}			t_element;

typedef struct	s_map
{
	char	**map;
	int		rows;
	int		pov_player;
	int		pos_playerX;
	int		pos_playerY;
}			t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}			t_mlx;

typedef struct	s_all
{
	t_element	*info_elements;
	t_map		*map;
	t_mlx		*window;
}				t_all;

// ----Parsing----
	// Get_elements
char		*get_info_element(char *name_file, char *flag);
t_element	*get_elements(char *name_file);
	// Parse_file
t_all		*parse_file(char *name_file);
	// Parse_map
char		*get_map_strings(int fd, int flag);
char		**parse_map(char *name_file);
	// Handling_char
int			check_spaces(char c);
int			outside_walls(char c);
int			empty_line(char *str);
int			is_external_row(char *str);
int			check_not_allowed_char(char **mtx);
	//Parse_utils
char		*get_path_texture(char	*texture, char *flag);
char		**lst_to_mtx(t_list *head);
int			not_closed_map(char **map, int row, int col);
int			spaces_in_map(char **map);

// ----Print----
	// Print_error
	// Print
void		print_mtx(char **mtx);
// ----Start_game----
	// Start_game

#endif