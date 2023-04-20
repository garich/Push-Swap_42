/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rules_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:10:34 by agarijo-          #+#    #+#             */
/*   Updated: 2023/04/19 17:46:44 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a_rra(t_node **head, int a_cost)
{
	t_node	*old_head;
	t_node	*new_last;

	(void)a_cost;
	old_head = *head;
	new_last = lst_second_to_last(*head);
	*head = lst_last(*head);
	new_last->next = NULL;
	(*head)->next = old_head;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b_rrb(t_node **head, int b_cost)
{
	t_node	*old_head;
	t_node	*new_last;

	(void)b_cost;
	old_head = *head;
	new_last = lst_second_to_last(*head);
	*head = lst_last(*head);
	new_last->next = NULL;
	(*head)->next = old_head;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_a_b_rrr(t_node **head_a, t_node **head_b,
		int a_cost, int b_cost)
{
	t_node	*old_head_a;
	t_node	*old_head_b;
	t_node	*new_last;

	(void)a_cost;
	(void)b_cost;
	old_head_a = *head_a;
	new_last = lst_second_to_last(*head_a);
	*head_a = lst_last(*head_a);
	new_last->next = NULL;
	(*head_a)->next = old_head_a;
	old_head_b = *head_b;
	new_last = lst_second_to_last(*head_b);
	*head_b = lst_last(*head_b);
	new_last->next = NULL;
	(*head_b)->next = old_head_b;
	write(1, "rrr\n", 4);
}

void	push_b_pb(t_node **head_a, t_node **head_b)
{
	t_node	*node_a;
	t_node	*node_b;

	if (head_a)
	{
		node_a = (*head_a)->next;
		node_b = *head_b;
		*head_b = *head_a;
		(*head_b)->next = node_b;
		*head_a = node_a;
		write(1, "pb\n", 3);
	}
}

void	push_a_pa(t_node **head_a, t_node **head_b)
{
	t_node	*node_a;
	t_node	*node_b;

	if (head_a)
	{
		node_a = *head_a;
		node_b = (*head_b)->next;
		*head_a = *head_b;
		(*head_a)->next = node_a;
		*head_b = node_b;
		write(1, "pa\n", 3);
	}
}
