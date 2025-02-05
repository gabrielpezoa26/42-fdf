/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:41:48 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/05 18:44:15 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mv_controls(void *data)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)data;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(fdf->mlx);
		ft_printf(";) \n");
	}
}
