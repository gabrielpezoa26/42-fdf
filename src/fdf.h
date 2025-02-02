/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:06:57 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/02 17:11:58 by gabriel          ###   ########.fr       */
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
# define TEXT_COLOR			0xEAEAEAFF
# define BACKGROUND			0x22222200
# define MENU_BACKGROUND	0x1E1E1EFF
# define COLOR_TEN			0x9e0142ff
# define COLOR_NINE			0xd53e4fff
# define COLOR_EIGHT		0xf46d43ff
# define COLOR_SEVEN		0xfdae61ff
# define COLOR_SIX			0xfee08bff
# define COLOR_FIVE			0xe6f598ff
# define COLOR_FOUR			0xabdda4ff
# define COLOR_THREE		0x66c2a5ff
# define COLOR_TWO			0x3288bdff
# define COLOR_ONE			0x5e4fa2ff
# define FORMAT				"Format:\n\t./fdf maps/filename.fdf"
# define MALLOC				"Malloc failed"
# define INVALID_MAP		"Map is invalid"
# define FILE_ERROR			"Unable to open file"

typedef struct s_point3d
{
	double	x;
	double	y;
	double	z;
	int		mapcolor;
	int		zcolor;
}				t_point3d;

typedef struct s_point2d
{
	int		x;
	int		y;
	int		z;
	int		rgba;
}			t_point2d;

typedef struct s_map
{
	int				rows;
	int				cols;
	int				high;
	int				low;
	bool			use_zcolor;
	double			x_offset;
	double			y_offset;
	double			interval;
	double			alpha;
	double			beta;
	double			xrotate;
	double			yrotate;
	double			zrotate;
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

/* fdf_main.c */
void		init_map(t_map *map);
/* fdf_parse.c */
void		parse_map(int fd, t_map *map);
void		get_dimensions(int fd, t_map *map);
/* fdf_error.c */
void		ft_free_tab(void **ptr, size_t len);
void		free_map(t_map *map);
void		handle_error(const char *message);
void		error_map(int fd, t_map *map, char *message);
/* fdf_draw.c */
void		project(t_map *map, int i, int j);
void		draw_image(void *param);
void		display_menu(mlx_t *mlx);

/* fdf_hooks.c */
void		ft_hook(void *param);
void		fdf_scrollhook(double xdelta, double ydelta, void *param);
void		ft_hook_rotate(void *param);
void		ft_hook_project(void *param);

/* fdf_utils.c*/
void		make_upper(unsigned int i, char *c);
void		draw_reset(mlx_image_t *image);
int			valid_filename(const char *filename);

#endif

// #ifndef FDF_H
// # define FDF_H

// # include <math.h>
// # include <fcntl.h>
// # include <stdlib.h>
// # include "../libft/libft.h"
// # include "../MLX42/include/MLX42/MLX42.h"

// # define WINDOW_WIDTH 1500  //800
// # define WINDOW_HEIGHT 1500  //900

// // STRUCTS
// typedef struct s_point
// {
// 	int	x;
// 	int	y;
// }	t_point;

// typedef struct s_point3d
// {
// 	int	x;
// 	int	y;
// 	int	z;
// }	t_point3d;

// typedef struct s_map
// {
// 	t_point3d	**grid;
// 	int			rows;
// 	int			cols;
// }	t_map;

// typedef struct s_mlx
// {
// 	mlx_t		*mlx_ptr;
// 	mlx_image_t	*img;
// }	t_mlx;

// //PROTOTYPES

// // Parser and map handling
// t_map	*parse_map(char *filename);
// void	populate_matrix(t_map *map, char *filename);
// void	free_memory(t_map *map);

// // Utilities
// int		ft_count_words(char *str, char delimiter);
// int		col_counter(char *line);
// void	ft_free_split(char **split);
// void	handle_error(const char *message);

// // Render
// void	render_map(t_map *map, t_mlx *mlx);
// t_mlx	*init_mlx(int width, int height, char *title);
// void	render_grid(t_map *map, t_mlx *mlx);

// // Controls
// void	setup_controls(t_mlx *mlx);
// void	handle_close(void *param);
// void	handle_keypress(mlx_key_data_t keydata, void *param);
// #endif