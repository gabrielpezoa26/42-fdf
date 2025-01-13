/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:12:25 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/12 23:25:57 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)  //esc
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(0);
	}
	return (0);
}

int	handle_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);  //mouse
	exit(0);
	return (0);
}

void	setup_controls(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, 17, 0, handle_close, mlx);
	mlx_key_hook(mlx->win_ptr, handle_keypress, mlx);
}
