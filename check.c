/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:13:41 by yaboumei          #+#    #+#             */
/*   Updated: 2025/02/26 20:14:00 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_get(int fd)
{
	char	*buffer;

	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		free(buffer);
	}
}

int	check_is_rectangle_map(t_map map_info)
{
	return (map_info.len_width == map_info.len_next);
}

enum t_bool	firstly(int fd, t_map *map_info, char **map)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return (FALSE);
	map_info->len_width = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i++] != '1')
		{
			free(line);
			free_get(fd);
			return (FALSE);
		}
		map_info->len_width++;
	}
	*map = get_map("", line);
	free(line);
	return (TRUE);
}

enum t_bool	lastly(char *line, t_map map_info)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i++] != '1')
		{
			free(line);
			return (FALSE);
		}
	}
	if (!check_is_rectangle_map(map_info))
	{
		free(line);
		return (FALSE);
	}
	return (TRUE);
}
