/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:42:09 by npillet           #+#    #+#             */
/*   Updated: 2026/02/16 14:13:13 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_cheapest(t_cost *cost, int size)
{
	int	cheapest;
	int	i;

	i = 1;
	cheapest = 0;
	while (i < size)
	{
		if (cost[i].tot < cost[cheapest].tot)
			cheapest = i;
		i++;
	}
	return (cheapest);
}

// it will calculate the total number of //
// operations needed to sort a stack the //
// correct position using the functions above //
void	calculate_cost(t_stack *stack_a, t_stack *stack_b, t_cost *cost)
{
	t_stack	*curr;
	int		target;
	int		i;

	curr = stack_a;
	i = 0;
	while (curr != NULL)
	{
		cost[i].value = curr->data;
		cost[i].mv_a = move_up_a(stack_a, i);
		cost[i].mv_b = move_b(stack_b, cost[i].value);
		cost[i].ra = ra_rra(stack_size(stack_a), i);
		target = target_max(stack_b, curr->data);
		cost[i].rb = rb_rrb(stack_size(stack_b), target);
		if (cost[i].ra == cost[i].rb)
			cost[i].tot = total_cost(cost[i].mv_a, cost[i].mv_b);
		else
			cost[i].tot = cost[i].mv_a + cost[i].mv_b;
		curr = curr->next;
		i++;
	}
}

// it applies the rr or rrr options when possible //
void	do_rr_or_rrr(t_stack **stack_a, t_stack **stack_b, t_cost *cost)
{
	if (cost->ra == 0)
	{
		while (cost->mv_a > 0 && cost->mv_b > 0)
		{
			rr(stack_a, stack_b);
			cost->mv_a--;
			cost->mv_b--;
		}
	}
	else
	{
		while (cost->mv_a > 0 && cost->mv_b > 0)
		{
			rrr(stack_a, stack_b);
			cost->mv_a--;
			cost->mv_b--;
		}
	}
}

// it executes the cheapest action possible //
void	do_cheapest(t_stack **stack_a, t_stack **stack_b, t_cost *cost)
{
	if (cost->rb == cost->ra && cost->mv_a != 0)
		do_rr_or_rrr(stack_a, stack_b, cost);
	while (cost->mv_b > 0)
	{
		if (cost->rb == 0)
			rb(stack_b);
		else
			rrb(stack_b);
		cost->mv_b--;
	}
	while (cost->mv_a > 0)
	{
		if (cost->ra == 0)
			ra(stack_a);
		else
			rra(stack_a);
		cost->mv_a--;
	}
	pb(stack_a, stack_b);
}
