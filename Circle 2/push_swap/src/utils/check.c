/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:32:24 by npillet           #+#    #+#             */
/*   Updated: 2026/02/16 16:04:24 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// it checks if the stack is sorted: //
// it returns 1 for yes and 0 for no //
int	check_sort(t_stack *stack)
{
	int	i;

	i = INT_MIN;
	while (stack != NULL)
	{
		if (i < stack->data)
			i = stack->data;
		else
			return (0);
		stack = stack->next;
	}
	return (1);
}

// it checks if the argument is already present: //
// it returns 1 for yes and 0 for no //
int	check_double(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	stack = stack->next;
	while (current->next != NULL)
	{
		stack = current->next;
		while (stack != NULL)
		{
			if (current->data == stack->data)
				return (1);
			stack = stack->next;
		}
		current = current->next;
	}
	return (0);
}

// it checks if the argument is only composed of numbers: //
// it returns 1 for yes and 0 for no //
int	only_nb(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			i++;
			sign++;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	if (sign == i)
		return (0);
	return (1);
}
