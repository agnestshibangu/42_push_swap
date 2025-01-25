/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:36:16 by agtshiba          #+#    #+#             */
/*   Updated: 2024/06/18 16:40:21 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_words(char **out, char *str, char delimiter)
{
	split_and_copy_words(out, str, delimiter);
}

char	**my_split(char *str, char delimiter)
{
	int		wc;
	char	**out;

	wc = count_words(str, delimiter);
	out = allocate_words(wc);
	if (!out)
		return (NULL);
	split_words(out, str, delimiter);
	return (out);
}
