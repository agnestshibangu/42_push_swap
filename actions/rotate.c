/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:43:43 by agtshiba          #+#    #+#             */
/*   Updated: 2024/06/11 11:46:01 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_lst **head)
{
	t_lst	*last_node;

	if (!*head || !(*head)->next)
		return ;
	last_node = find_last_node(head);
	last_node->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_lst **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_lst **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_lst **a, t_lst **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
