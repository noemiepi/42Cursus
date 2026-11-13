/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 09:08:33 by npillet           #+#    #+#             */
/*   Updated: 2025/10/30 12:25:10 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t n)
{
	void	*p;

	if (nmemb == 0 || n == 0)
		return (malloc(0));
	if (nmemb > (SIZE_MAX / n))
		return (NULL);
	p = malloc(nmemb * n);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * n);
	return (p);
}
