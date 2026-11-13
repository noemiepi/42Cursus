/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:14:16 by npillet           #+#    #+#             */
/*   Updated: 2026/02/16 11:10:31 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// it checks if the input is valid and add it to a chained list //
// if so and sends an error message while freeing the stack //
// and returning 0 if not //
t_stack	*input_validity(t_stack **stack_a, char **argv, int i)
{
	t_stack	*new;
	long	nb;

	if (only_nb(argv[i]) == 0)
		return (0);
	nb = ft_atol(argv[i]);
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	new = create_node(ft_atol(argv[i]));
	if (new == NULL)
		return (NULL);
	insert_end(stack_a, new);
	return (new);
}

// it checks if the input in the stringis valid and add it //
// to a chained list if so and sends an error message while //
// freeing the stack and returning 0 if not //
t_stack	*string_validity(t_stack **stack_a, char **tab)
{
	t_stack	*new;
	long	nb;
	int		i;

	i = 0;
	while (tab[i])
	{
		if (only_nb(tab[i]) == 0)
			return (0);
		nb = ft_atol(tab[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (0);
		new = create_node(nb);
		if (new == NULL)
			return (NULL);
		insert_end(stack_a, new);
		i++;
	}
	return (*stack_a);
}

// it fills stack_a before the sort. the function will stop //
// if there's only one argument or if the input validity //
// function returns 0 with an error message and the stack //
// will be freed. otherwise, it will return the stack //
t_stack	*fill_stack_a(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**tab;
	int		i;

	stack_a = NULL;
	i = 0;
	while (argc > ++i)
	{
		if (ft_strchr(argv[i], ' '))
		{
			tab = ft_split(argv[i], ' ');
			if (!string_validity(&stack_a, tab) || !tab)
				return (freetab(tab), freelist(&stack_a));
			freetab(tab);
		}
		else
		{
			if (input_validity(&stack_a, argv, i) == 0)
				return (freelist(&stack_a));
		}
	}
	if (check_double(stack_a) == 1)
		return (freelist(&stack_a));
	return (stack_a);
}
