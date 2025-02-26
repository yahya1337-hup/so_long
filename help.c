#include "so_long.h"

void	free_mem(char **arr)
{
	int i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr); 
	arr = NULL;
}

void	initial_value_count(st_counters *counters)
{
	counters->count_c = 0;
	counters->count_e = 0;
	counters->count_err = 0;
	counters->count_p = 0;
}

void	initial_value_stmap(st_map *map_info)
{
	map_info->line = NULL;
	map_info->len_next = 0;
	map_info->len_width = 0;
	map_info->len_height = 0;
	find_pos_player(map_info->map, &map_info->x, &map_info->y);
}

void	print_image_window(t_game game, t_image imag, int x, int y)
{
	mlx_put_image_to_window(game.mlx_ptr, game.mlx_wind, 
	imag.image_ptr, y * imag.y, x * imag.x );
}


