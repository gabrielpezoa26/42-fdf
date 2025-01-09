/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:24:58 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/01/09 16:45:51 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "libft/libft.h"
#include "fdf.h"
#include <string.h>

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
	return;
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
				line++;
		}
		else
			line++;
	}
	return (x);  //teste git
}

int	**create_matrix(int line_amount, int col)
{
	int	**matrix;
	int	i;

	i = 0;
	matrix = (int **)malloc(line_amount * sizeof(int *));
	if (matrix == NULL)
		return (NULL);
	while (i < line_amount)
	{
		matrix[i] = (int *)malloc(col * sizeof(int));
		if (matrix[i] == NULL)
		{
			free_memory(matrix, line_amount);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		row;
	int		col;
	char	*mango_loko;

	row = 0;
	if (argc != 2)
		return (ft_printf("Incorrect arg count"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error opening the file."), 1);
	mango_loko = get_next_line(fd);
	while (mango_loko != NULL)
	{
		col = col_counter(mango_loko);
		row++;
		free(mango_loko);
		mango_loko = get_next_line(fd);
	}
	ft_printf("%d %d \n", col, row);
	close (fd);
	return (0);
}
