/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:51:19 by agtshiba          #+#    #+#             */
/*   Updated: 2024/06/20 15:33:08 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_lst **head)
{
	t_lst	*first_node;
	t_lst	*next;
	int		tmp_index;
	int		tmp_nbr;

	first_node = *head;
	next = first_node->next;
	if (list_size(head) < 2)
		return ;
	if (!head || !next)
		return ;
	tmp_index = first_node->index;
	tmp_nbr = first_node->nbr;
	first_node->index = next->index;
	first_node->nbr = next->nbr;
	next->index = tmp_index;
	next->nbr = tmp_nbr;
}

void	sa(t_lst **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_lst **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_lst **a, t_lst **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
