/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:59:41 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/05 11:06:34 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bresenham(mlx_image_t *img, t_point2d a, t_point2d b)
{
	int			error[2];
	t_point2d	cur;

	cur.col = a.col;
	cur.row = a.row;
	error[0] = abs(b.col - a.col) - abs(b.row - a.row);
	while (cur.col != b.col || cur.row != b.row)
	{
		if ((uint32_t)cur.col < img->width && (uint32_t)cur.row < img->height)
			mlx_put_pixel(img, cur.col, cur.row, 0xFFFFFFFF);
		error[1] = 2 * error[0];
		if (error[1] > -abs(b.row - a.row))
		{
			error[0] -= abs(b.row - a.row);
			cur.col += (a.col < b.col);
			cur.col -= (b.col < a.col);
		}
		if (error[1] < abs(b.col - a.col))
		{
			error[0] += abs(b.col - a.col);
			cur.row += (a.row < b.row);
			cur.row -= (b.row < a.row);
		}
	}
}

void	convert_to_2d(t_map *map, int row, int col)
{
	t_point3d	*point_3d;
	t_point2d	*point_2d;
	t_point3d	temp;

	point_3d = &(map->grid3d[row][col]);
	point_2d = &(map->grid2d[row][col]);
	temp.x = point_3d->x;
	temp.y = point_3d->y;
	temp.z = point_3d->z * map->height_scale;
	point_2d->col = (int)((temp.x * map->zoom - temp.y * map->zoom)
			* cos(map->angle_x) + map->x_shift);
	point_2d->row = (int)(-temp.z * map->zoom
			+ (temp.x * map->zoom + temp.y * map->zoom)
			* sin(map->angle_y) + map->y_shift);
}

static void	render_line(t_fdf *fdf, int x, int y)
{
	if (y == 0 && x == 0)
		convert_to_2d(fdf->map, y, x);
	if (y + 1 < fdf->map->rows)
	{
		convert_to_2d(fdf->map, y + 1, x);
		bresenham(fdf->image, fdf->map->grid2d[y][x],
			fdf->map->grid2d[y + 1][x]);
	}
	if (x + 1 < fdf->map->cols)
	{
		if (y == 0)
			convert_to_2d(fdf->map, y, x + 1);
		bresenham(fdf->image, fdf->map->grid2d[y][x],
			fdf->map->grid2d[y][x + 1]);
	}
}

void	render_image(void *data)
{
	int		i;
	int		j;
	t_fdf	*fdf;

	fdf = (t_fdf *)data;
	fill_image(fdf->image);
	i = -1;
	while (++i < fdf->map->rows)
	{
		j = -1;
		while (++j < fdf->map->cols)
			render_line(fdf, j, i);
	}
}
