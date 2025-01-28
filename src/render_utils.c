/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:12:37 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/01/28 13:16:05 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_map(t_map *map, t_mlx *mlx)
{
	render_grid(map, mlx);
	mlx_image_to_window(mlx->mlx_ptr, mlx->img, 0, 0);
}

t_mlx	*init_mlx(int width, int height, char *title)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->mlx_ptr = mlx_init(width, height, title, true);
	if (!mlx->mlx_ptr)
	{
		free(mlx);
		return (NULL);
	}
	mlx->img = mlx_new_image(mlx->mlx_ptr, width, height);
	if (!mlx->img)
	{
		mlx_terminate(mlx->mlx_ptr);
		free(mlx);
		return (NULL);
	}
	return (mlx);
}
