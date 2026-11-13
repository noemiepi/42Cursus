/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:46:58 by npillet           #+#    #+#             */
/*   Updated: 2026/02/16 14:42:30 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/include/libft.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

typedef struct s_cost
{
	int	value;
	int	mv_a;
	int	mv_b;
	int	ra;
	int	rb;
	int	tot;
}		t_cost;

/* ----------- PARSING ----------- */
t_stack	*fill_stack_a(int argc, char **argv);
t_stack	*input_validity(t_stack **stack_a, char **argv, int i);
t_stack	*string_validity(t_stack **stack_a, char **tab);

/* ----------- CHECKS ------------ */
int		check_sort(t_stack *stack);
int		check_double(t_stack *stack);
int		only_nb(char *str);

/* ------------ ERROR ------------ */
t_stack	*errorlist(t_stack **stack);
t_stack	*freelist(t_stack **stack);
t_stack	*freetab(char **tab);

/* ------------ STACK ------------ */
t_stack	*create_node(int data);
t_stack	*last_node(t_stack *stack);
t_stack	*prev_last_node(t_stack *stack);
void	insert_end(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);

/* ---------- OPERATIONS --------- */
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/* ------------- SORT ------------ */
void	algorithm(t_stack **stack_a);
void	sort_three(t_stack **stack);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_big(t_stack **stack_a, t_stack **stack_b);

/* ---------- SORT UTILS --------- */
int		move_up_a(t_stack *stack_a, int i);
int		move_b(t_stack *stack_b, int value);
int		ra_rra(int size_a, int i);
int		rb_rrb(int size_b, int value);
int		total_cost(int a, int b);

int		target_max(t_stack *stack_b, int value);
int		stack_min(t_stack *stack);
int		stack_max(t_stack *stack);
int		max_pos(t_stack *stack_b);

/* ------------- COST ------------ */
void	do_rr_or_rrr(t_stack **stack_a, t_stack **stack_b, t_cost *cost);
void	do_cheapest(t_stack **stack_a, t_stack **stack_b, t_cost *cost);
void	calculate_cost(t_stack *stack_a, t_stack *stack_b, t_cost *cost);
int		find_cheapest(t_cost *cost, int size);

void	place_a(t_stack **stack_a, int value);
void	final_sort(t_stack **stack_a);
int		target_min(t_stack *stack_a, int value);
int		min_pos(t_stack *stack_a);

#endif
