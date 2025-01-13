/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:00:17 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/12 21:45:13 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	char	*mango_loko;
	int		fd, row;

	if (argc != 2)
		return (ft_putstr_fd("Usage: ./fdf <filename.fdf>\n", 2), 1);
	map = parse_map(argv[1]);
	if (!map)
		return (1);
	populate_matrix(map, argv[1]);
	ft_printf("Rows: %d, Columns: %d\n", map->rows, map->cols);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		handle_error("Error: Unable to open file for row processing.\n");
	row = 0;
	while ((mango_loko = get_next_line(fd)))
		ft_printf("Row %d has %d columns\n", row++, col_counter(mango_loko)), free(mango_loko);
	close(fd);
	free_memory(map);
	return (0);
}
