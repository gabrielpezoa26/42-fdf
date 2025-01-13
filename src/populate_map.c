/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:38:59 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/12 21:50:52 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	allocate_row(t_map *map, int row)
{
	map->grid[row] = malloc(sizeof(t_point3d) * map->cols);
	if (!map->grid[row])
		handle_error("Error: Memory allocation failed for row.\n");
}

static void	fill_row(t_map *map, char *line, int row)
{
	char	**values;
	int		col;

	values = ft_split(line, ' ');
	if (!values)
		handle_error("Error: Memory allocation failed for row values.\n");
	col = 0;
	while (col < map->cols)
	{
		map->grid[row][col].x = col;
		map->grid[row][col].y = row;
		map->grid[row][col].z = ft_atoi(values[col]);
		col++;
	}
	ft_free_split(values);
}

static void	process_line(t_map *map, char *line, int row)
{
	allocate_row(map, row);
	fill_row(map, line, row);
}

void	populate_matrix(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	int		row;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		handle_error("Error: Unable to open file.\n");
	row = 0;
	while ((line = get_next_line(fd)))
	{
		process_line(map, line, row);
		free(line);
		row++;
	}
	close(fd);
}
