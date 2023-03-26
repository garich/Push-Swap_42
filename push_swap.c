/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:19:20 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/27 00:13:19 by agarijo-         ###   ########.fr       */
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
		return (node);
	}
	return (NULL);
}

t_node	*only_two_numbers(t_node *head)
{
	t_node	*node;

	node = NULL;
	if (head->value < head->next->value)
		return (write(1, "OK\n", 3), head);
	else
	{
		node = swap_a_sa(head);
		if (node)
			return (write(1, "sa\n", 3), node);
		return (write(2, "Error\n", 6), NULL);
	}
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
		if (argc == 2)
			head = only_two_numbers(head);
		lst_print(head);
		lst_clear(&head);
	}
	free(array);
}
