/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:50:29 by yaboumei          #+#    #+#             */
/*   Updated: 2025/02/27 13:50:37 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_pos(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	swich_p_f(t_game *info, t_playr dir, int x, int y)
{
	int	x_;
	int	y_;

	x_ = info->minfo.x;
	y_ = info->minfo.y;
	ft_putnbr(++info->mouves);
	ft_putstr_fd("\n", 1);
	info->minfo.x = x;
	info->minfo.y = y;
	info->minfo.map[x_][y_] = FLOOR;
	info->minfo.map[x][y] = PLAYER;
	info->minfo.map[info->x_exit][info->y_exit] = 'E';
	print_new_window(*info, dir);
}

void	swich_p_e(t_game *info, t_playr dir, int x, int y)
{
	int	x_;
	int	y_;

	x_ = info->minfo.x;
	y_ = info->minfo.y;
	ft_putnbr(++info->mouves);
	ft_putstr_fd("\n", 1);
	info->minfo.x = x;
	info->minfo.y = y;
	info->minfo.map[x_][y_] = FLOOR;
	info->minfo.map[x][y] = PLAYER;
	print_new_window(*info, dir);
}

void	find_pos_player(char **map, int *x, int *y)
{
	(*x) = 0;
	while (map[*x])
	{
		(*y) = 0;
		while (map[*x][*y])
		{
			if (map[*x][*y] == 'P')
				return ;
			(*y)++;
		}
		(*x)++;
	}
}
