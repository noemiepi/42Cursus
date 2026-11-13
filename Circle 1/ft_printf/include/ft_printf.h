/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:51:10 by npillet           #+#    #+#             */
/*   Updated: 2026/06/26 21:49:52 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/include/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c);
int		ft_lennb(int nb);
int		ft_checkformat(char c, va_list args);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printdec(int n);
int		ft_printundec(unsigned int n);
int		ft_printlowhex(unsigned int n);
int		ft_printuphex(unsigned int n);
int		ft_printptr(void *p);

#endif
