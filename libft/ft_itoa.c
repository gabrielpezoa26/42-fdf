/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:46:09 by gcesar-n          #+#    #+#             */
/*   Updated: 2024/11/12 16:54:40 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_calculate_len(int value)
{
	size_t	size;

	size = 0;
	if (value == 0)
		return (1);
	else if (value < 0)
	{
		value *= -1;
		size++;
	}
	while (value > 0)
	{
		value /= 10;
		size++;
	}
	return (size);
}

static void	ft_convert_to_str(char *string, unsigned int num, size_t len)
{
	size_t	index;

	index = len - 1;
	while (num > 0)
	{
		string[index] = (num % 10) + '0';
		num /= 10;
		index--;
	}
}

char	*ft_itoa(int n)
{
	size_t			len;
	unsigned int	num;
	char			*result;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_calculate_len(n);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == 0)
		return (NULL);
	result[len] = '\0';
	if (n == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (n < 0)
	{
		result[0] = '-';
		num = -n;
	}
	else
		num = n;
	ft_convert_to_str(result, num, len);
	return (result);
}
