/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:14:19 by yaboumei          #+#    #+#             */
/*   Updated: 2025/02/26 20:14:22 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_err(char *file)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(" file format not recognized\n", 2);
	exit(1);
}

void	ready_err(char **map)
{
	free_mem(map);
	ft_putstr_fd("this a map is not good\n", 2);
	exit(1);
}

void	xpm_err(t_game *game)
{
	free_mem(game->minfo.map);
	free(game);
	ft_putstr_fd("this xpm file not exist\n", 2);
	exit(1);
}

int	close_game(t_game *game)
{
	free_mem(game->minfo.map);
	mlx_destroy_image(game->mlx_ptr, game->wall.image_ptr);
	mlx_destroy_image(game->mlx_ptr, game->coll.image_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_left.image_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_right.image_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_front.image_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_back.image_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit_closed.image_ptr);
	mlx_destroy_image(game->mlx_ptr, game->open_exit.image_ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.image_ptr);
	mlx_destroy_window(game->mlx_ptr, game->mlx_wind);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
	exit(1);
}

void	err_map(t_map *map, char *line, char *map_)
{
	ft_putstr_fd("Error\nYour map should have '1' in the start and at end\n",
		2);
	free(line);
	free_get(map->fd);
	free(map_);
	exit(1);
}
