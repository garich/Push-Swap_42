/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:48:00 by agarijo-          #+#    #+#             */
/*   Updated: 2023/04/05 20:05:20 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		head = rotate_a_ra(head);
		head = rotate_a_ra(head);
	}
	else if (smallest_place == 3)
	{
		head = reverse_rotate_a_rra(head);
	}
	push_b_pb(&head, &head_b);
	head = only_three_numbers(head);
	push_a_pa(&head, &head_b);
	lst_clear(&head_b);
	if (head)
		return (head);
	return (write(2, "Error\n", 6), NULL);
}

t_node	*more_numbers(t_node *head)
{
	int		head_size;
	int		*chunks;
	t_node	*head_b;

	head_b = NULL;
	head_size = lst_size(head);
	printf("Head Size: %d\n", head_size);
	chunks = get_chunks(head_size - 1);
	while (head && !(check_if_in_order(head)))
	{
		if (head_size == 3)
			head = only_three_numbers(head);
		else
			separate_chunks(&head, &head_b, &chunks, &head_size);
	}
	write(1, "A:\n", 3);
	lst_print(head);
	write(1, "B:\n", 3);
	lst_print(head_b);
	free(chunks);
	lst_clear(&head_b);
	if (head)
		return (head);
	return (write(2, "Error\n", 6), NULL);
}

void	separate_chunks(t_node **head_a,
	t_node **head_b, int **chunks, int *head_size)
{
	while (*head_size > chunks[0][0])
	{
		if ((*head_a)->rank <= chunks[0][0])
		{
			push_b_pb(head_a, head_b);
			*head_b = rotate_b_rb(*head_b);
			*head_size -= 1;
		}
		else if ((*head_a)->rank <= chunks[0][1])
		{
			push_b_pb(head_a, head_b);
			*head_size -= 1;
		}
		else
		{
			*head_a = rotate_a_ra(*head_a);
		}
	}
}
