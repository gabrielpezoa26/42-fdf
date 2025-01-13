/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:06:57 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/01/12 23:05:19 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

//            STRUCTS               //
/*
typedef struct s_point
{
	float	x;
	float	y;
}	t_point;*/

typedef struct s_point3d
{
	int		x;
	int		y;
	int		z;
}	t_point3d;

typedef struct s_map
{
	t_point3d	**grid;
	int			rows;
	int			cols;
}	t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;  //placeholder
	char	*img_data;  //placeholder
	int		bpp;  //placeholder
	int		line_len;  //placeholder
	int		endian;  //placeholder
}	t_mlx;

//            PROTOTYPES               //

// parser and map handling
t_map	*parse_map(char *filename);
void	populate_matrix(t_map *map, char *filename);
void	free_memory(t_map *map);

// utilities
int		ft_count_words(char *str, char delimiter);
int		col_counter(char *line);
void	ft_free_split(char **split);
void	handle_error(const char *message);

// render
void	render_map(t_map *map, t_mlx *mlx);
t_mlx	*init_mlx(int width, int height, char *title);

// controls
void	setup_controls(t_mlx *mlx);
int		handle_close(t_mlx *mlx);
int		handle_keypress(int keycode, t_mlx *mlx);

#endif
