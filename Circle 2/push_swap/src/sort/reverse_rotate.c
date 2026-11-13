/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:33:13 by npillet           #+#    #+#             */
/*   Updated: 2026/02/11 12:13:14 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// it does a reverse rotate operation, //
// it will be the base for the following //
// operations in this file //
static void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*prev_tail;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tail = last_node(*stack);
	prev_tail = prev_last_node(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	prev_tail->next = NULL;
}

// it does the rra operation and prints it //
void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

// it does the rrb operation and prints it //
void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

// it does the rrr operation and prints it //
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
