/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:12:57 by agarijo-          #+#    #+#             */
/*   Updated: 2023/04/19 17:43:52 by agarijo-         ###   ########.fr       */
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
		lst_add_pos_to_node(node, (head->next)->position);
		lst_add_rank_to_node(node, (head->next)->rank);
		lst_add_next_to_node(node, head);
		lst_add_next_to_node(head, (head->next)->next);
		lst_free_node(temp);
		return (write(1, "sa\n", 3), node);
	}
	return (NULL);
}

void	rotate_a_ra(t_node **head, int a_cost)
{
	t_node	*node;
	t_node	*new_head;

	(void)a_cost;
	node = lst_new_node();
	new_head = (*head)->next;
	lst_add_value_to_node(node, (*head)->value);
	lst_add_pos_to_node(node, (*head)->position);
	lst_add_rank_to_node(node, (*head)->rank);
	lst_add_next_to_node(node, NULL);
	lst_add_back(&new_head, node);
	lst_free_node(*head);
	*head = new_head;
	write(1, "ra\n", 3);
}

void	rotate_b_rb(t_node **head, int b_cost)
{
	t_node	*node;
	t_node	*new_head;

	(void)b_cost;
	node = lst_new_node();
	new_head = (*head)->next;
	lst_add_value_to_node(node, (*head)->value);
	lst_add_pos_to_node(node, (*head)->position);
	lst_add_rank_to_node(node, (*head)->rank);
	lst_add_next_to_node(node, NULL);
	lst_add_back(&new_head, node);
	lst_free_node(*head);
	*head = new_head;
	write(1, "rb\n", 3);
}

void	rotate_a_b_rr(t_node **head_a, t_node **head_b, int a_cost, int b_cost)
{
	t_node	*node;
	t_node	*new_head;

	(void)a_cost;
	(void)b_cost;
	node = lst_new_node();
	new_head = (*head_a)->next;
	lst_add_value_to_node(node, (*head_a)->value);
	lst_add_pos_to_node(node, (*head_a)->position);
	lst_add_rank_to_node(node, (*head_a)->rank);
	lst_add_next_to_node(node, NULL);
	lst_add_back(&new_head, node);
	lst_free_node(*head_a);
	*head_a = new_head;
	node = lst_new_node();
	new_head = (*head_b)->next;
	lst_add_value_to_node(node, (*head_b)->value);
	lst_add_pos_to_node(node, (*head_b)->position);
	lst_add_rank_to_node(node, (*head_b)->rank);
	lst_add_next_to_node(node, NULL);
	lst_add_back(&new_head, node);
	lst_free_node(*head_b);
	*head_b = new_head;
	write(1, "rr\n", 3);
}
