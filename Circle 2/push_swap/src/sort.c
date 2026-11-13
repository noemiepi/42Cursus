/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:38:52 by npillet           #+#    #+#             */
/*   Updated: 2026/02/16 16:07:10 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// it reunites all sorting functions and uses them appropriatly //
void	algorithm(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		size;

	stack_b = NULL;
	size = stack_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, &stack_b);
	else if (size == 5)
		sort_five(stack_a, &stack_b);
	else
		sort_big(stack_a, &stack_b);
	freelist(&stack_b);
}

// it will sort a stack of three int in ascending //
// order with a minimal number of operations completed //
// i corresponds to the data in first position, j is the //
// data in second position and k is data in third position//
void	sort_three(t_stack **stack)
{
	t_stack	*tmp;
	int		i;
	int		j;
	int		k;

	tmp = *stack;
	i = tmp->data;
	j = tmp->next->data;
	k = tmp->next->next->data;
	if (((i > j && i > k) || (i < j && i < k)) && j > k)
	{
		sa(stack);
		if (j > i && j > k)
			ra(stack);
		else
			rra(stack);
	}
	else if (k > i && k > j)
		sa(stack);
	else if (i > j && i > k)
		ra(stack);
	else if (j > i && j > k)
		rra(stack);
}

// it will sort a stack of four int in ascending //
// order with a minimal number of operations completed //
void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		size;
	int		min;
	int		i;

	tmp = *stack_a;
	size = stack_size(*stack_a);
	min = stack_min(*stack_a);
	i = min_pos(*stack_a);
	if (i > (size / 2))
	{
		while (i++ < size)
			rra(stack_a);
	}
	else
	{
		while (i-- > 0)
			ra(stack_a);
	}
	pb(stack_a, stack_b);
	if (check_sort(*stack_a) == 0)
		sort_three(stack_a);
	place_a(stack_a, (*stack_b)->data);
	pa(stack_a, stack_b);
	final_sort(stack_a);
}

// it will sort a stack of five int in ascending //
// order with a minimal number of operations completed //
void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if ((*stack_b)->next->data > (*stack_b)->data)
		rb(stack_b);
	if (check_sort(*stack_a) == 0)
		sort_three(stack_a);
	while (*stack_b != NULL)
	{
		place_a(stack_a, (*stack_b)->data);
		pa(stack_a, stack_b);
	}
	final_sort(stack_a);
}

// it will sort a stack of over five int in ascending //
// order with a minimal number of operations completed //
void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	t_cost	*cost;
	int		cheapest;
	int		size;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (stack_size(*stack_a) > 3)
	{
		size = stack_size(*stack_a);
		cost = malloc(sizeof(t_cost) * size);
		if (cost == NULL)
			return ;
		calculate_cost(*stack_a, *stack_b, cost);
		cheapest = find_cheapest(cost, size);
		do_cheapest(stack_a, stack_b, &cost[cheapest]);
		free(cost);
	}
	if (check_sort(*stack_a) == 0)
		sort_three(stack_a);
	while (*stack_b != NULL)
	{
		place_a(stack_a, (*stack_b)->data);
		pa(stack_a, stack_b);
	}
	final_sort(stack_a);
}
