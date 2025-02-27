/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:17:46 by yaboumei          #+#    #+#             */
/*   Updated: 2025/02/26 20:17:48 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *smap, char **temp, int x, int y)
{
	if (smap->map[x][y] == '1' || x < 0 || y < 0)
		return ;
	if (temp[x][y] == 'V')
		return ;
	if (smap->map[x][y] == 'C')
		smap->counters.count_c++;
	if (smap->map[x][y] == 'E')
		smap->counters.count_e++;
	temp[x][y] = 'V';
	flood_fill(smap, temp, x + 1, y);
	flood_fill(smap, temp, x - 1, y);
	flood_fill(smap, temp, x, y + 1);
	flood_fill(smap, temp, x, y - 1);
}

char	**full_visit(t_map map_info)
{
	char	**visited;
	int		i;
	int		j;

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

enum t_bool	check_is_ready(char **map, t_counters counters, t_map map_info)
{
	char	**visited;

	initial_value_count(&map_info.counters);
	find_pos_player(map, &map_info.x, &map_info.y);
	visited = full_visit(map_info);
	map_info.map = map;
	flood_fill(&map_info, visited, map_info.x, map_info.y);
	free_mem(visited);
	if (counters.count_e == map_info.counters.count_e
		&& map_info.counters.count_c == counters.count_c)
		return (TRUE);
	return (FALSE);
}

int	check_file(char *file, t_map *map_info)
{
	char	*pos;

	pos = ft_strnstr(file, ".ber", ft_strlen(file));
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

void	is_ready(char *file, t_map *map_info, t_counters *counters)
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
