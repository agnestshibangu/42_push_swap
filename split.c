/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:42:45 by agtshiba          #+#    #+#             */
/*   Updated: 2024/06/18 16:44:24 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*my_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int	count_words(char *str, char delimiter)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == delimiter
				|| str[i] == '\0' || str[i] == '\n'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != delimiter
				&& str[i] != '\0' && str[i] != '\n'))
			i++;
	}
	return (wc);
}

char	*get_next_word(char *str, int *index, char delimiter)
{
	int		start;
	int		end;
	char	*word;

	while (str[*index] && (str[*index] == delimiter
			|| str[*index] == '\t' || str[*index] == '\n'))
		(*index)++;
	start = *index;
	while (str[*index] && (str[*index] != delimiter
			&& str[*index] != '\t' && str[*index] != '\n'))
		(*index)++;
	end = *index;
	if (start == end)
		return (NULL);
	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	my_strncpy(word, &str[start], end - start);
	return (word);
}

void	split_and_copy_words(char **out, char *str, char delimiter)
{
	int		i;
	int		k;
	char	*word;

	i = 0;
	k = 0;
	while (str[i])
	{
		word = get_next_word(str, &i, delimiter);
		if (word)
		{
			out[k] = word;
			k++;
		}
	}
	out[k] = NULL;
}

char	**allocate_words(int wc)
{
	char	**out;

	out = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!out)
		return (NULL);
	return (out);
}
