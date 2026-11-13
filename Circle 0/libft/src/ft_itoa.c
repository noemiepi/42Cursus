/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:13:05 by npillet           #+#    #+#             */
/*   Updated: 2025/11/03 15:18:07 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_reverse(char *str, int i)
{
	int		j;
	char	*final;

	j = 0;
	final = malloc(sizeof(char) * (i + 1));
	if (!final)
		return (NULL);
	while (--i >= 0)
	{
		final[j++] = str[i];
	}
	final[j] = '\0';
	return (final);
}

char	*ft_itoa(int n)
{
	char	str[12];
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
	}
	while (n / 10)
	{
		str[i++] = ((n % 10) * sign + '0');
		n /= 10;
	}
	str[i++] = ((n % 10) * sign + '0');
	if (sign == -1)
		str[i++] = '-';
	return (ft_reverse(str, i));
}
