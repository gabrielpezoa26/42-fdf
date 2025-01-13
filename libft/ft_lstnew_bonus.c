/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:19:41 by gcesar-n          #+#    #+#             */
/*   Updated: 2024/12/03 17:17:25 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*mango_loko;

	mango_loko = malloc(sizeof(t_list));
	if (mango_loko == NULL)
	{
		return (NULL);
	}
	mango_loko->content = content;
	mango_loko->next = NULL;
	return (mango_loko);
}
