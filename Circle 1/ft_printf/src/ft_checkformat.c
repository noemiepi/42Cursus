/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:52:22 by npillet           #+#    #+#             */
/*   Updated: 2025/11/06 16:02:11 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkformat(char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_printchar(va_arg(args, int));
	else if (c == 's')
		i += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		i += ft_printptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		i += ft_printdec(va_arg(args, int));
	else if (c == 'u')
		i += ft_printundec(va_arg(args, unsigned int));
	else if (c == 'x')
		i += ft_printlowhex(va_arg(args, unsigned int));
	else if (c == 'X')
		i += ft_printuphex(va_arg(args, unsigned int));
	else if (c == '%')
		i += ft_printchar('%');
	return (i);
}
