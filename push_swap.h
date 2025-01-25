/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:28:44 by agtshiba          #+#    #+#             */
/*   Updated: 2024/06/19 16:59:46 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include "./my_printf/ft_printf.h"

typedef struct s_lst
{
	long			nbr;
	long			push_cost;
	bool			cheapest;
	bool			above_median;
	int				position;
	int				nb;
	int				index;
	int				cost;
	int				total_cost;
	struct s_lst	*next;
	struct s_lst	*prev;
	struct s_lst	*target_node;
}					t_lst;

// FUNCTIONS
// UTILS
char	*my_strncpy(char *s1, char *s2, int n);
char	*my_strncpy(char *s1, char *s2, int n);
int		count_words(char *str, char delimiter);
char	*get_next_word(char *str, int *index, char delimiter);
void	split_and_copy_words(char **out, char *str, char delimiter);
char	**allocate_words(int wc);
void	split_words(char **out, char *str, char delimiter);
char	**my_split(char *str, char delimiter);
long	my_atol(const char *s);

// UTILS PUSHSWAP
t_lst	*find_maxi(t_lst **head);
t_lst	*find_min(t_lst **head);
t_lst	*find_last_node(t_lst **headRef);
int		list_size(t_lst **head);
void	sort_after_push(t_lst **head);

// DEBBUG
void	printList(t_lst **head);
void	display_prev_values(t_lst **head);
void	debugPrintList(t_lst **head);
int		if_list_is_sorted(t_lst **head);
void	printf_for_shell_debbug(t_lst **a, t_lst **b);

// INIT
void	append(t_lst **headRef, long nbr);
t_lst	*create_small_list(char *av);
t_lst	*create_list(int ac, char **av);
t_lst	*create_stack_a(t_lst **head);
t_lst	*create_stack_b(t_lst **head);

// ACTIONS
// rotate
void	rotate(t_lst **head);
void	ra(t_lst **a);
void	rb(t_lst **b);
void	rr(t_lst **a, t_lst **b);

// rev_rotate
void	rev_rotate(t_lst **head);
void	rra(t_lst **a);
void	rrb(t_lst **b);
void	rrr(t_lst **a, t_lst **b);

// push
void	push(t_lst **src, t_lst **dst);
void	pab(t_lst **a, t_lst **b);
void	pba(t_lst **a, t_lst **b);
// swap
void	swap(t_lst **head);
void	sa(t_lst **a);
void	sb(t_lst **b);
void	ss(t_lst **a, t_lst **b);

// sort_three
void	sort_three(t_lst **a);
int		list_is_sorted(t_lst **head);

// free
void	free_list(t_lst **head);

// [[[algo]]] ---> (push_swap.c) 
void	push_a_nodes_to_b(t_lst **a, t_lst **b);
int		define_moy(t_lst **a);
// define the push cost for a and b
// void    define_push_cost(t_lst **head);
// void    define_push_cost(t_lst **a, t_lst **b);
void	define_push_cost_a_b(t_lst **a, t_lst **b);
// define the position for a and b
void	set_current_position(t_lst **head);
void	define_nodes_position(t_lst **head);
void	define_nodes_position_a_b(t_lst **a, t_lst **b);
// for both stacks, define which nodes are above the median in a and b
void	is_above_median(t_lst **head);
void	define_is_above_median_a_b(t_lst **a, t_lst **b);
// assigne a target for b nodes
void	assign_target_node(t_lst **a, t_lst **b);
// define cheapest
t_lst	*define_cheapest(t_lst **head);
void	define_push_cost_a_b(t_lst **a, t_lst **b);
//void define_cheapest_in_both_stack(t_lst **a, t_lst **b);
void	define_push_cost(t_lst **a, t_lst **b);
// check the two cheapest nodes in a and b
// void check_two_cheapest_after_def(t_lst **a, t_lst **b);
void	push_swap(t_lst **a, t_lst **b);
void	define_combined_cost(t_lst **head);

// // [[[algo]]] ---> (push_swap2.c)
void	reinitialise_before_next_move(t_lst **a, t_lst **b);
void	move_cheapest_to_top(t_lst **head);
t_lst	*find_target_to_move(t_lst **a, t_lst **b);
void	once_on_top_push_b_to_a(t_lst **a, t_lst **b);
void	move_cheapest_to_top_a(t_lst **a, t_lst **b);

// init_list.c
t_lst	*create_list_split(t_lst **head, int ac, char **av);
t_lst	*create_list_normal(t_lst **head, int ac, char **av);

// move nodes to top
void	rotate_both(t_lst **a, t_lst **b, t_lst *cheapest);
// void	rr_both(t_lst **a, t_lst **b, t_lst *cheapest);
void	move_both_cheapest_to_top(t_lst **a, t_lst **b);

// errors 

int		check_doubles(t_lst **head);
int		check_syntax(char *str_nbr);
// int check_errors(t_lst **head);
int		check_valid_caracters(t_lst **head);
int		exit_error(t_lst **head);

void	move_both_cheapest_to_top(t_lst **a, t_lst **b);
void	finish_moving_to_top_b(t_lst **b);
void	finish_moving_to_top_a(t_lst **a, t_lst **b);
void	free_list(t_lst **head);

#endif
