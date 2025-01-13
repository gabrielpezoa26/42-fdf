/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:20:01 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/01/09 13:18:57 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr(unsigned int n)
{
	long	num;
	int		count;

	num = (long)n;
	count = 0;
	if (num > 9)
		count += ft_putunbr(num / 10);
	count += ft_putchar(num % 10 + '0');
	return (count);
}
