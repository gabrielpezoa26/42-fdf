/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:59:41 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/12 22:09:10 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

t_mlx	*init_mlx(int width, int height, char *title)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		handle_error("Error: Failed to allocate memory for MLX.\n");
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		handle_error("Error: Failed to initialize MLX.\n");
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, width, height, title);
	if (!mlx->win_ptr)
		handle_error("Error: Failed to create MLX window.\n");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, width, height);
	if (!mlx->img_ptr)
		handle_error("Error: Failed to create MLX image.\n");
	mlx->img_data = mlx_get_data_addr(
		mlx->img_ptr, 
		&mlx->bpp, 
		&mlx->line_len, 
		&mlx->endian
	);
	return (mlx);
}

void    render_map(t_map *map, t_mlx *mlx)
{
	(void)map;
	(void)mlx;
	ft_printf("Rendering map...\n");
}


