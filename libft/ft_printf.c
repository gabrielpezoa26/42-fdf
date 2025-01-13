/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:08:55 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/09 13:15:48 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_verify_type(const char id, va_list arg_box)
{
	int	result;

	result = 0;
	if (id == 'c')
		result += ft_putchar((unsigned char)va_arg(arg_box, int));
	if (id == 's')
		result += ft_putstr(va_arg(arg_box, char *));
	if (id == 'p')
		result += ft_putptr(va_arg(arg_box, void *));
	if (id == 'd')
		result += ft_putnbr(va_arg(arg_box, int));
	if (id == 'i')
		result += ft_putnbr(va_arg(arg_box, int));
	if (id == 'u')
		result += ft_putunbr(va_arg(arg_box, unsigned int));
	if (id == 'x')
		result += ft_print_hex_lower(va_arg(arg_box, unsigned int));
	if (id == 'X')
		result += ft_print_hex_upper(va_arg(arg_box, unsigned int));
	if (id == '%')
		result += ft_putchar('%');
	return (result);
}

int	ft_printf(const char *format, ...)
{
	char	*type;
	va_list	arg_box;
	int		index;
	int		arg_counter;

	type = "cspdiuxX%";
	index = 0;
	arg_counter = 0;
	va_start(arg_box, format);
	while (format[index] != '\0')
	{
		if ((format[index] == '%') && ft_strchr(type, format[index + 1]))
		{
			arg_counter += ft_verify_type(format[index + 1], arg_box);
			index++;
		}
		else
			arg_counter += ft_putchar(format[index]);
		index++;
	}
	va_end(arg_box);
	return (arg_counter);
}
