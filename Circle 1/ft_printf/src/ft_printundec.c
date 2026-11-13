/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printundec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:45:25 by npillet           #+#    #+#             */
/*   Updated: 2025/11/06 16:03:28 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printundec(unsigned int n)
{
	int	i;

	if ((int)n < 0)
		i = 10;
	else if (n == 0)
		i = 1;
	else
		i = ft_lennb(n);
	if (n >= 10)
	{
		ft_printundec(n / 10);
		ft_printundec(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (i);
}
