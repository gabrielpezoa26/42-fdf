/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:12:25 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/13 14:19:51 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_keypress(mlx_key_data_t keydata, void *param)
{
	t_mlx *mlx = (t_mlx *)param;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(mlx->mlx_ptr);
		exit(0);
	}
}

void	handle_close(void *param)
{
	t_mlx *mlx = (t_mlx *)param;

	mlx_terminate(mlx->mlx_ptr);
	exit(0);
}

void	setup_controls(t_mlx *mlx)
{
	mlx_close_hook(mlx->mlx_ptr, handle_close, mlx); 
	mlx_key_hook(mlx->mlx_ptr, handle_keypress, mlx);
}
