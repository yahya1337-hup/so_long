#include "so_long.h"

void print_player(t_game game, int x, int y, t_playr dire)
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

void handle(t_game *info, int x, int y, t_playr dir)
{
    int x_;
    int y_;

    x_ = info->map_info.x;
    y_ = info->map_info.y;
    if (info->map_info.map[x][y] == EXIT && info->map_info.counters.count_c == 0)
    {
        ft_putstr_fd("game over\n", 1);
        close_game(info);
    }
    if (info->map_info.map[x_][y_] == PLAYER || info->map_info.map[x][y] == COLL)
    {
        printf("coll : %d\n", info->map_info.counters.count_c);

        if (info->map_info.map[x][y] == COLL)
            info->map_info.counters.count_c--;
        if (info->map_info.map[x][y] != WALL)
        {
            if (info->map_info.map[x][y] != EXIT || !info->map_info.counters.count_c)
            {
                info->map_info.x = x;
                info->map_info.y = y;
                info->map_info.map[x_][y_] = FLOOR;
                info->map_info.map[x][y] = PLAYER;
            }
            print_new_window(*info, dir);
        }
    }
}

void print_utils(t_game game, int x, int y, t_playr dire)
{
    if (game.map_info.map[x][y] == WALL)
        print_image_window(game, game.wall, x, y);
    else if (game.map_info.map[x][y] == FLOOR)
        print_image_window(game, game.floor, x, y);
    else if (game.map_info.map[x][y] == COLL)
        print_image_window(game, game.coll, x, y);
    else if (game.map_info.map[x][y] == EXIT)
    {
        if (game.map_info.counters.count_c == 0)
            print_image_window(game, game.open_exit, x, y);
        else
            print_image_window(game, game.exit_closed, x, y);
    }
    else if (game.map_info.map[x][y] == PLAYER)
        print_player(game, x, y, dire);
}

int print_new_window(t_game game, t_playr dire)
{
    int x;
    int y;

    x = 0;
    while (x < game.map_info.len_height)
    {
        y = 0;
        while (y < game.map_info.len_width)
        {
            print_utils(game, x, y, dire);
            y++;
        }
        x++;
    }
    return (0);
}

int handel_input(int keycode, t_game *game)
{
    printf("Key Pressed: %d\n", keycode);
    if (keycode == XK_Escape)
    {
        printf("The %d key (Esc) has been prossed\n", keycode);
        close_game(game);
        exit(1);
    }
    else if (keycode == XK_Left || keycode == XK_a) // Move Left
    {
        printf("Moving Left\n");
        handle(game, game->map_info.x, game->map_info.y - 1, LEFT);
    }
    else if (keycode == XK_Right || keycode == XK_d) // Move Right
    {
        printf("Moving Right\n");
        handle(game, game->map_info.x, game->map_info.y + 1, RIGHT);
    }
    else if (keycode == XK_Up || keycode == XK_w) // Move Up
    {
        printf("Moving Up\n");
        handle(game, game->map_info.x - 1, game->map_info.y, FRONT);
    }
    else if (keycode == XK_Down || keycode == XK_s) // Move Down
    {
        printf("Moving Down\n");
        handle(game, game->map_info.x + 1, game->map_info.y, BACK);
    }

    return (0);
}
