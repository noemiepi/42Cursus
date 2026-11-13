/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuphex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:24:08 by npillet           #+#    #+#             */
/*   Updated: 2025/11/06 16:03:35 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printuphex(unsigned int n)
{
	char	*base;
	char	str[16];
	int		i;
	int		count;

	base = "0123456789ABCDEF";
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
