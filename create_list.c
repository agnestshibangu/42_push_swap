/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:52:50 by agtshiba          #+#    #+#             */
/*   Updated: 2024/06/20 15:38:05 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

t_lst	*create_list(int ac, char **av)
{
	t_lst	*head;

	head = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (NULL);
	if (ac == 2)
	{
		if (create_list_split(&head, ac, av) == NULL)
			return (NULL);
	}
	else if (ac > 2)
	{
		if (create_list_normal(&head, ac, av) == NULL)
			return (NULL);
	}
	return (head);
}

t_lst	*create_stack_a(t_lst **head)
{
	t_lst	*a;

	a = *head;
	return (a);
}

t_lst	*create_stack_b(t_lst **head)
{
	t_lst	*b;

	b = *head;
	return (b);
}

int	list_is_sorted(t_lst **head)
{
	t_lst	*current_in_head;

	if (*head == NULL)
		return (1);
	current_in_head = *head;
	while (current_in_head->next != NULL)
	{
		if (current_in_head->nbr > current_in_head->next->nbr)
			return (0);
		current_in_head = current_in_head->next;
	}
	return (1);
}
