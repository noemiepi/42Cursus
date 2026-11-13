/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:33:19 by npillet           #+#    #+#             */
/*   Updated: 2026/02/02 17:05:34 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// it does the swap operation, it //
// will be the base for the following //
// operations in this file //
static void	swap(t_stack **stack)
{
	int	tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = tmp;
}

// it does the sa operation //
void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

// it does the sb operation //
void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

// it does the ss operation and prints it //
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
