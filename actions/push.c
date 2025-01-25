/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:38:28 by agtshiba          #+#    #+#             */
/*   Updated: 2024/06/11 11:39:59 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_lst **src, t_lst **dst)
{
	t_lst	*top_src;

	if (!*src)
		return ;
	top_src = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	top_src->prev = NULL;
	if (!*dst)
	{
		*dst = top_src;
		top_src->next = NULL;
	}
	else
	{
		top_src->next = *dst;
		top_src->next->prev = top_src;
		*dst = top_src;
	}
}

// push a vers b 
void	pab(t_lst **a, t_lst **b)
{
	push(a, b);
	ft_printf("pb\n");
}

// push b vers a
void	pba(t_lst **a, t_lst **b)
{
	push(b, a);
	ft_printf("pa\n");
}
