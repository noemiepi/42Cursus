/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlowhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:45:39 by npillet           #+#    #+#             */
/*   Updated: 2025/11/06 16:02:49 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printlowhex(unsigned int n)
{
	char	*base;
	char	str[16];
	int		i;
	int		count;

	base = "0123456789abcdef";
	i = 0;
	if (n == 0)
		return (ft_printchar('0'));
	while (n > 0)
	{
		str[i] = base[n % 16];
		n /= 16;
		i++;
	}
	count = 0;
	while (i > 0)
	{
		i--;
		count += ft_printchar(str[i]);
	}
	return (count);
}
