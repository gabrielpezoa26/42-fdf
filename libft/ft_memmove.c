/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:59:56 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/01/09 16:40:20 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*u;
	unsigned char	*y;
	unsigned int	i;

	y = (unsigned char *)dest;
	u = (unsigned char *)src;
	i = 0;
	if ((y == NULL) && (u == NULL))
		return (NULL);
	if ((y >= u) && (y < u + n))
	{
		while (n > 0)
		{
			y[n - 1] = u[n - 1];
			n--;
		}
	}
	while (i < n)
	{
		y[i] = u[i];
		i++;
	}
	return (dest);
}
