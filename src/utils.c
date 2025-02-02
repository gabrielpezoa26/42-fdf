/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:36:28 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/02 16:59:31 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	valid_filename(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	filename += len - 4;
	return (ft_strncmp(filename, ".fdf", 4) == 0);
}

void	make_upper(unsigned int i, char *c)
{
	i++;
	*c = ft_toupper(*c);
}

void	draw_reset(mlx_image_t *image)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < image->height)
	{
		j = 0;
		while (j < image->width)
		{
			mlx_put_pixel(image, j, i, BACKGROUND);
			j++;
		}
		i++;
	}
}

// void	free_memory(t_map *map)
// {
// 	int	i;

// 	if (!map || !map->grid)
// 		return ;
// 	i = 0;
// 	while (i < map->rows)
// 	{
// 		free(map->grid[i]);
// 		i++;
// 	}
// 	free(map->grid);
// 	free(map);
// }

// int	col_counter(char *line)
// {
// 	int	count;

// 	count = 0;
// 	while (*line)
// 	{
// 		if (ft_isdigit(*line) || *line == '-')
// 		{
// 			count++;
// 			while (ft_isdigit(*line) || *line == '-')
// 				line++;
// 		}
// 		if (*line)
// 			line++;
// 	}
// 	return (count);
// }

// int	ft_count_words(char *str, char delimiter)
// {
// 	int	count;

// 	count = 0;
// 	while (*str)
// 	{
// 		while (*str == delimiter)
// 		{
// 			str++;
// 		}
// 		if (*str && *str != delimiter)
// 		{
// 			count++;
// 			while (*str && *str != delimiter)
// 				str++;
// 		}
// 	}
// 	return (count);
// }
