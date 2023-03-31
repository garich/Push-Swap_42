/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:19:20 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/30 20:24:54 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_in_order(t_node *head)
{
	t_node	*node;

	node = head;
	while (node && node->next && (node->value < node->next->value))
		node = node->next;
	if (node && node->next && (node->value > node->next->value))
		return (0);
	return (1);
}

t_node	*only_two_numbers(t_node *head)
{
	t_node	*node;

	node = NULL;
	node = swap_a_sa(head);
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
			node = rotate_a_ra(node);
		else if ((node->value < node->next->value)
			&& (node->next->value > node->next->next->value)
			&& node->next->next->value < node->value)
			node = reverse_rotate_a_rra(node);
		else
			node = swap_a_sa(node);
	}
	if (node)
		return (node);
	return (write(2, "Error\n", 6), NULL);
}

void	push_swap(int *array, int argc)
{
	t_node	*head;

	head = NULL;
	if (argc == 1)
		write(1, "OK\n", 3);
	else
	{
		head = fill_list_with_array(array, argc);
		lst_print(head);
		if (check_if_in_order(head))
			write(1, "ORDEN\n", 6);
		else
		{
			if (argc == 2)
				head = only_two_numbers(head);
			if (argc == 3)
				head = only_three_numbers(head);
		}
		lst_print(head);
		lst_clear(&head);
	}
	free(array);
}
