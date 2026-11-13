/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:03:17 by npillet           #+#    #+#             */
/*   Updated: 2026/02/12 09:34:50 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// it calculates whether ra or rra operations is cheaper //
// it returns 1 if rra is more effective and 0 if it's ra //
int	ra_rra(int size_a, int i)
{
	if (i <= (size_a / 2) && i != 0)
		return (0);
	return (1);
}

// it calculates whether rb or rrb operations is cheaper //
// it returns 1 if rrb is more effective and 0 if it's rb //
int	rb_rrb(int size_b, int t)
{
	if (t <= (size_b / 2))
		return (0);
	return (1);
}

// it calculates the total number of operation for a number //
// and consider rr and rrr operations in it's calclations //
int	total_cost(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

// it calculates the number of moves to make in //
// order to get in the first position of stack_a //
int	move_up_a(t_stack *stack_a, int i)
{
	int	size_a;

	size_a = stack_size(stack_a);
	if (i <= (size_a / 2))
		return (i);
	else
		return (size_a - i);
}

// it calculates the number of moves to make in //
// order to get in the correcct position of stack_b //
int	move_b(t_stack *stack_b, int value)
{
	int	t;
	int	size;

	t = target_max(stack_b, value);
	size = stack_size(stack_b);
	if (t <= (size / 2))
		return (t);
	else
		return (size - t);
}
