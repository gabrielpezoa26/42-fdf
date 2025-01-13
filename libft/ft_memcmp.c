/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:43:47 by gcesar-n          #+#    #+#             */
/*   Updated: 2024/11/12 17:24:50 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*y;
	unsigned char	*u;

	u = (unsigned char *)s2;
	y = (unsigned char *)s1;
	i = 0;
	while (i < n)
	{
		if (y[i] != u[i])
			return (y[i] - u[i]);
		i++;
	}
	return (0);
}
