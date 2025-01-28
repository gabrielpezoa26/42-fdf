/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:24:58 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/01/28 14:57:16 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	check_column_consistency(t_map *map, char *line)
{
	if (ft_count_words(line, ' ') != map->cols)
	{
		free(line);
		handle_error("Error: Inconsistent column count.\n");  //validacao mapa
	}
}

static int	read_map_file(t_map *map, char *filename)  //le o .fdf e guarda em "t_map"
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		handle_error("Error: Unable to open file.\n");
	line = get_next_line(fd);
	while (line)
	{
		if (map->rows == 0)
			map->cols = ft_count_words(line, ' ');
		else
			check_column_consistency(map, line);
		map->rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

t_map	*parse_map(char *filename)  //parseia o mapa e forma o grid
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
