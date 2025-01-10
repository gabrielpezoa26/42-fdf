/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:36:28 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/01/10 15:47:28 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_memory(int **matrix, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(matrix[i]);
		i++;
	}
	free (matrix);
	return ;
}

int	col_counter(char *line)
{
	int	x;

	x = 0;
	while (*line != '\0')
	{
		if (ft_isdigit(*line) != 0)
		{
			x++;
			while (ft_isdigit(*line) != 0)
			{
				line++;
			}
		}
		else if (ft_isdigit(*line) == 0)
		{
			line++;
		}
	}
	return (x);
}