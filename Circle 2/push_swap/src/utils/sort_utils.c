/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:48:51 by npillet           #+#    #+#             */
/*   Updated: 2026/02/12 10:08:34 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// it defines the maximum value of a stack //
int	stack_max(t_stack *stack)
{
	t_stack	*tmp;
	int		max;

	tmp = stack;
	if (tmp == NULL)
		return (0);
	max = tmp->data;
	while (tmp->next != NULL)
	{
		if (max < tmp->next->data)
			max = tmp->next->data;
		tmp = tmp->next;
	}
	if (max < tmp->data)
		max = tmp->data;
	return (max);
}

// it defines the minimum value of a stack //
int	stack_min(t_stack *stack)
{
	t_stack	*tmp;
	int		min;

	tmp = stack;
	if (tmp == NULL)
		return (0);
	min = tmp->data;
	while (tmp->next != NULL)
	{
		if (min > tmp->next->data)
			min = tmp->next->data;
		tmp = tmp->next;
	}
	if (min > tmp->data)
		min = tmp->data;
	return (min);
}

// it gets the position of the maximum value of a stack //
int	max_pos(t_stack *stack_b)
{
	int		i;
	t_stack	*curr;
	int		max;
	int		pos;

	curr = stack_b;
	max = curr->data;
	pos = 0;
	i = 0;
	while (curr)
	{
		if (curr->data > max)
		{
			max = curr->data;
			pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (pos);
}

// it get the position of the wanted number in stack_b //
int	target_max(t_stack *stack_b, int value)
{
	t_stack	*tmp;
	int		bigger;
	int		pos;
	int		i;

	if (stack_b == NULL)
		return (0);
	tmp = stack_b;
	bigger = INT_MAX;
	pos = 0;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->data > value && tmp->data < bigger)
		{
			bigger = tmp->data;
			pos = i + 1;
		}
		tmp = tmp->next;
		i++;
	}
	if (bigger == INT_MAX)
		pos = max_pos(stack_b);
	return (pos);
}
