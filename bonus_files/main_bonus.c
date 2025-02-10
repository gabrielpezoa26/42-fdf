/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:42:37 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/10 14:08:18 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

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
