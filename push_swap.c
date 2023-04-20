/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:19:20 by agarijo-          #+#    #+#             */
/*   Updated: 2023/04/19 17:49:49 by agarijo-         ###   ########.fr       */
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

void	push_swap(int *array, int argc)
{
	t_node	*head;

	head = NULL;
	head = fill_list_with_array(array, argc);
	if (!check_if_in_order(head))
	{
		if (argc == 2)
			head = only_two_numbers(head);
		if (argc == 3)
			head = only_three_numbers(head);
		if (argc == 4)
			head = only_four_numbers(head);
		if (argc > 4)
			head = more_numbers(head);
	}
	lst_clear(&head);
	free(array);
}
