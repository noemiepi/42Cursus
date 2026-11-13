/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:13:57 by npillet           #+#    #+#             */
/*   Updated: 2026/02/16 14:42:25 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// it gets the position of the minimum value in a stack //
int	min_pos(t_stack *stack_a)
{
	t_stack	*tmp;
	int		min;
	int		max;
	int		pos;
	int		i;

	tmp = stack_a;
	min = tmp->data;
	max = tmp->data;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->data <= min)
		{
			min = tmp->data;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

// it get the position of the wanted number in stack_a //
int	target_min(t_stack *stack_a, int value)
{
	t_stack	*tmp;
	int		smallest;
	int		pos;
	int		i;

	if (stack_a == NULL)
		return (0);
	tmp = stack_a;
	smallest = INT_MIN;
	pos = 0;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->data < value && tmp->data > smallest)
		{
			smallest = tmp->data;
			pos = i + 1;
		}
		tmp = tmp->next;
		i++;
	}
	if (smallest == INT_MIN)
		pos = min_pos(stack_a);
	return (pos);
}

// it help place back in the correct //
// position the elements of stack_a //
void	place_a(t_stack **stack_a, int value)
{
	int	move;
	int	size;
	int	pos;

	size = stack_size(*stack_a);
	pos = target_min(*stack_a, value);
	if (pos <= (size / 2))
	{
		move = pos;
		while (move-- > 0)
			ra(stack_a);
	}
	else
	{
		move = size - pos;
		while (move-- > 0)
			rra(stack_a);
	}
}

// it will finish sorting stack_a if //
// it's not done once outside the loop //
void	final_sort(t_stack **stack_a)
{
	int	size;
	int	min;

	if (check_sort(*stack_a) == 1)
		return ;
	size = stack_size(*stack_a);
	min = min_pos(*stack_a);
	if (min <= (size / 2))
	{
		while (min-- > 0)
			ra(stack_a);
	}
	else
	{
		while (min++ < size)
			rra(stack_a);
	}
}
