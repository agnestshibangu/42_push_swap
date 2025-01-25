/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_position_target.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:36:13 by agtshiba          #+#    #+#             */
/*   Updated: 2024/06/20 15:34:45 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_lst	*find_best_match(t_lst **a, t_lst *b_node)
{
	t_lst	*current_in_a;
	t_lst	*target_node;
	long	best_match;

	target_node = NULL;
	best_match = LONG_MAX;
	current_in_a = *a;
	while (current_in_a)
	{
		if (current_in_a->nbr > b_node->nbr && current_in_a->nbr < best_match)
		{
			best_match = current_in_a->nbr;
			target_node = current_in_a;
		}
		current_in_a = current_in_a->next;
	}
	if (best_match == LONG_MAX)
		return (find_min(a));
	else
		return (target_node);
}

void	assign_target_node(t_lst **a, t_lst **b)
{
	t_lst	*current_in_b;

	current_in_b = *b;
	while (current_in_b)
	{
		current_in_b->target_node = find_best_match(a, current_in_b);
		current_in_b = current_in_b->next;
	}
}

void	set_current_position(t_lst **head)
{
	t_lst	*current;
	int		i;
	int		median;

	current = *head;
	i = 0;
	median = list_size(head) / 2;
	while (current)
	{
		current->position = i;
		if (i <= median)
			current->above_median = true;
		else
			current->above_median = false;
		current = current->next;
		i++;
	}
}

void	define_nodes_position_a_b(t_lst **a, t_lst **b)
{
	set_current_position(a);
	set_current_position(b);
}
