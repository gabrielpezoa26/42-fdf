/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:07:47 by gcesar-n          #+#    #+#             */
/*   Updated: 2024/12/05 14:19:30 by gcesar-n         ###   ########.fr       */
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
