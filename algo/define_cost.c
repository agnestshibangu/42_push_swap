/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:48:52 by agtshiba          #+#    #+#             */
/*   Updated: 2024/06/20 15:36:06 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	both_nodes_above_median(t_lst *current, int len_a, int len_b)
{
	if (current->above_median && current->target_node->above_median)
	{
		if (current->position > current->target_node->position)
			current->push_cost = current->position;
		else
			current->push_cost = current->target_node->position;
	}
	else if (!current->above_median && !current->target_node->above_median)
	{
		if (len_b - current->position > len_a - current->target_node->position)
			current->push_cost = len_b - current->position;
		else
			current->push_cost = len_a - current->target_node->position;
	}
}

void	define_push_cost(t_lst **a, t_lst **b)
{
	int				len_a;
	int				len_b;
	int				tempcur;
	int				temptar;
	t_lst			*current;

	current = *b;
	len_a = list_size(a);
	len_b = list_size(b);
	tempcur = len_a - current->target_node->position;
	temptar = len_b - current->position;
	while (current)
	{
		if ((current->above_median && current->target_node->above_median)
			|| (!current->above_median && !current->target_node->above_median))
			both_nodes_above_median(current, len_a, len_b);
		else if (current->above_median && !current->target_node->above_median)
			current->push_cost = current->position + tempcur;
		else if (!current->above_median && current->target_node->above_median)
			current->push_cost = temptar + current->target_node->position;
		current = current->next;
	}
}

t_lst	*define_cheapest(t_lst **head)
{
	t_lst	*current;
	t_lst	*cheapest_node;
	long	cheapest;

	current = *head;
	cheapest_node = NULL;
	cheapest = LONG_MAX;
	while (current != NULL)
	{
		if (current->push_cost < cheapest)
		{
			cheapest = current->push_cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	if (cheapest_node != NULL)
		cheapest_node->cheapest = true;
	return (cheapest_node);
}
