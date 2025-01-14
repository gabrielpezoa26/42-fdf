/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:00:17 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/13 21:22:28 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	t_map   *map;
	t_mlx   *mlx;

	if (argc != 2)
	{
		handle_error("Usage: ./fdf <map_file>\n");
		return (1);
	}
	map = parse_map(argv[1]);
	if (!map)
		handle_error("Failed to parse map.\n");
	mlx = init_mlx(WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	if (!mlx)
		handle_error("Failed to initialize MLX.\n");
	render_map(map, mlx);
	setup_controls(mlx);
	mlx_loop(mlx->mlx_ptr);
	free_memory(map);
	return (0);
}
