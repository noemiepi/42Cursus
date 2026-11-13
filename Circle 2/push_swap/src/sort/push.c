/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:33:08 by npillet           #+#    #+#             */
/*   Updated: 2026/02/11 12:12:39 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// it does the pa operation and prints it //
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	if ((*stack_a) != NULL)
		tmp->next = *stack_a;
	else
		tmp->next = NULL;
	*stack_a = tmp;
	ft_printf("pa\n");
}

// it does the pb operation and prints it //
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if ((*stack_a) == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	if ((*stack_b) != NULL)
		tmp->next = *stack_b;
	else
		tmp->next = NULL;
	*stack_b = tmp;
	ft_printf("pb\n");
}
