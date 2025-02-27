/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:18:03 by yaboumei          #+#    #+#             */
/*   Updated: 2025/02/26 20:18:05 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/usr/include/minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include <X11/keysym.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

# define TILE_SIZE 32

# define WALL_XPM "sprites/wall.xpm"
# define FLOOR_XPM "sprites/floor.xpm"
# define COLL_XPM "sprites/coin-bag.xpm"
# define FRONT_XPM "sprites/player/front.xpm"
# define LEFT_XPM "sprites/player/left.xpm"
# define RIGHT_XPM "sprites/player/right.xpm"
# define BACK_XPM "sprites/player/back.xpm"
# define OPEN_EXIT_XPM "sprites/open-exit.xpm"
# define EXIT_XPM "sprites/exit-closed.xpm"

typedef enum e_utils
{
	EXIT = 'E',
	PLAYER = 'P',
	COLL = 'C',
	FLOOR = '0',
	WALL = '1'
}				t_utils;
typedef enum t_player
{
	FRONT,
	BACK,
	RIGHT,
	LEFT
}				t_playr;
typedef enum KEYS
{
	KEY_E = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100
}				t_KEYS;

typedef enum t_bool
{
	TRUE = 1,
	FALSE = 0,
	ERROR = -1
}				t_bool;

typedef struct t_counters
{
	int			count_e;
	int			count_p;
	int			count_c;
	int			count_err;

}				t_counters;

typedef struct tmap_info
{
	t_counters	counters;
	char		*line;
	char		**map;
	int			len_next;
	int			len_width;
	int			len_height;
	int			x;
	int			y;
	int			fd;

}				t_map;

typedef struct t_image
{
	void		*image_ptr;
	int			x;
	int			y;

}				t_image;

typedef struct t_game
{
	void		*mlx_ptr;
	void		*mlx_wind;
	t_map		minfo;
	t_playr		dire;
	t_image		wall;
	t_image		floor;
	t_image		coll;
	t_image		open_exit;
	t_image		exit_closed;
	t_image		player_front;
	t_image		player_left;
	t_image		player_right;
	t_image		player_back;
	int			whidth;
	int			height;
	int			mouves;
	int			x_exit;
	int			y_exit;

}				t_game;

void			exit_pos(char **map, int *x, int *y);
void			ft_putnbr(int n);
void			err_map(t_map *map, char *line, char *map_);
void			print_image_window(t_game game, t_image imag, int x, int y);
int				handel_input(int keysym, t_game *game);
int				close_game(t_game *game);
int				print_new_window(t_game game, t_playr dire);
void			display(t_game *game);

void			swich_p_e(t_game *info, t_playr dir, int x, int y);
void			swich_p_f(t_game *info, t_playr dir, int x, int y);
void			ft_mlx(t_game **game_info);

void			xpm_err(t_game *game);
void			file_err(char *file);
void			ready_err(char **map);

void			is_ready(char *file, t_map *map_info, t_counters *counters);

void			ft_putstr_fd(char *s, int fd);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
void			find_pos_player(char **map, int *x, int *y);
void			initial_value_stmap(t_map *map_info);
void			initial_value_count(t_counters *counters);
int				check_line(char *line, t_counters *counters, t_map *map_info,
					char **map);
int				check_input(t_map *map_info, char **map, t_counters *counters);
void			free_mem(char **arr);
void			free_get(int fd);
char			**ft_split(char const *s, char c);
char			*get_map(char *line1, char *line2);
enum t_bool		firstly(int fd, t_map *map_info, char **map);
enum t_bool		lastly(char *line, t_map map_info);
int				check_is_rectangle_map(t_map map_info);

#endif
