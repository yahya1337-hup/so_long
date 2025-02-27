/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:17:24 by yaboumei          #+#    #+#             */
/*   Updated: 2025/02/26 20:17:26 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_init(t_game **game_info)
{
	(*game_info)->mlx_ptr = mlx_init();
	if ((*game_info)->mlx_ptr == NULL)
	{
		ft_putstr_fd("the fuction mlx_init failed\n", 2);
		free_mem((*game_info)->minfo.map);
		exit(1);
	}
}

void	create_new_window(t_game **info)
{
	(*info)->mlx_wind = mlx_new_window((*info)->mlx_ptr, TILE_SIZE
			* (*info)->whidth, TILE_SIZE * (*info)->height, "so_long");
	if ((*info)->mlx_wind == NULL)
	{
		mlx_destroy_display((*info)->mlx_ptr);
		ft_putstr_fd("the fuction mlx_init filed\n", 2);
		free_mem((*info)->minfo.map);
		exit(1);
	}
}

void	ft_mlx(t_game **game_info)
{
	ft_mlx_init(game_info);
	create_new_window(game_info);
}
