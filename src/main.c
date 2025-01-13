/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:00:17 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/13 15:06:05 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	*mlx;

	if (argc != 2)
		return (ft_putstr_fd("Usage: ./fdf <filename.fdf>\n", 2), 1);
	map = parse_map(argv[1]);
	if (!map)
		return (1);
	populate_matrix(map, argv[1]);
	mlx = init_mlx(800, 600, "FdF");
	setup_controls(mlx);
	render_map(map, mlx);
	mlx_loop(mlx->mlx_ptr);
	free_memory(map);
	free(mlx);
	return (0);
}
