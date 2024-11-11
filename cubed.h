#ifndef CUBED_H
# define CUBED_H

# include <sys/time.h>
# include "mlx.h"
# include "mlx_int.h"
# include <X11/Xlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include "libft/headers/libft.h"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_ESC 65307

# define SCREEN_W 720
# define SCREEN_H 1080

typedef enum	s_error
{
	MALLOC_E,
	OPEN_E,
	MISSING_EL,
	MISSING_MAP,
	ERROR_MAP,
	OPEN_MAP
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

typedef struct	s_player
{
	double		dir_playerX;
	double		dir_playerY;
	double		plane_x;
	double		plane_y;
}			t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}			t_mlx;

typedef struct	s_all
{
	double		time;
	double		old_time;
	t_element	info_elements;
	t_map		map;
	t_mlx		window;
	t_player	*player;
}				t_all;

// ----Parsing----
	// Get_elements
char		*get_path_texture(char	*texture, char *flag);
char		*get_info_element(char *name_file, char *flag);
t_element	get_elements(char *name_file);
	// Get_map
bool		empty_line(char *str);
bool		is_external_row(char *str);
char		**lst_to_mtx(t_list *head);
char		*get_map_rows(int fd, int flag);
char		**get_map(char *name_file);
	// Get_player_info
t_map		get_player_info(t_map map);
	// Get_t_map
t_map		get_t_map(char *map_file);
	// Is_map_playable
bool		correct_char_set(char **map);
bool		is_surrounded(char **map, int row, int col);
bool		closed_map(char **map);
bool		is_map_playable(char **map);
	// Parse_file
t_all		*parse_file(char *name_file);
	// Parse_utils
bool		check_spaces(int c);
bool		extern_char(int c);
bool		is_inside_row(int row, int total_row);
bool		is_inside_col(int col, int len);
bool		is_player(int c);
// ----Print----
	// Print_error
void		error(int flag);
	// Print
void		print_mtx(char **mtx);
// ----Start_game----
void	start_game(t_mlx *pMlx);

#endif