/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:53:01 by agtshiba          #+#    #+#             */
/*   Updated: 2024/06/20 15:40:06 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	my_atol(const char *s)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'
			|| *s == '\v' || *s == '\f' || *s == '\r'))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s && *s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - 48);
		s++;
	}
	return (res * sign);
}

t_lst	*find_min(t_lst **head)
{
	t_lst	*current;
	t_lst	*min_node;
	long	min;

	current = *head;
	min_node = NULL;
	min = INT_MAX;
	while (current != NULL)
	{
		if (current->nbr < min)
		{
			min = current->nbr;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

t_lst	*find_maxi(t_lst **head)
{
	long		max;
	t_lst		*current;
	t_lst		*max_node;

	max_node = NULL;
	current = *head;
	max = INT_MIN;
	while (current != NULL)
	{
		if (current->nbr > max)
		{
			max = current->nbr;
			max_node = current;
		}
		current = current->next;
	}
	return (max_node);
}

int	list_size(t_lst **head)
{
	int			size;
	t_lst		*current;

	current = *head;
	size = 0;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

t_lst	*find_last_node(t_lst **headRef)
{
	t_lst	*last_node;

	last_node = *headRef;
	if (headRef == NULL || *headRef == NULL)
		return (NULL);
	while (last_node->next != NULL)
		last_node = last_node->next;
	return (last_node);
}
