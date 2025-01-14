/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:59:41 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/13 22:04:03 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void render_line(t_mlx *mlx, t_point start, t_point end)
{
	double dx;
	double dy;
	double max;
	double step;

	dx = end.x - start.x;
	dy = end.y - start.y;
	max = fmax(fabs(dx), fabs(dy));
	step = 1.0 / max;
	while (max > 0)
	{
		mlx_put_pixel(mlx->img, start.x, start.y, 0xFFFFFF);
		start.x += dx * step;
		start.y += dy * step;
		max--;
	}
}

static void render_horizontal(t_map *map, t_mlx *mlx, int row)
{
	int col;
	t_point start, end;

	col = 0;
	while (col < map->cols - 1)
	{
		start.x = col * 20;
		start.y = row * 20;
		end.x = (col + 1) * 20;
		end.y = row * 20;
		render_line(mlx, start, end);
		col++;
	}
}

static void render_vertical(t_map *map, t_mlx *mlx, int col)
{
	int row;
	t_point start;
	t_point end;

	row = 0;
	while (row < map->rows - 1)
	{
		start.x = col * 20;
		start.y = row * 20;
		end.x = col * 20;
		end.y = (row + 1) * 20;
		render_line(mlx, start, end);
		row++;
	}
}

void render_grid(t_map *map, t_mlx *mlx)
{
	int row;
	int col;

	row = 0;
	while (row < map->rows)
	{
		render_horizontal(map, mlx, row);
		row++;
	}

	col = 0;
	while (col < map->cols)
	{
		render_vertical(map, mlx, col);
		col++;
	}
}

void render_map(t_map *map, t_mlx *mlx)
{
	render_grid(map, mlx);
	mlx_image_to_window(mlx->mlx_ptr, mlx->img, 0, 0);
}

t_mlx *init_mlx(int width, int height, char *title)
{
	t_mlx *mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->mlx_ptr = mlx_init(width, height, title, true);
	if (!mlx->mlx_ptr)
	{
		free(mlx);
		return (NULL);
	}
	mlx->img = mlx_new_image(mlx->mlx_ptr, width, height);
	if (!mlx->img)
	{
		mlx_terminate(mlx->mlx_ptr);
		free(mlx);
		return (NULL);
	}
	return (mlx);
}