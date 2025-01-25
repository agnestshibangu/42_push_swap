/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:32:00 by agtshiba          #+#    #+#             */
/*   Updated: 2024/06/18 16:00:09 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	append(t_lst **headref, long nbr)
{
	t_lst	*newnode;
	t_lst	*lastnode;

	newnode = (t_lst *)malloc(sizeof(t_lst));
	if (newnode == NULL)
	{
		ft_printf("memory allocation failed\n");
		return ;
	}
	newnode->nbr = nbr;
	newnode->next = NULL;
	newnode->prev = NULL;
	if (*headref == NULL)
	{
		*headref = newnode;
		return ;
	}
	lastnode = *headref;
	while (lastnode->next != NULL)
		lastnode = lastnode->next;
	lastnode->next = newnode;
	newnode->prev = lastnode;
}

t_lst	*create_result(t_lst **head, long nbr, char **result)
{
	int		i;

	i = 0;
	while (result[i])
	{
		check_syntax(result[i]);
		nbr = my_atol(result[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			while (result[i])
			{
				free(result[i]);
				i++;
			}		
			free(result);
			return (NULL);
		}
		append(head, nbr);
		i++;
	}
	free(result);
	return (*head);
}

t_lst	*create_list_split(t_lst **head, int ac, char **av)
{
	char	**result;
	int		i;
	long	nbr;

	nbr = 0;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (NULL);
	else if (ac == 2)
	{
		result = my_split(av[1], ' ');
		if (result == NULL)
			return (NULL);
		i = 0;
		create_result(head, nbr, result);
	}
	return (*head);
}

t_lst	*create_list_normal(t_lst **head, int ac, char **av)
{
	int		y;
	long	nbr;

	y = 1;
	while (y < ac)
	{
		if (check_syntax(av[y]))
		{
			ft_printf("Error\n");
			return (NULL);
		}
		nbr = my_atol(av[y]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			exit_error(head);
			ft_printf("Error\n");
			return (NULL);
		}
		append(head, nbr);
		y++;
	}
	return (*head);
}
