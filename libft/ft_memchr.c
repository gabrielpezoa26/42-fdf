/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:03:44 by gcesar-n          #+#    #+#             */
/*   Updated: 2024/11/12 17:24:43 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*y;
	size_t			i;

	i = 0;
	y = (unsigned char *)s;
	c = (unsigned char)c;
	while (i < n)
	{
		if (y[i] == c)
			return ((unsigned char *)&y[i]);
		i++;
	}
	return (NULL);
}
