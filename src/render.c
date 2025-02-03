/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:59:41 by gabriel           #+#    #+#             */
/*   Updated: 2025/02/02 22:07:38 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	prepare_line(t_line *line, t_point2d a, t_point2d b)
{
	line->delta_x = abs(b.x - a.x);
	line->delta_y = abs(b.y - a.y);
	line->step_x = 1;
	line->step_y = 1;
	if (a.x > b.x)
		line->step_x = -1;
	if (a.y > b.y)
		line->step_y = -1;
	line->error = line->delta_x - line->delta_y;
}

static void	line_to_pixels(mlx_image_t *image, t_point2d a, t_point2d b)
{
	t_point2d	cur;
	t_line		line;

	cur.x = a.x;
	cur.y = a.y;
	prepare_line(&line, a, b);
	while (cur.x != b.x || cur.y != b.y)
	{
		if ((uint32_t)cur.x < image->width && (uint32_t)cur.y < image->height)
			mlx_put_pixel(image, cur.x, cur.y, 0xFFFFFF);
		if (2 * line.error > -line.delta_y)
		{
			line.error -= line.delta_y;
			cur.x += line.step_x;
		}
		if (2 * line.error < line.delta_x)
		{
			line.error += line.delta_x;
			cur.y += line.step_y;
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
	temp.z = point_3d->z * map->zscale;
	point_2d->x = (int)((temp.x * map->zoom - temp.y * map->zoom)
			* cos(map->alpha) + map->x_offset);
	point_2d->y = (int)(-temp.z * map->zoom
			+ (temp.x * map->zoom + temp.y * map->zoom)
			* sin(map->beta) + map->y_offset);
}

static void	render_line(t_fdf *fdf, int x, int y)
{
	if (y == 0 && x == 0)
		convert_to_2d(fdf->map, y, x);
	if (y + 1 < fdf->map->rows)
	{
		convert_to_2d(fdf->map, y + 1, x);
		line_to_pixels(fdf->image, fdf->map->grid2d[y][x],
			fdf->map->grid2d[y + 1][x]);
	}
	if (x + 1 < fdf->map->cols)
	{
		if (y == 0)
			convert_to_2d(fdf->map, y, x + 1);
		line_to_pixels(fdf->image, fdf->map->grid2d[y][x],
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
