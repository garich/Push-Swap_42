/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:47:48 by agarijo-          #+#    #+#             */
/*   Updated: 2023/04/28 17:14:18 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct ListNode
{
	int					value;
	int					position;
	int					targ_position;
	int					rank;
	struct ListNode		*next;
}	t_node;

// 'list_node.c' FILE functions declarations.
void	lst_add_value_to_node(t_node *node, int add_value);
void	lst_add_pos_to_node(t_node *node, int add_pos);
void	lst_add_targ_pos_to_node(t_node *node, int add_targ_pos);
void	lst_add_rank_to_node(t_node *node, int add_rank);
void	lst_add_next_to_node(t_node *node, t_node *next);

// 'list_utils.c' FILE functions declarations.
t_node	*lst_new_node(void);
void	lst_add_back(t_node **lst, t_node *new);
t_node	*lst_second_to_last(t_node *lst);
t_node	*lst_last(t_node *lst);
int		lst_size(t_node *lst);

// 'list_utils_more.c' FILE functions declarations.
t_node	*fill_list_with_array(int *array, int argc);
void	lst_print(t_node *lst);
void	lst_clear(t_node **lst);
void	lst_free_node(t_node *node);

// 'arguments.c' FILE functions declarations.
int		*manage_array(int *argc, char ***args, char **argv);
char	**split_arguments(char *argv);
int		*check_arguments(int argc, char *argv[]);
int		check_argument_format(char *argument);
int		check_argument_duplicate(int *array_arguments, int size);

// 'array_utils.c' FILE functions declarations.
int		*get_array_weight(int *array, int argc);
void	print_array(char **array);
int		count_array(char **array);
void	free_malloc(void **result_array);

// 'push_swap.c' FILE functions declarations.
int		check_if_in_order(t_node *head);
void	push_swap(int *array, int argc);

// 'ps_algorithms.c' FILE functions declarations.
t_node	*only_two_numbers(t_node *head);
t_node	*only_three_numbers(t_node *head);
t_node	*only_four_numbers(t_node *head);

// 'ps_algorithms_more.c' FILE functions declarations.
t_node	*more_numbers(t_node *head);
void	costs_on_more_numbers(t_node **head_a, t_node **head_b);
void	move_all_to_b(t_node **head_a, t_node **head_b, int *head_size);

// 'ps_rules.c' FILE functions declarations.
// 'swap_a_sa' Swap the first 2 elements at the top of Stack A.
// 		First element becomes the last one.
// 'rotate_a_ra' Shift up all elements of Stack A by 1.
// 		First element becomes the last one.
// 'rotate_b_rb' Shift up all elements of Stack B by 1.
// 		First element becomes the last one.
// 'rotate_a_b_rr'
//		ra and rb at the same time.
t_node	*swap_a_sa(t_node *head);
void	rotate_a_ra(t_node **head, int a_cost);
void	rotate_b_rb(t_node **head, int b_cost);
void	rotate_a_b_rr(t_node **head_a, t_node **head_b, int a_cost, int b_cost);

// 'ps_rules_more.c' FILE functions declarations.
// 'reverse_rotate_a_rra' Shift down all elements of stack a by 1.
// 		Last element becomes the first one.
// 'reverse_rotate_b_rrb' Shift down all elements of stack b by 1.
// 		Last element becomes the first one.
// 'reverse_rotate_a_b_rrr'
//		rra and rrb at the same time.
// 'push_b_pb' Take the first element at the top of Stack A
//		and put it at the top of Stack B.
// 'push_a_pa' Take the first element at the top of Stack B
//		and put it at the top of Stack A.
void	reverse_rotate_a_rra(t_node **head, int a_cost);
void	reverse_rotate_b_rrb(t_node **head, int b_cost);
void	reverse_rotate_a_b_rrr(t_node **head_a, t_node **head_b,
			int a_cost, int b_cost);
void	push_b_pb(t_node **head_a, t_node **head_b);
void	push_a_pa(t_node **head_a, t_node **head_b);

// 'ps_utils.c' FILE functions declarations.
int		check_rank(t_node *head_a, int head_mid);
int		smallest_position(t_node *head);
void	recalculate_position_on_stack(t_node *head);
void	recalculate_position_two_stacks(t_node *head_a, t_node *head_b);
void	set_target_postion_b_stack(t_node *head_a, t_node *head_b);

// 'ps_utils_more.c' FILE functions declarations.
void	execute_lowest_cost(t_node *p_to_less_cost, t_node **head_a,
			t_node **head_b, int head_b_size);
t_node	*calculate_total_cost(t_node *head_a, t_node *head_b, int head_b_size);
int		calculate_head_a_cost(t_node *head_a, t_node *head_b);
int		calculate_head_b_cost(t_node *head, int b_size);
t_node	*find_rank_on_stack(t_node *head, int rank);

#endif