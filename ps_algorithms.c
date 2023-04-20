/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:48:00 by agarijo-          #+#    #+#             */
/*   Updated: 2023/04/19 17:51:37 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*only_two_numbers(t_node *head)
{
	t_node	*node;

	node = NULL;
	node = swap_a_sa(head);
	recalculate_position_on_stack(node);
	if (node)
		return (node);
	return (write(2, "Error\n", 6), NULL);
}

t_node	*only_three_numbers(t_node *head)
{
	t_node	*node;

	node = head;
	while (!check_if_in_order(node))
	{
		if ((node->value > node->next->value)
			&& (node->next->value < node->next->next->value)
			&& node->next->next->value < node->value)
			rotate_a_ra(&node, 0);
		else if ((node->value < node->next->value)
			&& (node->next->value > node->next->next->value)
			&& node->next->next->value < node->value)
			reverse_rotate_a_rra(&node, 0);
		else
			node = swap_a_sa(node);
	}
	recalculate_position_on_stack(node);
	if (node)
		return (node);
	return (write(2, "Error\n", 6), NULL);
}

t_node	*only_four_numbers(t_node *head)
{
	t_node	*head_b;
	int		smallest_place;

	head_b = NULL;
	smallest_place = smallest_position(head);
	if (smallest_place == 1)
		head = swap_a_sa(head);
	else if (smallest_place == 2)
	{
		rotate_a_ra(&head, 0);
		rotate_a_ra(&head, 0);
	}
	else if (smallest_place == 3)
	{
		reverse_rotate_a_rra(&head, 0);
	}
	push_b_pb(&head, &head_b);
	head = only_three_numbers(head);
	push_a_pa(&head, &head_b);
	lst_clear(&head_b);
	recalculate_position_on_stack(head);
	if (head)
		return (head);
	return (write(2, "Error\n", 6), NULL);
}
