/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:10:44 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/02 22:56:16 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_partial_rows(t_map *map, int i)
{
	while (--i >= 0)
	{
		free(map->grid3d[i]);
		free(map->grid2d[i]);
	}
	free(map->grid3d);
	free(map->grid2d);
}

static void	allocate_map(t_map *map)
{
	int	i;

	ft_printf("DEBUG: Allocating map - Rows: %d, Cols: %d\n", map->rows, map->cols);
	map->grid3d = malloc(sizeof(t_point3d *) * map->rows);
	map->grid2d = malloc(sizeof(t_point2d *) * map->rows);
	if (!map->grid3d || !map->grid2d)
	{
		free(map->grid3d);
		free(map->grid2d);
		handle_error("Malloc fail");
	}
	ft_printf("DEBUG: Grid allocated - grid3d: %p, grid2d: %p\n", (void *)map->grid3d, (void *)map->grid2d);
	i = 0;
	while (i < map->rows)
	{
		map->grid3d[i] = malloc(sizeof(t_point3d) * map->cols);
		map->grid2d[i] = malloc(sizeof(t_point2d) * map->cols);
		if (!map->grid3d[i] || !map->grid2d[i])
		{
			free_partial_rows(map, i);
			handle_error("Malloc fail");
		}
		ft_printf("DEBUG: Row %d allocated - grid3d[%d]: %p, grid2d[%d]: %p\n",
			i, i, (void *)map->grid3d[i], i, (void *)map->grid2d[i]);
		i++;
	}
}


void	map_init(t_map *map)
{
	map->alpha = 0.46373398 / 2;
	map->beta = 0.46373398;

	map->x_offset = WIDTH / 2;
	map->y_offset = HEIGHT / 2;
	
	map->zoom = 0.8;
	map->zscale = 0.8;
	map->high = INT_MIN;
	map->low = INT_MAX;
	map->rows = 0;
	map->cols = 0;
	map->grid2d = NULL;
	map->grid3d = NULL;
}

static t_map	*input_parser(char *filename)
{
	int		fd;
	t_map	*map;

	fd = open(filename, O_RDONLY, 0777);
	if (fd == -1)
		handle_error("Error");
	map = malloc(sizeof(t_map));
	if (!map)
	{
		close(fd);
		handle_error("Malloc fail");
	}
	map_init(map);
	get_map_size(fd, map);
	close(fd);
	allocate_map(map);
	map->interval = ft_min(WIDTH / map->cols, HEIGHT / map->rows) / 2;
	map->interval = ft_max(2, map->interval);
	fd = open(filename, O_RDONLY, 0777);
	map_parser(fd, map);
	close(fd);
	return (map);
}

t_fdf	*fdf_init(char *filename)
{
	static t_fdf	fdf;

	fdf.map = input_parser(filename);
	fdf.mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (fdf.mlx == NULL)
	{
		destroy_map(fdf.map);
		handle_error(mlx_strerror(mlx_errno));
	}
	fdf.image = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	if (fdf.image == NULL)
	{
		destroy_map(fdf.map);
		mlx_close_window(fdf.mlx);
		handle_error(mlx_strerror(mlx_errno));
	}
	return (&fdf);
}
