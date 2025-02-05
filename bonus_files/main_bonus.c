/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:42:37 by gabriel           #+#    #+#             */
/*   Updated: 2025/02/05 12:05:43 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf		*fdf;

	check_input(argc, argv[1]);
	fdf = fdf_init(argv[1]);
	render_image(fdf);
	if (mlx_image_to_window(fdf->mlx, fdf->image, 0, 0) == -1)
	{
		destroy_map(fdf->map);
		mlx_close_window(fdf->mlx);
		handle_error(mlx_strerror(mlx_errno));
	}
	mlx_loop_hook(fdf->mlx, &mv_controls, fdf);
	mlx_loop_hook(fdf->mlx, &render_image, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	destroy_map(fdf->map);
	return (0);
}
