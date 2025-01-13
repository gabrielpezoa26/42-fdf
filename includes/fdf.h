/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:06:57 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/01/12 22:08:17 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

typedef struct s_point3d {
	int x;
	int y;
	int z;
}	t_point3d;

typedef struct s_map {
	t_point3d **grid;
	int rows;
	int cols;
}	t_map;

typedef struct s_mlx {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		bpp;
	int		line_len;
	int		endian;
}	t_mlx;

t_map	*parse_map(char *filename);
void	populate_matrix(t_map *map, char *filename);
void	free_memory(t_map *map);
int		ft_count_words(char *str, char delimiter);
void	handle_error(const char *message);
int		col_counter(char *line);
void	ft_free_split(char **split);
void	render_map(t_map *map, t_mlx *mlx);
t_mlx	*init_mlx(int width, int height, char *title);
#endif
