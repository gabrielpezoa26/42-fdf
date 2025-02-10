/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:36:21 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/10 14:07:10 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_array(void **tab, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	destroy_map(t_map *map)
{
	if (map == NULL)
		return ;
	if (map->grid2d != NULL)
		free_array((void **)map->grid2d, map->rows);
	if (map->grid3d != NULL)
		free_array((void **)map->grid3d, map->rows);
	free(map);
}

void	abort_map(int fd, t_map *map, char *message)
{
	close(fd);
	destroy_map(map);
	handle_error(message);
}

void	handle_error(const char *message)
{
	if (errno == 0)
		ft_printf("FdF: %s\n", message);
	else
		perror("FdF");
	exit(1);
}
