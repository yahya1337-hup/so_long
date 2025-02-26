#include "so_long.h"
// #include "get_next_line/get_next_line.c"
// #include "get_next_line/get_next_line_utils.c"
// #include "check.c"
// #include "help.c"
// #include "ft_split.c"
// #include "parsing.c"
// #include "ft_strncmp.c"
// #include "ft_strnstr.c"

void find_pos_player(char **map,int *x, int *y)
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

void	flood_fill(st_map *smap, char **temp, int x, int y)
{
	if (smap->map[x][y] == '1' || x < 0 || y < 0 )
		return ;
	if (temp[x][y] == 'V')
		return ;
	if (smap->map[x][y] == 'C')
		smap->counters.count_c++;
	if (smap->map[x][y] == 'E')
		smap->counters.count_e++;
	temp[x][y] = 'V';
		
	flood_fill(smap,temp, x + 1, y);
	flood_fill(smap, temp, x - 1, y);
	flood_fill(smap, temp, x, y + 1);
	flood_fill(smap,temp, x, y - 1);
}

char	**full_visit(st_map map_info)
{
	char	**visited;
	int i;
	int j;

	i = 0;
	visited = malloc((map_info.len_height + 1) * sizeof(char *));
	if (visited == NULL)
		return (NULL);
	while (i < map_info.len_height)
	{
		visited[i] = malloc((map_info.len_width + 1) * sizeof(char));
		if (visited[i] == NULL)
			return (NULL);
		j = 0;
		while (j < map_info.len_width)
			visited[i][j++] = 'F';
		visited[i++][j] = 0;
	}
	visited[i] = NULL;
	return (visited);
}


enum t_bool check_is_ready(char **map,st_counters counters, st_map map_info)
{
	char **visited;

	initial_value_count(&map_info.counters);
	find_pos_player(map, &map_info.x, &map_info.y);
	visited = full_visit(map_info);
	map_info.map = map;
	flood_fill(&map_info, visited, map_info.x, map_info.y);
	free_mem(visited);
	if (counters.count_e == map_info.counters.count_e && map_info.counters.count_c == counters.count_c)
		return (TRUE);
	return (FALSE);
}

int check_file(char *file, st_map *map_info)
{
	char *pos = ft_strnstr(file, ".ber", ft_strlen(file));
	if (pos == NULL)
		return (0);
	if (file == pos)
		return (0);
	if (ft_strncmp(".ber", pos, ft_strlen(pos)))
		return (0);
	map_info->fd = open(file, O_RDONLY);
	if (map_info->fd == -1)
		return (0);
	return (1);
}

void	is_ready(char *file, st_map *map_info, st_counters *counters)
{
	initial_value_count(counters);
	if (!check_file(file, map_info))
		file_err(file);
	if (!check_input(map_info, &map_info->line, counters))
		exit(1);
	close(map_info->fd);
	map_info->map = ft_split(map_info->line, '\n');
	free(map_info->line);
	find_pos_player(map_info->map, &map_info->x, &map_info->y);
	if (check_is_ready(map_info->map, *counters, *map_info) == FALSE)
		ready_err(map_info->map);
}

// int main(int ac, char **av)
// {
// 	if (is_ready("a.ber"))
// 	{
// 		printf("all ok\n");
// 	}
// 	else
// 		printf("not ok\n");
	
	// int fd;
	// st_map map_info;
	// st_counters counters2;
	// initial_value_count(&counters2);
	// st_counters counters;
	// initial_value_count(&counters);
	// map_info.fd = open(".per", O_RDONLY);
	// if (fd == -1)
	// 	return (0);
	
	// if (!check_input(&map_info, &map_info.line, &counters))
	// 	return (0);
	// char **map = ft_split(map_info.line, '\n');
	// int x = 0 , y = 0;
	// find_pos_player(map, &map_info.x, &map_info.y);
	// check_is_ready(map, counters, map_info);

    // char **visited = malloc(map_info.len_height * sizeof(char *));
    // for (int i = 0; i < map_info.len_height; i++) {
    //     visited[i] = malloc(map_info.len_width * sizeof(char));
    //     for (int j = 0; j < map_info.len_width; j++) {
    //         visited[i][j] = 'F';
    //     }
    // }
	// flood_file(map, &counters2, visited, x, y);	
	// if (counters.count_e == counters2.count_e && counters2.count_c == counters.count_c)
	// 	printf("the map is valid\n");
	// else
	// 	printf("the map is not valid\n");
	//printf("x = %d\n", x);
	//printf("y = %d", y);
	
//}


