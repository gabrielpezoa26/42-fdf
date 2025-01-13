/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:46:09 by gcesar-n          #+#    #+#             */
/*   Updated: 2024/11/12 17:25:17 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = (long)n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	if (num > 9)
		ft_putnbr_fd(num / 10, fd);
	write(fd, &((char){num % 10 + '0'}), 1);
}
