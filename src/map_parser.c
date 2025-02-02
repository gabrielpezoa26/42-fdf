/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:24:58 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/02 16:59:06 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	parse_color(int fd, t_map *map, char *tabj)
{
	while (*tabj == '-')
		tabj++;
	while (ft_isdigit(*tabj))
		tabj++;
	if (*tabj == ',')
		tabj++;
	else
		return (0xFFFFFFFF);
	if ((ft_strncmp(tabj, "0X", 2) && ft_strncmp(tabj, "0x", 2)))
		error_map(fd, map, INVALID_MAP);
	tabj += 2;
	ft_striteri(tabj, &make_upper);
	return ((ft_atoi_base(tabj, "0123456789ABCDEF") << 8) | 0xFF);
}

static void	parse_column(int fd, t_map *map, char **tab, int i)
{
	t_point3d	*point;
	int			x_offset;
	int			y_offset;
	int			j;

	j = -1;
	while (++j < map->cols)
	{
		if (!ft_isdigit(*tab[j]) && *tab[j] != '-')
			error_map(fd, map, INVALID_MAP);
		point = &(map->grid3d[i][j]);
		x_offset = (map->cols - 1) * map->interval / 2;
		y_offset = (map->rows - 1) * map->interval / 2;
		point->x = (double)j * (map->interval) - x_offset;
		point->y = (double)i * (map->interval) - y_offset;
		point->z = (double)ft_atoi(tab[j]) * (map->interval);
		map->high = ft_max(map->high, point->z);
		map->low = ft_min(map->low, point->z);
		point->mapcolor = parse_color(fd, map, tab[j]);
	}
}

void	parse_map(int fd, t_map *map)
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
			error_map(fd, map, MALLOC);
		line = ft_strtrim(temp, "\n");
		free(temp);
		if (!line)
			error_map(fd, map, MALLOC);
		tab = ft_split(line, ' ');
		free(line);
		if (!tab)
			error_map(fd, map, MALLOC);
		parse_column(fd, map, tab, i);
		ft_free_tab((void **)tab, map->cols);
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
		error_map(fd, map, MALLOC);
	tab = ft_split(temp, ' ');
	free(temp);
	if (!tab)
		error_map(fd, map, MALLOC);
	i = 0;
	while (tab[i])
	{
		map->high = ft_max(map->high, ft_atoi(tab[i]));
		map->low = ft_min(map->low, ft_atoi(tab[i]));
		i++;
	}
	ft_free_tab((void **)tab, i);
	return (i);
}

void	get_dimensions(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		error_map(fd, map, MALLOC);
	map->cols = get_cols(fd, map, line);
	if (map->cols == 0)
		error_map(fd, map, INVALID_MAP);
	map->rows = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->rows++;
		if (map->cols != get_cols(fd, map, line))
			error_map(fd, map, INVALID_MAP);
	}
}

// static void	check_column_consistency(t_map *map, char *line)
// {
// 	if (ft_count_words(line, ' ') != map->cols)
// 	{
// 		free(line);
// 		handle_error("Error: Inconsistent column count.\n");  //validacao mapa
// 	}
// }

// static int	read_map_file(t_map *map, char *filename)  //le o .fdf e guarda em "t_map"
// {
// 	int		fd;
// 	char	*line;

// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 		handle_error("Error: Unable to open file.\n");
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		if (map->rows == 0)
// 			map->cols = ft_count_words(line, ' ');
// 		else
// 			check_column_consistency(map, line);
// 		map->rows++;
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }

// t_map	*parse_map(char *filename)  //parseia o mapa e forma o grid
// {
// 	t_map	*map;

// 	map = malloc(sizeof(t_map));
// 	if (!map)
// 		handle_error("Error: Memory allocation failed.\n");
// 	map->rows = 0;
// 	map->cols = 0;
// 	read_map_file(map, filename);
// 	map->grid = malloc(sizeof(t_point3d *) * map->rows);
// 	if (!map->grid)
// 	{
// 		free(map);
// 		handle_error("Error: Memory allocation failed.\n");
// 	}
// 	return (map);
// }
