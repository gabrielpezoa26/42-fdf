/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:12:25 by gabriel           #+#    #+#             */
/*   Updated: 2025/02/02 16:58:44 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fdf		*fdf;

	fdf = (t_fdf *)param;
	if (ydelta > 0)
		fdf->map->zoom *= 1.02;
	else if (ydelta < 0 && fdf->map->zoom * 0.98 > 0)
		fdf->map->zoom *= 0.98;
	xdelta++;
}

void	ft_hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->map->x_offset -= 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->map->x_offset += 5; 
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->map->y_offset -= 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->map->y_offset += 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_EQUAL))
		fdf_scrollhook(0, 1, param);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_MINUS))
		fdf_scrollhook(0, -1, param);
}

// void	handle_keypress(mlx_key_data_t keydata, void *param)
// {
// 	t_mlx	*mlx;

// 	mlx = (t_mlx *)param;
// 	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
// 	{
// 		mlx_terminate(mlx->mlx_ptr);
// 		exit(0);
// 	}
// }

// void	handle_close(void *param)
// {
// 	t_mlx	*mlx;

// 	mlx = (t_mlx *)param;
// 	mlx_terminate(mlx->mlx_ptr);
// 	exit(0);
// }

// void	setup_controls(t_mlx *mlx)
// {
// 	mlx_close_hook(mlx->mlx_ptr, handle_close, mlx);
// 	mlx_key_hook(mlx->mlx_ptr, handle_keypress, mlx);
// }
