/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:59:41 by gabriel           #+#    #+#             */
/*   Updated: 2025/02/02 16:58:10 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bresenham(mlx_image_t *image, t_point2d a, t_point2d b)
{
	int			error[2];
	t_point2d	cur;

	cur.x = a.x;
	cur.y = a.y;
	error[0] = abs(b.x - a.x) - abs(b.y - a.y);
	while (cur.x != b.x || cur.y != b.y)
	{
		if ((uint32_t)cur.x < image->width && (uint32_t)cur.y < image->height)
			mlx_put_pixel(image, cur.x, cur.y, 0xFFFFFF);
		error[1] = 2 * error[0];
		if (error[1] > -abs(b.y - a.y))
		{
			error[0] -= abs(b.y - a.y);
			cur.x += (a.x < b.x);
			cur.x -= (b.x < a.x);
		}
		if (error[1] < abs(b.x - a.x))
		{
			error[0] += abs(b.x - a.x);
			cur.y += (a.y < b.y);
			cur.y -= (b.y < a.y);
		}
	}
}

void	project(t_map *map, int i, int j)
{
	t_point3d	*previous;
	t_point3d	temp;
	t_point2d	*new;

	previous = &(map->grid3d[i][j]);
	new = &(map->grid2d[i][j]);
	temp.x = previous->x;
	temp.y = previous->y;
	temp.z = previous->z * map->zscale;
	new->x = (int)((temp.x * map->zoom - temp.y * map->zoom)
			* cos(map->alpha) + map->x_offset);
	new->y = (int)(-temp.z * map->zoom
			+ (temp.x * map->zoom + temp.y * map->zoom)
			* sin(map->beta) + map->y_offset);
	if (map->use_zcolor)
		new->rgba = previous->zcolor;
	else
		new->rgba = previous->mapcolor;
}

static void	draw_line(t_fdf *fdf, int x, int y)
{
	if (y == 0 && x == 0)
		project(fdf->map, y, x);
	if (y + 1 < fdf->map->rows)
	{
		project(fdf->map, y + 1, x);
		bresenham(fdf->image, fdf->map->grid2d[y][x],
			fdf->map->grid2d[y + 1][x]);
	}
	if (x + 1 < fdf->map->cols)
	{
		if (y == 0)
			project(fdf->map, y, x + 1);
		bresenham(fdf->image, fdf->map->grid2d[y][x],
			fdf->map->grid2d[y][x + 1]);
	}
}

void	draw_image(void *param)
{
	int		i;
	int		j;
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	draw_reset(fdf->image);
	i = -1;
	while (++i < fdf->map->rows)
	{
		j = -1;
		while (++j < fdf->map->cols)
			draw_line(fdf, j, i);
	}
}

// static void	render_line(t_mlx *mlx, t_point start, t_point end)
// {
// 	double	dx;
// 	double	dy;
// 	double	max;
// 	double	step;

// 	dx = end.x - start.x;
// 	dy = end.y - start.y;
// 	max = fmax(fabs(dx), fabs(dy));
// 	step = 1.0 / max;
// 	while (max > 0)
// 	{
// 		mlx_put_pixel(mlx->img, start.x, start.y, 0xFFFFFF);
// 		start.x += dx * step;
// 		start.y += dy * step;
// 		max--;
// 	}
// }

// static void	render_horizontal(t_map *map, t_mlx *mlx, int row)
// {
// 	int		col;
// 	int		size;
// 	t_point	start;
// 	t_point	end;

// 	col = 0;
// 	size = 25;
// 	while (col < map->cols - 1)
// 	{
// 		start.x = col * size;  //tamanho do bagui
// 		start.y = row * size;
// 		end.x = (col + 1) * size;
// 		end.y = row * size;
// 		render_line(mlx, start, end);
// 		col++;
// 	}
// }

// static void	render_vertical(t_map *map, t_mlx *mlx, int col)
// {
// 	int		row;
// 	int		size;
// 	t_point	start;
// 	t_point	end;

// 	row = 0;
// 	size = 25;
// 	while (row < map->rows - 1)
// 	{
// 		start.x = col * size;
// 		start.y = row * size;
// 		end.x = col * size;
// 		end.y = (row + 1) * size;
// 		render_line(mlx, start, end);
// 		row++;
// 	}
// }

// void	render_grid(t_map *map, t_mlx *mlx)
// {
// 	int	row;
// 	int	col;

// 	row = 0;
// 	while (row < map->rows)
// 	{
// 		render_horizontal(map, mlx, row);
// 		row++;
// 	}
// 	col = 0;
// 	while (col < map->cols)
// 	{
// 		render_vertical(map, mlx, col);
// 		col++;
// 	}
// }

