/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:12:57 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/30 20:23:51 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*swap_a_sa(t_node *head)
{
	t_node	*node;
	t_node	*temp;

	node = lst_new_node();
	if (node)
	{
		temp = head->next;
		lst_add_value_to_node(node, (head->next)->value);
		lst_add_next_to_node(node, head);
		lst_add_next_to_node(head, (head->next)->next);
		lst_free_node(temp);
		return (write(1, "sa\n", 3), node);
	}
	return (NULL);
}

t_node	*rotate_a_ra(t_node *head)
{
	t_node	*node;
	t_node	*new_head;

	node = lst_new_node();
	if (node)
	{
		new_head = head->next;
		lst_add_value_to_node(node, head->value);
		lst_add_next_to_node(node, NULL);
		lst_add_back(&new_head, node);
		lst_free_node(head);
		return (write(1, "ra\n", 3), new_head);
	}
	return (NULL);
}

t_node	*reverse_rotate_a_rra(t_node *head)
{
	t_node	*node;
	t_node	*new_head;
	t_node	*new_last;

	node = head;
	new_last = lst_second_to_last(head);
	new_head = lst_last(head);
	new_last->next = NULL;
	new_head->next = node;
	return (write(1, "rra\n", 4), new_head);
}
