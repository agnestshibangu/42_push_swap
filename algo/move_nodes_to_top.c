/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes_to_top.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:02:35 by agtshiba          #+#    #+#             */
/*   Updated: 2024/06/13 16:10:28 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_both_cheapest_to_top(t_lst **a, t_lst **b)
{
	t_lst	*cheapest_b;

	cheapest_b = define_cheapest(b);
	if (cheapest_b->above_median && cheapest_b->target_node->above_median)
	{
		while (*a != cheapest_b->target_node && *b != cheapest_b)
			rr(a, b);
		set_current_position(a);
		set_current_position(b);
	}
	else if (!(cheapest_b->above_median)
		&& !(cheapest_b->target_node->above_median))
	{
		while (*a != cheapest_b->target_node && *b != cheapest_b)
			rrr(a, b);
		set_current_position(a);
		set_current_position(b);
	}
	finish_moving_to_top_b(b);
	finish_moving_to_top_a(a, b);
}

void	finish_moving_to_top_b(t_lst **b)
{
	t_lst	*cheapest_node_in_b;

	cheapest_node_in_b = define_cheapest(b);
	if (cheapest_node_in_b == *b)
		return ;
	if ((*b) != cheapest_node_in_b)
	{
		while ((*b) != cheapest_node_in_b)
		{
			if (cheapest_node_in_b->above_median)
				rb(b);
			else if (!cheapest_node_in_b->above_median)
				rrb(b);
		}
	}
}

void	finish_moving_to_top_a(t_lst **a, t_lst **b)
{
	t_lst	*cheapest_b;

	cheapest_b = define_cheapest(b);
	if (cheapest_b->target_node == *a)
		return ;
	if ((*a) != cheapest_b->target_node)
	{
		while ((*a) != cheapest_b->target_node)
		{
			if (cheapest_b->target_node->above_median)
				ra(a);
			else if (!cheapest_b->target_node->above_median)
				rra(a);
		}
	}
}
