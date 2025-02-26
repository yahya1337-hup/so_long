#include "so_long.h"
// #include "get_next_line/get_next_line.c"
// #include "get_next_line/get_next_line_utils.c"
// #include "check.c"
// #include "ft_split.c"
// #include "ft_putstr_fd.c"
// #include "help.c"


int check_line(char *line, st_counters *counters, st_map *map_info)
{
	int i;
	int len;
	if (line == NULL)
		return (FALSE);
	(1) && (i = 0 ,len = ft_strlen(line), map_info->len_next = 0);
	if (line[0] != '1' || line[len - 2] != '1')
			err_map(counters);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != '0')
		{
			if (line[i] == 'P')
				counters->count_p++;
			else if (line[i] == 'C')
				counters->count_c++;
			else if (line[i] == 'E')
				counters->count_e++;
			else
				return (counters->count_err = ERROR);
		}
		map_info->len_next++;
		i++;
	}
	return (check_is_rectangle_map(*map_info));
}

char *get_map(char *line1, char *line2)
{
	if (line1[0] == 0)
	{
		line1 = malloc(sizeof(char));
		line1[0] = 0;
	}
	char *new_line;
	if (line2 == NULL)
		return (NULL);
	new_line = ft_strjoin(line1 ,line2);
	if (new_line == NULL)
		return (NULL);
	free(line1);
	return (new_line);
}

enum t_bool check_err(st_counters counters,st_map map_info, char *line, char **map)
{
	if (counters.count_err == ERROR || counters.count_c < 1)
	{
		ft_putstr_fd("Error\nmap has line not good\n", 2);
		free(line);
		free_get(map_info.fd);
		free(*map);
		return (FALSE);
	}
	if (counters.count_p != 1 || counters.count_e != 1)
	{
		ft_putstr_fd("Error\nThe (E OR P) are duplicate in map\n", 2);
		if (line)
			free(line);
		free_get(map_info.fd);
		free(*map);
		return (FALSE);
	}
	if (!lastly(line, map_info))
	{		
		ft_putstr_fd("last line is not good\n", 2);
		free(*map);
		return (FALSE);
	}
	free(line);
	return (TRUE);
}

void help(char **map, char **line, st_map *map_info)
{
	if (!firstly(map_info->fd, map_info, map))
	{
		ft_putstr_fd("Error\nThe input is't correct\n", 2);
		exit(1);
	}
	map_info->len_height = 1;
	*line = get_next_line(map_info->fd);
	*map = get_map(*map, *line);
	map_info->len_height++;
}

int check_input(st_map *map_info, char **map, st_counters *counters)
{
	char *line;
	char *temp;

	help(map, &line, map_info);
	while (1)
	{
		if (!check_line(line, counters, map_info))
			break ;
		temp = get_next_line(map_info->fd);
		if (temp)
			*map = get_map(*map, temp);
		if (temp == NULL || *map == NULL)
			break;
		map_info->len_height++;
		if (line)	
			free(line);
		line = temp;
	}
	close(map_info->fd);
	return (check_err(*counters, *map_info, line, map));
}


// int main(int ac, char **av)
// {
// 	char *map = NULL;
// 	char **mp = NULL;
// 	int fd = open("a.ber", O_RDONLY);
// 	if (fd == -1)
// 	{ 
// 		printf("function open is failed\n");
// 		return (0);
// 	}
	
// 	st_counters counters = {0,0,0,0};
// 	st_map map_info.fd;
		
// 	if (check_input(&map_info, &map, &counters))
// 	{
// 		mp = ft_split(map, '\n');
// 		printf("the input is correct\n");
// 		free(map);
// 		for (int i = 0; mp[i]; i++)
// 		{
// 				printf("map :\n%s.\n",mp[i]);
// 		}
// 		free_mem(mp);
// 	}
// 	else
// 		printf("the input is't correct\n");
// 	printf("E : %d\n", counters.count_e);
// 	printf("C : %d\n", counters.count_c);
// 	printf("P : %d\n", counters.count_p);

// 	return (0);
// }
