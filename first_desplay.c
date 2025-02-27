/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_desplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:14:45 by yaboumei          #+#    #+#             */
/*   Updated: 2025/02/26 20:14:48 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	ft_xpm_file_to_imag(void *mlx, char *path, t_game *game)
{
	t_image	info;

	info.image_ptr = mlx_xpm_file_to_image(mlx, path, &info.x, &info.y);
	if (info.image_ptr == NULL)
		xpm_err(game);
	return (info);
}

void	display(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	game->wall = ft_xpm_file_to_imag(mlx, WALL_XPM, game);
	game->floor = ft_xpm_file_to_imag(mlx, FLOOR_XPM, game);
	game->coll = ft_xpm_file_to_imag(mlx, COLL_XPM, game);
	game->player_front = ft_xpm_file_to_imag(mlx, FRONT_XPM, game);
	game->player_left = ft_xpm_file_to_imag(mlx, LEFT_XPM, game);
	game->player_right = ft_xpm_file_to_imag(mlx, RIGHT_XPM, game);
	game->player_back = ft_xpm_file_to_imag(mlx, BACK_XPM, game);
	game->open_exit = ft_xpm_file_to_imag(mlx, OPEN_EXIT_XPM, game);
	game->exit_closed = ft_xpm_file_to_imag(mlx, EXIT_XPM, game);
}
