/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:35:51 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/01/09 13:11:54 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlength(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while ((s[i] != '\0') || s[i] == (char)c)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	dest = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if ((dest == NULL) || (s == NULL))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	if (!s)
	{
		return (NULL);
	}
	if ((size_t)start >= ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[start + i] && i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
