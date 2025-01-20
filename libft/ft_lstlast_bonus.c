/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:07:47 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/01/20 16:33:43 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_last(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if (lst->next == NULL)
			lst = lst->next;
	}
	return (lst);
}
