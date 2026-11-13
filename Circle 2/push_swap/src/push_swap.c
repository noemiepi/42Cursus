/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:25:31 by npillet           #+#    #+#             */
/*   Updated: 2026/02/16 12:59:30 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// this is the main, it's where the magic happens //
int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc == 1)
		return (1);
	stack_a = fill_stack_a(argc, argv);
	if (stack_a == NULL)
	{
		errorlist(&stack_a);
		return (1);
	}
	if (check_sort(stack_a) == 0)
		algorithm(&stack_a);
	freelist(&stack_a);
	return (0);
}
