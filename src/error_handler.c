/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:36:21 by gabriel           #+#    #+#             */
/*   Updated: 2025/02/02 16:58:25 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_tab(void **tab, size_t len)
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

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->grid2d)
		ft_free_tab((void **)map->grid2d, map->rows);
	if (map->grid3d)
		ft_free_tab((void **)map->grid3d, map->rows);
	free(map);
}

void	handle_error(const char *message)
{
	if (errno == 0)
	{
		ft_putstr_fd("FdF: ", 2);
		ft_putendl_fd((char *)message, 2);
	}
	else
		perror("FdF");
	exit(1);
}

void	error_map(int fd, t_map *map, char *message)
{
	close(fd);
	free_map(map);
	handle_error(message);
}
