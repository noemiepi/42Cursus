/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:37:48 by npillet           #+#    #+#             */
/*   Updated: 2025/11/06 16:02:34 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdec(int n)
{
	int	i;

	i = ft_lennb(n);
	if (n == 0)
		i = 1;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		i = 11;
		return (i);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
		i++;
	}
	if (n >= 10)
	{
		ft_printdec(n / 10);
		ft_printdec(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (i);
}
