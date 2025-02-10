/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:06:57 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/10 18:13:46 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define WIDTH			1920
# define HEIGHT			1080
# define FORMAT			"Invalid format. Correct format:\n./fdf maps/file.fdf"
# define INVALID_MAP	"Invalid map"

typedef struct s_point2d
{
	int		col;
	int		row;
	int		color;
}			t_point2d;

typedef struct s_point3d
{
	double	x;
	double	y;
	double	z;
	int		mapcolor;
}				t_point3d;

typedef struct s_map
{
	int				rows;
	int				cols;
	int				max_height;
	int				min_height;
	double			x_shift;
	double			y_shift;
	double			interval;
	double			angle_x;
	double			angle_y;
	double			zoom;
	double			height_scale;
	t_point3d		**grid3d;
	t_point2d		**grid2d;
}					t_map;

typedef struct s_fdf
{
	mlx_t		*mlx;
	t_map		*map;
	mlx_image_t	*image;
}				t_fdf;

//SETUP
t_fdf		*fdf_init(char *filename);

//PARSE
void		map_parser(int fd, t_map *map);
void		get_map_size(int fd, t_map *map);

//ERROR
void		free_array(void **ptr, size_t len);
void		destroy_map(t_map *map);
void		handle_error(const char *message);
void		abort_map(int fd, t_map *map, char *message);

//RENDER
void		convert_to_2d(t_map *map, int row, int col);
void		render_image(void *data);
//CONTROLS
void		mv_controls(void *data);

//UTILS
void		fill_image(mlx_image_t *image);
int			is_valid(const char *filename);
void		make_upper(unsigned int i, char *c);
void		check_input(int argc, char *filename);

#endif
