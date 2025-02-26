#include "so_long.h"


void play(char *av)
{
    st_counters counters;
    st_map map_info;
    t_game *game;

    is_ready(av, &map_info, &counters);
    game = malloc(sizeof(t_game));
    game->map_info.x = map_info.x;
    game->map_info.y = map_info.y;
    game->map_info.counters.count_c = counters.count_c;
    game->map_info.map = map_info.map;
    game->map_info.len_height = map_info.len_height;
    game->map_info.len_width = map_info.len_width;
    game->height = map_info.len_height;
    game->whidth = map_info.len_width;
    ft_mlx(&game);
    display(game);
    print_new_window(*game, RIGHT);
    mlx_hook(game->mlx_wind, 2, 1L, handel_input, game);
    mlx_hook(game->mlx_wind, 17, 1L<<2 , close_game, game);
    mlx_hook(game->mlx_wind, 12, 1L<<15, print_new_window, game);
    mlx_loop(game->mlx_ptr);
    mlx_destroy_display(game->mlx_ptr);
    mlx_destroy_window(game->mlx_ptr, game->mlx_wind);

}

int main(int ac, char **av)
{
    if (ac == 2)
	    play(av[1]);
    return (0);
}

