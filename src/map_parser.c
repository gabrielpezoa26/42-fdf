/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:24:58 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/01/12 21:57:19 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	check_column_consistency(t_map *map, char *line)
{
	if (ft_count_words(line, ' ') != map->cols)
	{
		free(line);
		handle_error("Error: Inconsistent column count.\n");
	}
}

static int	read_map_file(t_map *map, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		handle_error("Error: Unable to open file.\n");
	while ((line = get_next_line(fd)))
	{
		if (map->rows == 0)
			map->cols = ft_count_words(line, ' ');
		else
			check_column_consistency(map, line);
		map->rows++;
		free(line);
	}
	close(fd);
	return (0);
}

t_map	*parse_map(char *filename)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		handle_error("Error: Memory allocation failed.\n");
	map->rows = 0;
	map->cols = 0;
	read_map_file(map, filename);
	map->grid = malloc(sizeof(t_point3d *) * map->rows);
	if (!map->grid)
	{
		free(map);
		handle_error("Error: Memory allocation failed.\n");
	}
	return (map);
}
