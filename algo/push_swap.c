/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:35:17 by agtshiba          #+#    #+#             */
/*   Updated: 2024/06/20 15:36:47 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	define_moy(t_lst **a)
{
	long			min;
	long			max;
	long			average;

	min = find_min(a)->nbr;
	max = find_maxi(a)->nbr;
	average = (min + max) / 2;
	return (average);
}

void	push_a_nodes_to_b_above_moy(t_lst **a, t_lst **b)
{
	int				i;
	int				stack_len;
	long			moy;
	t_lst			*current_in_a;

	moy = define_moy(a);
	if (!a || !*a)
		return ;
	stack_len = list_size(a);
	i = 0;
	while (i < stack_len)
	{
		current_in_a = *a;
		if (current_in_a->nbr > moy)
			pab(a, b);
		else
			ra(a);
		i++;
	}
}

void	push_a_nodes_to_b(t_lst **a, t_lst **b)
{
	int	stack_a_len;

	stack_a_len = list_size(a);
	while (stack_a_len > 3)
	{
		pab(a, b);
		stack_a_len--;
	}
}

void	reinitialise_before_next_move(t_lst **a, t_lst **b)
{
	assign_target_node(a, b);
	define_nodes_position_a_b(a, b);
	define_push_cost(a, b);
	define_cheapest(b);
}

void	push_swap(t_lst **a, t_lst **b)
{
	t_lst	*min_node;

	push_a_nodes_to_b_above_moy(a, b);
	push_a_nodes_to_b(a, b);
	sort_three(a);
	while (*b)
	{
		reinitialise_before_next_move(a, b);
		move_both_cheapest_to_top(a, b);
		pba(a, b);
	}
	min_node = find_min(a);
	if (min_node->above_median)
	{
		while (*a != min_node)
			ra(a);
	}
	else
	{
		while (*a != min_node)
			rra(a);
	}
	free_list(a);
}
