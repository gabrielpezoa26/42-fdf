/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:00:17 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/28 13:46:21 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	*mlx;

	if (argc != 2)
	{
		handle_error("Usage: ./fdf <map_file>\n");  //trata erro d formatacao
		return (1);
	}
	map = parse_map(argv[1]);  //chama a func de parse
	if (!map)
		handle_error("Failed to parse map.\n");
	mlx = init_mlx(WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	if (!mlx)
		handle_error("Failed to initialize MLX.\n");
	render_map(map, mlx);
	setup_controls(mlx);  //inicializa os controle
	mlx_loop(mlx->mlx_ptr);
	free_memory(map);
	return (0);
}
