#ifndef CUB3D_H
# define CUB3D_H

# include <sys/time.h>
# include "mlx.h"
# include "mlx_int.h"
# include <X11/Xlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include "libft.plus/includes/libft.h"

# define PI 3.14159265358979323846
# define SCREEN_W 720
# define SCREEN_H 1080
# define ROT 0.050
# define PLAYER_SPEED 0.001

# define MINIMAP_TILE 25

typedef enum	s_color
{
	RED = 0x00ff0000,
	GREEN = 0x0000ff00,
	BLUE = 0x000000ff,
	WHITE = 0x00ffffff,
	BLACK = 0x00000000,
	GREY = 0x00a9a9a9
}	t_color;

typedef enum	s_error
{
	ARG_ERROR,
	MALLOC_E,
	OPEN_E,
	MISSING_EL,
	MISSING_MAP,
	ERROR_MAP,
	OPEN_MAP,
	INCORRECT_CHAR,
	NO_PLAYER,
	MULTIPLE_PLAYER,
	NOT_PLAYABLE
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
}			t_map;

typedef struct s_event
{
	bool	walk_forw;
	bool	walk_back;
	bool	walk_left;
	bool	walk_right;
	bool	show_minimap;
	bool	rotate_left;
	bool	rotate_right;
}			t_event;

typedef struct s_point
{
	double		x;
	double		y;
}			t_point;

typedef struct	s_player
{
	t_point		pos;
	t_point		dir;
	t_point		plane;
	double		angle;
}			t_player;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_img		*frame;
}			t_mlx;

typedef struct	s_all
{
	double		time;
	double		old_time;
	t_element	info_elements;
	t_event		event;
	t_map		map;
	t_mlx		window;
	t_player	player;
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
	// Get_player
t_player	set_pos_angle(int x, int y, int pov, t_player player);
t_player	set_info_player(int x, int y, int pov, t_player player);
	// Init_all
t_player	get_player_info(t_map *map);
t_map		get_map_info(char *map_file);
bool		init_all(t_all *all_info, char *name_file);
	// Playability
bool		correct_char_set(char **map);
bool		is_surrounded(char **map, int row, int col);
bool		closed_map(char **map);
bool		is_map_playable(char **map);
	// Utils
bool		is_char_set(int c);
bool		extern_char(int c);
bool		is_inside_row(int row, int total_row);
bool		is_inside_col(int col, int len);
bool		is_player(int c);
// ----Print----
	// Print_error
void		error(int flag);
// ----Game----
int			game_loop(t_all *pAll);
void		start_game(t_all *pAll);
	// Events
int			on_key_press(int key, t_all *ptr);
int			on_key_release(int key, t_all *ptr);
	// Movement
int			rotate_player(t_all *cubed);
int			rot_action(t_all *cubed, int old_dirx, int old_planex, double rot);
bool		is_new_x_valid(t_all *cubed, double new_x);
bool		is_new_y_valid(t_all *cubed, double new_y);
void		get_new_position(t_all *cubed, double *new_x, double *new_y);
int			move_player(t_all *cubed);
	// Minimap
void		draw_minimap(t_all *ptr);
// ----Utils----
	// Free
void		free_element(t_element *pElement);
void		free_map(t_map *pMap);
int			quit_game(t_all *pAll);

	// Drawing
void		draw_pixel(t_all *data, int x, int y, int color);
void		draw_rectangle(t_all *pAll, t_point start, t_point end, int color);

#endif