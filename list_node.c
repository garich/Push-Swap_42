/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:51:33 by agarijo-          #+#    #+#             */
/*   Updated: 2023/04/03 22:15:10 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst_new_node(void)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->rank = -1;
	return (new_node);
}

void	lst_add_value_to_node(t_node *node, int add_value)
{
	if (node)
		node->value = add_value;
}

void	lst_add_og_pos_to_node(t_node *node, int add_og_pos)
{
	if (node)
		node->og_position = add_og_pos;
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
