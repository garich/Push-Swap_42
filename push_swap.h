/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:47:48 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/22 17:09:30 by agarijo-         ###   ########.fr       */
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

int		*check_arguments(int argc, char *argv[]);
int		check_argument_format(char *argument);
int		check_argument_duplicate(int *array_arguments);
void	push_swap(void);
void	lst_print(t_node *lst);
void	lst_clear(t_node **lst);
void	lst_free_node(t_node *node);
int		lst_size(t_node *lst);
t_node	*lst_last(t_node *lst);
void	lst_add_back(t_node **lst, t_node *new);
void	lst_add_value_to_node(t_node *node, int add_value);
t_node	*lst_new_node(void);

#endif