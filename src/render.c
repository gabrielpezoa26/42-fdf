/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:59:41 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/13 20:56:07 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*init_mlx(int width, int height, char *title)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		handle_error("Error: Failed to allocate memory for MLX.\n");
	mlx->mlx_ptr = mlx_init(width, height, title, true);
	if (!mlx->mlx_ptr)
		handle_error("Error: Failed to initialize MLX.\n");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, width, height);
	if (!mlx->img_ptr)
		handle_error("Error: Failed to create MLX image.\n");

	return (mlx);
}

void	render_map(t_map *map, t_mlx *mlx)
{
	if (!map || !mlx)
		return ;
	mlx_image_to_window(mlx->mlx_ptr, mlx->img_ptr, 0, 0);
	ft_printf("Rendering map...\n");
	mlx_loop(mlx->mlx_ptr);
}