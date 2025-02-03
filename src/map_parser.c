/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:24:58 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/03 17:55:53 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	parse_row(int fd, t_map *map, char **tab, int i)
{
	t_point3d	*point;
	int			x_offset;
	int			y_offset;
	int			j;

	j = -1;
	while (++j < map->cols)
	{
		if (!ft_isdigit(*tab[j]) && *tab[j] != '-')
			abort_map(fd, map, INVALID_MAP);
		point = &(map->grid3d[i][j]);
		x_offset = (map->cols - 1) * map->interval / 2;
		y_offset = (map->rows - 1) * map->interval / 2;
		point->x = (double)j * (map->interval) - x_offset;
		point->y = (double)i * (map->interval) - y_offset;
		point->z = (double)ft_atoi(tab[j]) * (map->interval);
		map->max_height = ft_max(map->max_height, point->z);
		map->min_height = ft_min(map->min_height, point->z);
		point->mapcolor = 0xFFFFFFFF;
	}
}

void	map_parser(int fd, t_map *map)
{
	char	*line;
	char	*temp;
	char	**tab;
	int		i;

	i = -1;
	while (++i < map->rows)
	{
		temp = get_next_line(fd);
		if (!temp)
			abort_map(fd, map, "Malloc fail");
		line = ft_strtrim(temp, "\n");
		free(temp);
		if (!line)
			abort_map(fd, map, "Malloc fail");
		tab = ft_split(line, ' ');
		free(line);
		if (!tab)
			abort_map(fd, map, "Malloc fail");
		parse_row(fd, map, tab, i);
		free_array((void **)tab, map->cols);
	}
}

static int	get_cols(int fd, t_map *map, char *line)
{
	char	**tab;
	char	*temp;
	int		i;

	temp = ft_strtrim(line, "\n");
	free(line);
	if (!temp)
		abort_map(fd, map, "Malloc fail");
	tab = ft_split(temp, ' ');
	free(temp);
	if (!tab)
		abort_map(fd, map, "Malloc fail");
	i = 0;
	while (tab[i])
	{
		map->max_height = ft_max(map->max_height, ft_atoi(tab[i]));
		map->min_height = ft_min(map->min_height, ft_atoi(tab[i]));
		i++;
	}
	free_array((void **)tab, i);
	return (i);
}

void	get_map_size(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		abort_map(fd, map, "Malloc fail");
	map->cols = get_cols(fd, map, line);
	if (map->cols == 0)
		abort_map(fd, map, INVALID_MAP);
	map->rows = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->rows++;
		if (map->cols != get_cols(fd, map, line))
			abort_map(fd, map, INVALID_MAP);
	}
}
