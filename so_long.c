/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:17:06 by yaboumei          #+#    #+#             */
/*   Updated: 2025/02/26 20:17:08 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	play(char *av)
{
	t_counters	counters;
	t_map		minfo;
	t_game		*game;

	is_ready(av, &minfo, &counters);
	game = malloc(sizeof(t_game));
	game->minfo.x = minfo.x;
	game->minfo.y = minfo.y;
	game->minfo.counters.count_c = counters.count_c;
	game->minfo.map = minfo.map;
	game->minfo.len_height = minfo.len_height;
	game->minfo.len_width = minfo.len_width;
	game->height = minfo.len_height;
	game->whidth = minfo.len_width;
	game->mouves = 0;
	exit_pos(game->minfo.map, &game->x_exit, &game->y_exit);
	ft_mlx(&game);
	display(game);
	print_new_window(*game, RIGHT);
	mlx_hook(game->mlx_wind, 2, 1L, handel_input, game);
	mlx_hook(game->mlx_wind, 17, 1L << 2, close_game, game);
	mlx_loop(game->mlx_ptr);
	mlx_destroy_display(game->mlx_ptr);
	mlx_destroy_window(game->mlx_ptr, game->mlx_wind);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		play(av[1]);
	return (0);
}
