/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:36:28 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/01/20 16:12:28 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_memory(t_map *map)
{
	int	i;

	if (!map || !map->grid)
		return ;
	i = 0;
	while (i < map->rows)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	free(map);
}

int	col_counter(char *line)
{
	int	count;

	count = 0;
	while (*line)
	{
		if (ft_isdigit(*line) || *line == '-')
		{
			count++;
			while (ft_isdigit(*line) || *line == '-')
				line++;
		}
		if (*line)
			line++;
	}
	return (count);
}

int	ft_count_words(char *str, char delimiter)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == delimiter)
		{
			str++;
		}
		if (*str && *str != delimiter)
		{
			count++;
			while (*str && *str != delimiter)
				str++;
		}
	}
	return (count);
}
