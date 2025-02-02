/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:06:57 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/02 18:09:49 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include "MLX42/MLX42.h"
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define WIDTH				1920
# define HEIGHT				1080
# define FORMAT				" Corret format:\n./fdf maps/filename.fdf"
# define INVALID_MAP		"Map is invalid"


typedef struct s_point2d
{
	int		x;
	int		y;
	int		z;
	int		rgba;
}			t_point2d;

typedef struct s_point3d
{
	double	x;
	double	y;
	double	z;
	int		mapcolor;
	int		zcolor;
}				t_point3d;

typedef struct s_map
{
	int				rows;
	int				cols;
	int				high;
	int				low;
	double			x_offset;
	double			y_offset;
	double			interval;
	double			alpha;
	double			beta;
	double			zoom;
	double			zscale;
	t_point3d		**grid3d;
	t_point2d		**grid2d;
}					t_map;

typedef struct s_fdf
{
	mlx_t		*mlx;
	t_map		*map;
	mlx_image_t	*image;
}				t_fdf;

//MAIN
void		map_init(t_map *map);

//PARSE
void		map_parser(int fd, t_map *map);
void		get_map_size(int fd, t_map *map);

//ERROR
void		free_tab(void **ptr, size_t len);
void		free_map(t_map *map);
void		handle_error(const char *message);
void		error_map(int fd, t_map *map, char *message);

//RENDER
void		convert_to_2d(t_map *map, int i, int j);
void		render_image(void *data);

//CONTROLS
void		ft_hook(void *data);
void		zoom_handler(double x_delta, double y_delta, void *data);

//UTILS

void		fill_image(mlx_image_t *image);
int			is_valid(const char *filename);
void		make_upper(unsigned int i, char *c);

#endif
