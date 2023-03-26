/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:47:48 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/27 00:05:05 by agarijo-         ###   ########.fr       */
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
void	lst_add_next_to_node(t_node *node, t_node *next);
t_node	*fill_list_with_array(int *array, int argc);
void	lst_print(t_node *lst);
void	lst_clear(t_node **lst);
void	lst_free_node(t_node *node);

// 'list_utils.c' FILE functions declarations.
t_node	*lst_new_node(void);
void	lst_add_value_to_node(t_node *node, int add_value);
void	lst_add_back(t_node **lst, t_node *new);
t_node	*lst_last(t_node *lst);
int		lst_size(t_node *lst);

// 'arguments.c' FILE functions declarations.
char	**split_arguments(char *argv);
int		*check_arguments(int argc, char *argv[]);
int		check_argument_format(char *argument);
int		check_argument_duplicate(int *array_arguments);

// 'push_swap.c' FILE functions declarations.
void	push_swap(int *array, int argc);

// 'array_utils.c' FILE functions declarations.
void	print_array(char **array);
int		count_array(char **array);
void	free_malloc(char **result_array);

#endif