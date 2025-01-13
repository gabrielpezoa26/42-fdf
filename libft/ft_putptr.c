/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:32:06 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/01/09 13:16:03 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_adress(unsigned long n)
{
	char	*hex_digits_lower;
	int		result;

	result = 0;
	hex_digits_lower = "0123456789abcdef";
	if (n >= 16)
		result += ft_print_adress(n / 16);
	result += ft_putchar(hex_digits_lower[n % 16]);
	return (result);
}

int	ft_putptr(void *y)
{
	int	count;

	if (y == 0)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	count += ft_print_adress((unsigned long)y);
	return (count);
}
