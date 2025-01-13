/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:38:28 by gcesar-n          #+#    #+#             */
/*   Updated: 2024/11/06 18:35:45 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size;
	size_t	i;
	char	*dest_ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest_ptr = malloc(size);
	if (dest_ptr == NULL)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		dest_ptr[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		dest_ptr[i] = *s2;
		i++;
		s2++;
	}
	dest_ptr[i] = '\0';
	return (dest_ptr);
}
