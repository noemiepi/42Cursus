/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:10:36 by npillet           #+#    #+#             */
/*   Updated: 2025/10/30 13:07:00 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;
	int	j;

	if (lst == NULL)
		return (NULL);
	i = ft_lstsize(lst);
	j = 0;
	while (++j < i)
		lst = lst->next;
	return (lst);
}
