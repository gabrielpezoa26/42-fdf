/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:51:55 by gcesar-n          #+#    #+#             */
/*   Updated: 2024/11/12 17:18:26 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*malloc_result;
	size_t	malloc_size;

	if (nmemb != 0 && size != 0 && nmemb > (size_t) -1 / size)
		return (NULL);
	malloc_size = nmemb * size;
	malloc_result = malloc(malloc_size);
	if (malloc_result == NULL)
		return (NULL);
	ft_memset(malloc_result, 0, malloc_size);
	return (malloc_result);
}
