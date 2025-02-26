#ifndef SO_LONG_H
#define SO_LONG_H


#include <stdio.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
//#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

//#define WIDTH 400
//#define HEIGHT 400
#define TILE_SIZE 32

# define WALL_XPM			"sprites/wall.xpm"
# define FLOOR_XPM			"sprites/floor.xpm"
# define COLL_XPM			"sprites/coin-bag.xpm"
# define FRONT_XPM	"sprites/player/front.xpm"
# define LEFT_XPM	"sprites/player/left.xpm"
# define RIGHT_XPM	"sprites/player/right.xpm"
# define BACK_XPM	"sprites/player/back.xpm"
# define OPEN_EXIT_XPM		"sprites/open-exit.xpm"
# define EXIT_XPM	"sprites/exit-closed.xpm"

typedef enum e_utils  {EXIT = 'E', PLAYER = 'P', COLL = 'C', FLOOR = '0', WALL = '1'} e_utils;
typedef enum player {FRONT , BACK, RIGHT, LEFT} t_playr;
typedef enum KEYS {KEY_E = 119 , KEY_A = 97, KEY_S = 115, KEY_D = 100} t_KEYS;

enum t_bool
{
	TRUE = 1,
	FALSE = 0,
	ERROR = -1
};

typedef struct t_counters
{
	int count_e;
	int count_p;
	int count_c;
	int count_err;

} st_counters;

typedef struct t_map_info
{
	st_counters counters;
	char	*line;
	char	**map;
	int len_next;
	int	len_width;
	int len_height;
	int	x;
	int y;
	int fd;
	
} st_map;

typedef struct s_image
{
	void	*image_ptr;
	int x;
	int y;

}	t_image;

typedef struct t_game
{
	//t_game player;
	void	*mlx_ptr;
	void *mlx_wind;
	st_map	map_info;
	t_playr dire;
	t_image		wall;
	t_image		floor;
	t_image		coll;
	t_image		open_exit;
	t_image		exit_closed;
	t_image		player_front;
	t_image		player_left;
	t_image		player_right;
	t_image		player_back;
	int	whidth;
	int height;

} t_game;

void    err_map(st_counters *counters);
void	print_image_window(t_game game, t_image imag, int x, int y);
int handel_input(int keysym, t_game *game);
int    close_game(t_game *game);
int print_new_window(t_game game, t_playr dire);
void	display(t_game *game);

void ft_mlx(t_game **game_info);

void    xpm_err(t_game *game);
void file_err(char *file);
void    ready_err(char **map);

void	is_ready(char *file, st_map *map_info, st_counters *counters);

void	ft_putstr_fd(char *s, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void find_pos_player(char **map,int *x, int *y);
void	initial_value_stmap(st_map *map_info);
void	initial_value_count(st_counters *counters);
int check_input(st_map *map_info, char **map, st_counters *counters);
void	free_mem(char **arr);
void free_get(int fd);
char	**ft_split(char const *s, char c);
char *get_map(char *line1, char *line2);
enum t_bool firstly(int fd, st_map *map_info, char **map);
enum t_bool lastly(char *line, st_map map_info);
int check_is_rectangle_map(st_map map_info);

#endif
