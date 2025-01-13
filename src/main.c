/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:00:17 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/12 22:17:33 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

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

