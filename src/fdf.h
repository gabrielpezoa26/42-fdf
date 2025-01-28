/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:06:57 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/01/28 13:41:03 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 900

// STRUCTS
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_point3d
{
	int	x;
	int	y;
	int	z;
}	t_point3d;

typedef struct s_map
{
	t_point3d	**grid;
	int			rows;
	int			cols;
}	t_map;

typedef struct s_mlx
{
	mlx_t		*mlx_ptr;
	mlx_image_t	*img;
}	t_mlx;

//PROTOTYPES

// Parser and map handling
t_map	*parse_map(char *filename);
void	populate_matrix(t_map *map, char *filename);
void	free_memory(t_map *map);

// Utilities
int		ft_count_words(char *str, char delimiter);
int		col_counter(char *line);
void	ft_free_split(char **split);
void	handle_error(const char *message);

// Render
void	render_map(t_map *map, t_mlx *mlx);
t_mlx	*init_mlx(int width, int height, char *title);
void	render_grid(t_map *map, t_mlx *mlx);

// Controls
void	setup_controls(t_mlx *mlx);
void	handle_close(void *param);
void	handle_keypress(mlx_key_data_t keydata, void *param);
#endif