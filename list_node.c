/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:51:33 by agarijo-          #+#    #+#             */
/*   Updated: 2023/04/11 16:18:31 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_add_value_to_node(t_node *node, int add_value)
{
	if (node)
		node->value = add_value;
}

void	lst_add_pos_to_node(t_node *node, int add_pos)
{
	if (node)
		node->position = add_pos;
}

void	lst_add_targ_pos_to_node(t_node *node, int add_targ_pos)
{
	if (node)
		node->targ_position = add_targ_pos;
}

void	lst_add_rank_to_node(t_node *node, int add_rank)
{
	if (node)
		node->rank = add_rank;
}

void	lst_add_next_to_node(t_node *node, t_node *next)
{
	if (node)
		node->next = next;
}
