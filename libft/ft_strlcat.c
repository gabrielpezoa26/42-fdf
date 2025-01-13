/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:16:31 by gcesar-n          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:59 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dest;
	size_t	size_src;
	size_t	i;
	size_t	j;

	size_dest = 0;
	size_src = 0;
	while (dst[size_dest] && size_dest < size)
		size_dest++;
	while (src[size_src])
		size_src++;
	if (size_dest >= size)
		return (size_dest + size_src);
	i = size_dest;
	j = 0;
	while (src[j] != '\0' && i + 1 < (size))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (size_dest + size_src);
}
