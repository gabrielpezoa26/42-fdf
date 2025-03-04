/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:12:25 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/10 14:08:09 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom_handler(double x_delta, double y_delta, void *data)
{
	t_fdf		*fdf;

	fdf = (t_fdf *)data;
	if (y_delta > 0)
		fdf->map->zoom *= 1.02;
	else if (y_delta < 0 && fdf->map->zoom * 0.98 > 0)
		fdf->map->zoom *= 0.98;
	x_delta++;
}

void	mv_controls(void *data)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)data;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(fdf->mlx);
		ft_printf(";) \n");
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->map->x_shift -= 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->map->x_shift += 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->map->y_shift += 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->map->y_shift -= 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_EQUAL))
		zoom_handler(0, 1, data);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_MINUS))
		zoom_handler(0, -1, data);
}
