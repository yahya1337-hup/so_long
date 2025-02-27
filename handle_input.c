/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:17:15 by yaboumei          #+#    #+#             */
/*   Updated: 2025/02/26 20:17:17 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_player(t_game game, int x, int y, t_playr dire)
{
	if (dire == FRONT)
		print_image_window(game, game.player_back, x, y);
	if (dire == BACK)
		print_image_window(game, game.player_front, x, y);
	if (dire == RIGHT)
		print_image_window(game, game.player_right, x, y);
	if (dire == LEFT)
		print_image_window(game, game.player_left, x, y);
}

void	handle(t_game *info, int x, int y, t_playr dir)
{
	int	x_;
	int	y_;

	(1) && (x_ = info->minfo.x, y_ = info->minfo.y);
	if (info->minfo.map[x][y] == EXIT && info->minfo.counters.count_c == 0)
		close_game(info);
	if (info->minfo.map[x_][y_] == PLAYER || info->minfo.map[x][y] == COLL)
	{
		if (info->minfo.map[x][y] == COLL)
			info->minfo.counters.count_c--;
		if (info->minfo.map[x][y] != WALL)
		{
			if (info->minfo.map[x][y] != EXIT)
				swich_p_f(info, dir, x, y);
			else
				swich_p_e(info, dir, x, y);
		}
	}
}

void	print_utils(t_game game, int x, int y, t_playr dire)
{
	if (game.minfo.map[x][y] == WALL)
		print_image_window(game, game.wall, x, y);
	else if (game.minfo.map[x][y] == FLOOR)
		print_image_window(game, game.floor, x, y);
	else if (game.minfo.map[x][y] == COLL)
		print_image_window(game, game.coll, x, y);
	else if (game.minfo.map[x][y] == EXIT)
	{
		if (game.minfo.counters.count_c == 0)
			print_image_window(game, game.open_exit, x, y);
		else
			print_image_window(game, game.exit_closed, x, y);
	}
	else if (game.minfo.map[x][y] == PLAYER)
		print_player(game, x, y, dire);
}

int	print_new_window(t_game game, t_playr dire)
{
	int	x;
	int	y;

	x = 0;
	while (x < game.minfo.len_height)
	{
		y = 0;
		while (y < game.minfo.len_width)
		{
			print_utils(game, x, y, dire);
			y++;
		}
		x++;
	}
	return (0);
}

int	handel_input(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		close_game(game);
		exit(1);
	}
	if (keycode == XK_Left || keycode == XK_a)
		handle(game, game->minfo.x, game->minfo.y - 1, LEFT);
	else if (keycode == XK_Right || keycode == XK_d)
		handle(game, game->minfo.x, game->minfo.y + 1, RIGHT);
	else if (keycode == XK_Up || keycode == XK_w)
		handle(game, game->minfo.x - 1, game->minfo.y, FRONT);
	else if (keycode == XK_Down || keycode == XK_s)
		handle(game, game->minfo.x + 1, game->minfo.y, BACK);
	return (0);
}
