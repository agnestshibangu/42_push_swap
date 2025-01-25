/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:38:08 by agtshiba          #+#    #+#             */
/*   Updated: 2024/06/18 10:42:01 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_lst	*head;
	t_lst	*b;
	t_lst	*a;

	head = NULL;
	b = NULL;
	a = NULL;
	head = create_list(ac, av);
	if (head == NULL)
		return (0);
	if (list_is_sorted(&head))
		return (0);
	if (ac < 2)
		return (0);
	b = create_stack_b(&b);
	a = create_stack_a(&head);
	if (ac == 4)
	{
		sort_three(&a);
		return (0);
	}
	if (!check_doubles(&a))
		return (0);
	push_swap(&a, &b);
	return (0);
}
