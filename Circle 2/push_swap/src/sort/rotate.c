/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:33:16 by npillet           #+#    #+#             */
/*   Updated: 2026/02/11 12:13:27 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// it does a rotate operation, it //
// will be the base for the following //
// operations in this file //
static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tail = last_node(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

// it does the ra operation and prints it //
void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

// it does the rb operation and prints it //
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

// it does the rr operation and prints it //
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
