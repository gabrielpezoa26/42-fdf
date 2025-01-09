/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:24:58 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/01/09 19:42:17 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	**populate_matrix(int line_amount, char **matrix)
{
	char	**result;
	int		i;
	int		j;

	result = malloc(sizeof(int *));
	i = 0;
	j = 0;
	while (i < line_amount)
	{
		if (matrix[i][j] == '\n')
			j++;
		else if (matrix[i][j] == '\0')
			return (result);
		result[i][j] = matrix[i][j];
		i++;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		row;
	int		col;
	char	*mango_loko;

	row = 0;
	if (argc != 2)
		return (ft_printf("Incorrect arg count"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error opening the file."));
	mango_loko = get_next_line(fd);
	while (mango_loko != NULL)
	{
		col = col_counter(mango_loko);
		row++;
		free(mango_loko);
		mango_loko = get_next_line(fd);
		ft_printf("%d \n", populate_matrix(4, (char **)mango_loko));  //teste
	}
	ft_printf("%d %d \n", col, row);
	close (fd);
	return (0);
}
