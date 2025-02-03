/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:12:25 by gabriel           #+#    #+#             */
/*   Updated: 2025/02/03 17:31:18 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_handler(double x_delta, double y_delta, void *data)
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
		ft_printf(";) \n");  //teste
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->map->x_offset -= 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->map->x_offset += 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->map->y_offset += 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->map->y_offset -= 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_EQUAL))
		zoom_handler(0, 1, data);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_MINUS))
		zoom_handler(0, -1, data);
}
