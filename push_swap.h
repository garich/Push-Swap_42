/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:47:48 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/31 13:29:00 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// stdlib para exit.
// stdio para printf.
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct ListNode
{
	int					value;
	struct ListNode		*next;
}	t_node;

// 'main.c' FILE functions declarations.
void	leaks(void);

// 'list_utils_more.c' FILE functions declarations.
void	lst_add_value_to_node(t_node *node, int add_value);
void	lst_add_next_to_node(t_node *node, t_node *next);
t_node	*fill_list_with_array(int *array, int argc);
void	lst_print(t_node *lst);
void	lst_clear(t_node **lst);
void	lst_free_node(t_node *node);

// 'list_utils.c' FILE functions declarations.
t_node	*lst_new_node(void);
void	lst_add_back(t_node **lst, t_node *new);
t_node	*lst_second_to_last(t_node *lst);
t_node	*lst_last(t_node *lst);
int		lst_size(t_node *lst);

// 'arguments.c' FILE functions declarations.
char	**split_arguments(char *argv);
int		*check_arguments(int argc, char *argv[]);
int		check_argument_format(char *argument);
int		check_argument_duplicate(int *array_arguments, int size);

// 'push_swap.c' FILE functions declarations.
int		check_if_in_order(t_node *head);
t_node	*only_two_numbers(t_node *head);
t_node	*only_three_numbers(t_node *head);
t_node	*only_five_numbers(t_node *head);
void	push_swap(int *array, int argc);

// 'array_utils.c' FILE functions declarations.
void	print_array(char **array);
int		count_array(char **array);
void	free_malloc(char **result_array);

// 'ps_rules.c' FILE functions declarations. 
// 'swap_a_sa' Swap the first 2 elements at the top of Stack A.
// 		First element becomes the last one.
// 'rotate_a_ra' Shift up all elements of Stack A by 1.
// 		First element becomes the last one.
// 'reverse_rotate_a_rra' Shift down all elements of stack a by 1.
// 		Last element becomes the first one.
// 'push_b_pb' Take the first element at the top of Stack A
//		and put it at the top of Stack B.
t_node	*swap_a_sa(t_node *head);
t_node	*rotate_a_ra(t_node *head);
t_node	*reverse_rotate_a_rra(t_node *head);
void	push_b_pb(t_node **head_a, t_node **head_b);

#endif